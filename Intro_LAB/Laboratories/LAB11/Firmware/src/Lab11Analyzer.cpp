#include "Lab11Analyzer.h"

void Lab11Analyzer::reset()
{
    hasReference_ = false;
    lat0_rad_ = 0.0;
    lon0_rad_ = 0.0;

    hasPrevious_ = false;
    previous_x_m_ = 0.0;
    previous_y_m_ = 0.0;

    totalSamples_ = 0;
    validSamples_ = 0;

    cumulativeDistance_m_ = 0.0;
    maxRadial_m_ = 0.0;
    maxStep_m_ = 0.0;

    xStats_.reset();
    yStats_.reset();
    rStats_.reset();
    altitudeStats_.reset();
    hAccStats_.reset();
    speedStats_.reset();

    radialCount_ = 0;
}

bool Lab11Analyzer::process(const GnssSample &sample, Lab11Row &row)
{
    totalSamples_++;

    row = Lab11Row{};
    row.gnss = sample;

    if (!sample.valid_for_lab)
    {
        return false;
    }

    validSamples_++;

    const double lat_rad = degToRad(sample.lat_deg);
    const double lon_rad = degToRad(sample.lon_deg);

    if (!hasReference_)
    {
        lat0_rad_ = lat_rad;
        lon0_rad_ = lon_rad;
        hasReference_ = true;
    }

    localXY(lat_rad, lon_rad, lat0_rad_, lon0_rad_, row.x_m, row.y_m);
    row.r_m = sqrt(row.x_m * row.x_m + row.y_m * row.y_m);

    if (hasPrevious_)
    {
        row.dx_step_m = row.x_m - previous_x_m_;
        row.dy_step_m = row.y_m - previous_y_m_;
        row.step_distance_m = sqrt(
            row.dx_step_m * row.dx_step_m +
            row.dy_step_m * row.dy_step_m
        );
        row.step_bearing_deg = bearingFromDxDy(row.dx_step_m, row.dy_step_m);

        if (row.step_distance_m <= MAX_REASONABLE_STEP_M)
        {
            cumulativeDistance_m_ += row.step_distance_m;
        }

        if (row.step_distance_m > maxStep_m_)
        {
            maxStep_m_ = row.step_distance_m;
        }
    }
    else
    {
        row.dx_step_m = 0.0;
        row.dy_step_m = 0.0;
        row.step_distance_m = 0.0;
        row.step_bearing_deg = NAN;
        hasPrevious_ = true;
    }

    previous_x_m_ = row.x_m;
    previous_y_m_ = row.y_m;

    if (row.r_m > maxRadial_m_)
    {
        maxRadial_m_ = row.r_m;
    }

    xStats_.push(row.x_m);
    yStats_.push(row.y_m);
    rStats_.push(row.r_m);
    altitudeStats_.push(sample.alt_msl_m);
    hAccStats_.push(sample.h_acc_m);
    speedStats_.push(sample.ground_speed_mps);

    if (radialCount_ < MAX_RADIAL_SAMPLES)
    {
        radialSamples_[radialCount_] = row.r_m;
        radialCount_++;
    }

    row.cumulative_distance_m = cumulativeDistance_m_;

    row.x_mean_m = xStats_.mean();
    row.y_mean_m = yStats_.mean();
    row.r_mean_m = rStats_.mean();

    row.x_std_m = xStats_.stddev();
    row.y_std_m = yStats_.stddev();
    row.r_std_m = rStats_.stddev();

    row.r_max_m = maxRadial_m_;
    row.r68_m = radialPercentile(68.0);
    row.r95_m = radialPercentile(95.0);

    return true;
}

uint32_t Lab11Analyzer::totalSamples() const
{
    return totalSamples_;
}

uint32_t Lab11Analyzer::validSamples() const
{
    return validSamples_;
}

double Lab11Analyzer::referenceLatitudeDeg() const
{
    return radToDeg(lat0_rad_);
}

double Lab11Analyzer::referenceLongitudeDeg() const
{
    return radToDeg(lon0_rad_);
}

bool Lab11Analyzer::referenceReady() const
{
    return hasReference_;
}

double Lab11Analyzer::degToRad(double deg)
{
    return deg * M_PI / 180.0;
}

double Lab11Analyzer::radToDeg(double rad)
{
    return rad * 180.0 / M_PI;
}

