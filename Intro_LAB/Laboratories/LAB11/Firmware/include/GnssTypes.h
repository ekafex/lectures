#pragma once

#include <Arduino.h>

struct GnssSample
{
    uint32_t t_ms = 0;

    uint16_t year = 0;
    uint8_t month = 0;
    uint8_t day = 0;
    uint8_t hour = 0;
    uint8_t minute = 0;
    uint8_t second = 0;
    uint16_t millisecond = 0;

    bool date_valid = false;
    bool time_valid = false;
    bool fix_ok = false;

    uint8_t fix_type = 0;
    uint8_t satellites_used = 0;

    double lat_deg = NAN;
    double lon_deg = NAN;

    double alt_ellipsoid_m = NAN;
    double alt_msl_m = NAN;

    double h_acc_m = NAN;
    double v_acc_m = NAN;

    double pdop = NAN;
    double hdop = NAN;

    double ground_speed_mps = NAN;
    double heading_deg = NAN;

    double speed_acc_mps = NAN;
    double heading_acc_deg = NAN;

    bool valid_for_lab = false;
};

struct Lab11Row
{
    GnssSample gnss;

    double x_m = NAN;
    double y_m = NAN;
    double r_m = NAN;

    double dx_step_m = NAN;
    double dy_step_m = NAN;
    double step_distance_m = NAN;
    double step_bearing_deg = NAN;

    double cumulative_distance_m = NAN;

    double x_mean_m = NAN;
    double y_mean_m = NAN;
    double r_mean_m = NAN;

    double x_std_m = NAN;
    double y_std_m = NAN;
    double r_std_m = NAN;

    double r_max_m = NAN;
    double r68_m = NAN;
    double r95_m = NAN;
};
