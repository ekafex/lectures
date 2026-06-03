#include <Arduino.h>
#include "AppConfig.h"
#include "GnssReader.h"
#include "Lab11Analyzer.h"

HardwareSerial gnssSerial(GNSS_UART_NUM);

GnssReader gnssReader(gnssSerial);
Lab11Analyzer analyzer;

static void printStartupMessage()
{
    Serial.println();
    Serial.println("# ==================================================");
    Serial.println("# LAB11 GNSS logger");
    Serial.println("# ESP32-S3-DevKitC-1 + u-blox NEO-M9N");
    Serial.println("# SparkFun u-blox GNSS v3");
    Serial.println("# ==================================================");
    Serial.println("# Lidhja:");
    Serial.println("#   NEO-M9N TX -> ESP32-S3 GPIO18 RX");
    Serial.println("#   NEO-M9N RX -> ESP32-S3 GPIO17 TX");
    Serial.println("#   NEO-M9N GND -> ESP32-S3 GND");
    Serial.println("#   NEO-M9N VCC -> 3.3 V");
    Serial.println("#");
    Serial.println("# Rekomandim per perdorimin:");
    Serial.println("#   1. Vendose modulin e GNSS jashte ne vend te hapur.");
    Serial.println("#   2. Prit deri sa te kycet me satelitet.");
    Serial.println("#   3. Ruaj output qe del nga terminali CSV.");
    Serial.println("#   4. Per pandas, perdor: pd.read_csv(file, comment='#')");
    Serial.println("# ==================================================");
    Serial.println();
}

static void printInvalidSampleStatus(const GnssSample &s)
{
    Serial.print("# Nuk eshte kycur me satelitet akoma per LAB11: ");
    Serial.print("fix_ok=");
    Serial.print(s.fix_ok ? 1 : 0);

    Serial.print(", fix_type=");
    Serial.print(s.fix_type);

    Serial.print(", satellites_used=");
    Serial.print(s.satellites_used);

    Serial.print(", lat=");
    Serial.print(s.lat_deg, 9);

    Serial.print(", lon=");
    Serial.print(s.lon_deg, 9);

    Serial.print(", h_acc_m=");
    Serial.print(s.h_acc_m, 3);

    Serial.print(", pdop=");
    Serial.println(s.pdop, 2);
}

void setup()
{
    Serial.begin(USB_SERIAL_BAUD);
    delay(2000);

    printStartupMessage();

    analyzer.reset();

    if (!gnssReader.begin(Serial))
    {
        Serial.println("# ERROR: moduli GNSS nuk u detektua.");
        Serial.println("# Check:");
        Serial.println("#   - TX/RX jan ciftuar ne rregull.");
        Serial.println("#   - GNSS ka 3.3 V dhe GND.");
        Serial.println("#   - Antena e modulit ka pamje te lire te qiellit.");
        Serial.println("#   - Baud rate eshte 115200.");
        Serial.println("# Programi ndaloj.");

        while (true)
        {
            delay(1000);
        }
    }

    analyzer.printCsvHeader(Serial);

    Serial.println("# Po presim per nje kycje GNSS ...");
}

void loop()
{
    GnssSample sample;

    if (!gnssReader.readSample(sample))
    {
        Serial.println("# Nuk ka te dhena PVT te reja.");
        delay(200);
        return;
    }

    Lab11Row row;
    const bool valid = analyzer.process(sample, row);

    if (valid)
    {
        if (analyzer.validSamples() == 1)
        {
            Serial.print("# Referenca e inicializuar: lat=");
            Serial.print(analyzer.referenceLatitudeDeg(), 9);
            Serial.print(", lon=");
            Serial.println(analyzer.referenceLongitudeDeg(), 9);
        }

        analyzer.printCsvRow(Serial, row);

        if ((analyzer.validSamples() % SUMMARY_EVERY_VALID_SAMPLES) == 0)
        {
            analyzer.printSummary(Serial);
        }
    }
    else
    {
        printInvalidSampleStatus(sample);
    }
}