double Lab11Analyzer::normalizeAngle360(double deg)
{
    while (deg < 0.0) deg += 360.0;
    while (deg >= 360.0) deg -= 360.0;
    return deg;
}

void Lab11Analyzer::localXY(
    double lat_rad,
    double lon_rad,
    double ref_lat_rad,
    double ref_lon_rad,
    double &x_m,
    double &y_m
)
{
    x_m = EARTH_RADIUS_M * cos(ref_lat_rad) * (lon_rad - ref_lon_rad);
    y_m = EARTH_RADIUS_M * (lat_rad - ref_lat_rad);
}

double Lab11Analyzer::bearingFromDxDy(double dx_m, double dy_m)
{
    // x is East, y is North.
    // Bearing is clockwise from North.
    return normalizeAngle360(radToDeg(atan2(dx_m, dy_m)));
}

double Lab11Analyzer::radialPercentile(double p) const
{
    if (radialCount_ == 0) return NAN;

    static double temp[MAX_RADIAL_SAMPLES];

    for (size_t i = 0; i < radialCount_; i++)
    {
        temp[i] = radialSamples_[i];
    }

    // Insertion sort is fine for <=1800 points and occasional use.
    for (size_t i = 1; i < radialCount_; i++)
    {
        const double key = temp[i];
        size_t j = i;

        while (j > 0 && temp[j - 1] > key)
        {
            temp[j] = temp[j - 1];
            j--;
        }

        temp[j] = key;
    }

    const double index = (p / 100.0) * static_cast<double>(radialCount_ - 1);
    const size_t i0 = static_cast<size_t>(floor(index));
    const size_t i1 = static_cast<size_t>(ceil(index));

    if (i0 == i1) return temp[i0];

    const double frac = index - static_cast<double>(i0);
    return temp[i0] * (1.0 - frac) + temp[i1] * frac;
}

void Lab11Analyzer::printIsoTime(Stream &out, const GnssSample &s)
{
    char buffer[40];

    if (s.date_valid && s.time_valid)
    {
        snprintf(
            buffer,
            sizeof(buffer),
            "%04u-%02u-%02uT%02u:%02u:%02u.%03uZ",
            s.year,
            s.month,
            s.day,
            s.hour,
            s.minute,
            s.second,
            s.millisecond
        );
    }
    else
    {
        snprintf(buffer, sizeof(buffer), "INVALID_TIME");
    }

    out.print(buffer);
}

const char *Lab11Analyzer::fixTypeName(uint8_t fixType)
{
    switch (fixType)
    {
        case 0: return "NO_FIX";
        case 1: return "DEAD_RECKONING";
        case 2: return "2D";
        case 3: return "3D";
        case 4: return "GNSS_PLUS_DR";
        case 5: return "TIME_ONLY";
        default: return "UNKNOWN";
    }
}

void Lab11Analyzer::printCsvHeader(Stream &out) const
{
    out.println();
    out.println("# LAB11 GNSS logger");
    out.println("# Device: ESP32-S3-DevKitC-1 + u-blox NEO-M9N");
    out.println("# Library: SparkFun u-blox GNSS v3");
    out.println("# Save this serial output to a CSV file.");
    out.println("# pandas can ignore comment lines using: pd.read_csv(file, comment='#')");
    out.println("# x_m and y_m are local coordinates relative to the first valid fix.");
    out.println("# x_m is approximately East-West; y_m is approximately North-South.");
    out.println("# r_m is radial displacement from the first valid fix.");
    out.println();

    out.println(
        "sample_index,"
        "millis,"
        "utc,"
        "fix_ok,"
        "fix_type,"
        "fix_name,"
        "satellites_used,"
        "lat_deg,"
        "lon_deg,"
        "alt_msl_m,"
        "alt_ellipsoid_m,"
        "h_acc_m,"
        "v_acc_m,"
        "pdop,"
        "hdop,"
        "ground_speed_mps,"
        "heading_deg,"
        "speed_acc_mps,"
        "heading_acc_deg,"
        "x_m,"
        "y_m,"
        "r_m,"
        "dx_step_m,"
        "dy_step_m,"
        "step_distance_m,"
        "step_bearing_deg,"
        "cumulative_distance_m,"
        "x_mean_m,"
        "y_mean_m,"
        "r_mean_m,"
        "x_std_m,"
        "y_std_m,"
        "r_std_m,"
        "r_max_m,"
        "r68_m,"
        "r95_m"
    );
}

