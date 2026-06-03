#include "GnssReader.h"

GnssReader::GnssReader(HardwareSerial &serialPort)
    : serial_(serialPort)
{
}

bool GnssReader::begin(Stream &debugOut)
{
    for (size_t i = 0; i < GNSS_BAUD_CANDIDATE_COUNT; i++)
    {
        const uint32_t baud = GNSS_BAUD_CANDIDATES[i];

        if (tryBeginAtBaud(baud, debugOut))
        {
            configure(debugOut);
            return true;
        }
    }

    return false;
}

bool GnssReader::tryBeginAtBaud(uint32_t baud, Stream &debugOut)
{
    debugOut.print("# Trying GNSS UART baud ");
    debugOut.println(baud);

    serial_.end();
    delay(200);

    serial_.begin(baud, SERIAL_8N1, GNSS_RX_PIN, GNSS_TX_PIN);
    delay(500);

    // We are using the module's main UART, i.e. u-blox UART1.
    // Do not call connectedToUART2() unless physically wired to module UART2.
    gnss_.connectedToUART2(false);

    if (gnss_.begin(serial_, GNSS_PVT_MAX_WAIT_MS))
    {
        debugOut.print("# GNSS detected at baud ");
        debugOut.println(baud);
        return true;
    }

    // Try to enable UBX output on UART1. This can help if the port output is not already UBX.
    debugOut.println("# Initial begin failed. Trying to enable UBX output on UART1...");

    gnss_.setUART1Output(COM_TYPE_UBX);
    delay(500);

    if (gnss_.begin(serial_, GNSS_PVT_MAX_WAIT_MS))
    {
        debugOut.print("# GNSS detected after UART1 UBX enable at baud ");
        debugOut.println(baud);
        return true;
    }

    debugOut.println("# GNSS not detected at this baud.");
    return false;
}

void GnssReader::configure(Stream &debugOut)
{
    debugOut.println("# Configuring GNSS...");

    gnss_.connectedToUART2(false);

    // UART1 should output UBX. This disables NMEA output on UART1.
    if (gnss_.setUART1Output(COM_TYPE_UBX))
    {
        debugOut.println("# UART1 output set to UBX.");
    }
    else
    {
        debugOut.println("# WARNING: Could not set UART1 output to UBX.");
    }

    if (gnss_.setNavigationFrequency(GNSS_NAV_RATE_HZ))
    {
        debugOut.print("# Navigation frequency set to ");
        debugOut.print(GNSS_NAV_RATE_HZ);
        debugOut.println(" Hz.");
    }
    else
    {
        debugOut.println("# WARNING: Could not set navigation frequency.");
    }

    // Auto PVT makes repeated reads cleaner.
    if (gnss_.setAutoPVT(true))
    {
        debugOut.println("# Auto PVT enabled.");
    }
    else
    {
        debugOut.println("# WARNING: Could not enable Auto PVT.");
    }

    // DOP is useful but not essential.
    if (gnss_.setAutoDOP(true))
    {
        debugOut.println("# Auto DOP enabled.");
    }
    else
    {
        debugOut.println("# WARNING: Could not enable Auto DOP.");
    }

    debugOut.println("# GNSS configuration complete.");
}

bool GnssReader::readSample(GnssSample &sample)
{
    // getPVT returns true when new PVT data is available.
    if (!gnss_.getPVT(GNSS_PVT_MAX_WAIT_MS))
    {
        return false;
    }

    sample = GnssSample{};

    sample.t_ms = millis();

    sample.year = gnss_.getYear(0);
    sample.month = gnss_.getMonth(0);
    sample.day = gnss_.getDay(0);
    sample.hour = gnss_.getHour(0);
    sample.minute = gnss_.getMinute(0);
    sample.second = gnss_.getSecond(0);
    sample.millisecond = gnss_.getMillisecond(0);

    sample.date_valid = gnss_.getDateValid(0);
    sample.time_valid = gnss_.getTimeValid(0);

    sample.fix_type = gnss_.getFixType(0);
    sample.fix_ok = gnss_.getGnssFixOk(0);
    sample.satellites_used = gnss_.getSIV(0);

    // Library units:
    // latitude / longitude: degrees * 1e-7
    // altitude: mm
    // horizontal / vertical accuracy: mm
    // speed: mm/s
    // heading: degrees * 1e-5
    sample.lat_deg = static_cast<double>(gnss_.getLatitude(0)) / 1e7;
    sample.lon_deg = static_cast<double>(gnss_.getLongitude(0)) / 1e7;

    sample.alt_ellipsoid_m = static_cast<double>(gnss_.getAltitude(0)) / 1000.0;
    sample.alt_msl_m = static_cast<double>(gnss_.getAltitudeMSL(0)) / 1000.0;

    sample.h_acc_m = static_cast<double>(gnss_.getHorizontalAccEst(0)) / 1000.0;
    sample.v_acc_m = static_cast<double>(gnss_.getVerticalAccEst(0)) / 1000.0;

    sample.ground_speed_mps = static_cast<double>(gnss_.getGroundSpeed(0)) / 1000.0;
    sample.heading_deg = static_cast<double>(gnss_.getHeading(0)) / 1e5;

    sample.speed_acc_mps = static_cast<double>(gnss_.getSpeedAccEst(0)) / 1000.0;
    sample.heading_acc_deg = static_cast<double>(gnss_.getHeadingAccEst(0)) / 1e5;

    // PDOP is included in NAV-PVT.
    sample.pdop = static_cast<double>(gnss_.getPDOP(0)) / 100.0;

    // HDOP is from NAV-DOP. If unavailable, leave as NAN.
    if (gnss_.getDOP(GNSS_DOP_MAX_WAIT_MS))
    {
        sample.hdop = static_cast<double>(gnss_.getHorizontalDOP(0)) / 100.0;
    }
    else
    {
        sample.hdop = NAN;
    }

    sample.valid_for_lab = sampleIsUsableForLab(sample);

    return true;
}

bool GnssReader::sampleIsUsableForLab(const GnssSample &s)
{
    if (!s.fix_ok) return false;
    if (s.fix_type < 2) return false;
    if (s.satellites_used < 4) return false;

    if (isnan(s.lat_deg) || isnan(s.lon_deg)) return false;
    if (isinf(s.lat_deg) || isinf(s.lon_deg)) return false;

    // Reject the common invalid zero coordinate.
    if (fabs(s.lat_deg) < 1e-9 && fabs(s.lon_deg) < 1e-9) return false;

    return true;
}