void Lab11Analyzer::printCsvRow(Stream &out, const Lab11Row &row) const
{
    out.print(validSamples_);
    out.print(",");

    out.print(row.gnss.t_ms);
    out.print(",");

    printIsoTime(out, row.gnss);
    out.print(",");

    out.print(row.gnss.fix_ok ? 1 : 0);
    out.print(",");

    out.print(row.gnss.fix_type);
    out.print(",");

    out.print(fixTypeName(row.gnss.fix_type));
    out.print(",");

    out.print(row.gnss.satellites_used);
    out.print(",");

    out.print(row.gnss.lat_deg, 9);
    out.print(",");

    out.print(row.gnss.lon_deg, 9);
    out.print(",");

    out.print(row.gnss.alt_msl_m, 3);
    out.print(",");

    out.print(row.gnss.alt_ellipsoid_m, 3);
    out.print(",");

    out.print(row.gnss.h_acc_m, 3);
    out.print(",");

    out.print(row.gnss.v_acc_m, 3);
    out.print(",");

    out.print(row.gnss.pdop, 2);
    out.print(",");

    out.print(row.gnss.hdop, 2);
    out.print(",");

    out.print(row.gnss.ground_speed_mps, 3);
    out.print(",");

    out.print(row.gnss.heading_deg, 2);
    out.print(",");

    out.print(row.gnss.speed_acc_mps, 3);
    out.print(",");

    out.print(row.gnss.heading_acc_deg, 2);
    out.print(",");

    out.print(row.x_m, 3);
    out.print(",");

    out.print(row.y_m, 3);
    out.print(",");

    out.print(row.r_m, 3);
    out.print(",");

    out.print(row.dx_step_m, 3);
    out.print(",");

    out.print(row.dy_step_m, 3);
    out.print(",");

    out.print(row.step_distance_m, 3);
    out.print(",");

    out.print(row.step_bearing_deg, 2);
    out.print(",");

    out.print(row.cumulative_distance_m, 3);
    out.print(",");

    out.print(row.x_mean_m, 3);
    out.print(",");

    out.print(row.y_mean_m, 3);
    out.print(",");

    out.print(row.r_mean_m, 3);
    out.print(",");

    out.print(row.x_std_m, 3);
    out.print(",");

    out.print(row.y_std_m, 3);
    out.print(",");

    out.print(row.r_std_m, 3);
    out.print(",");

    out.print(row.r_max_m, 3);
    out.print(",");

    out.print(row.r68_m, 3);
    out.print(",");

    out.println(row.r95_m, 3);
}

void Lab11Analyzer::printSummary(Stream &out) const
{
    out.println();
    out.println("# ---------- Running LAB11 summary ----------");

    out.print("# total_samples=");
    out.println(totalSamples_);

    out.print("# valid_samples=");
    out.println(validSamples_);

    if (hasReference_)
    {
        out.print("# reference_lat_deg=");
        out.println(referenceLatitudeDeg(), 9);

        out.print("# reference_lon_deg=");
        out.println(referenceLongitudeDeg(), 9);
    }

    out.print("# sigma_x_m=");
    out.println(xStats_.stddev(), 3);

    out.print("# sigma_y_m=");
    out.println(yStats_.stddev(), 3);

    out.print("# mean_radial_m=");
    out.println(rStats_.mean(), 3);

    out.print("# sigma_radial_m=");
    out.println(rStats_.stddev(), 3);

    out.print("# r68_m=");
    out.println(radialPercentile(68.0), 3);

    out.print("# r95_m=");
    out.println(radialPercentile(95.0), 3);

    out.print("# r_max_m=");
    out.println(maxRadial_m_, 3);

    out.print("# mean_alt_msl_m=");
    out.println(altitudeStats_.mean(), 3);

    out.print("# mean_h_acc_m=");
    out.println(hAccStats_.mean(), 3);

    out.print("# mean_ground_speed_mps=");
    out.println(speedStats_.mean(), 3);

    out.print("# cumulative_distance_m=");
    out.println(cumulativeDistance_m_, 3);

    out.print("# max_one_sample_step_m=");
    out.println(maxStep_m_, 3);

    out.println("# ------------------------------------------");
    out.println();
}
