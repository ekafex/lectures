#pragma once

#include <Arduino.h>
#include "GnssTypes.h"
#include "WelfordStats.h"
#include "AppConfig.h"

class Lab11Analyzer
{
public:
    void reset();

    bool process(const GnssSample &sample, Lab11Row &row);

    uint32_t totalSamples() const;
    uint32_t validSamples() const;

    double referenceLatitudeDeg() const;
    double referenceLongitudeDeg() const;
    bool referenceReady() const;

    void printCsvHeader(Stream &out) const;
    void printCsvRow(Stream &out, const Lab11Row &row) const;
    void printSummary(Stream &out) const;

private:
    bool hasReference_ = false;
    double lat0_rad_ = 0.0;
    double lon0_rad_ = 0.0;

    bool hasPrevious_ = false;
    double previous_x_m_ = 0.0;
    double previous_y_m_ = 0.0;

    uint32_t totalSamples_ = 0;
    uint32_t validSamples_ = 0;

    double cumulativeDistance_m_ = 0.0;
    double maxRadial_m_ = 0.0;
    double maxStep_m_ = 0.0;

    WelfordStats xStats_;
    WelfordStats yStats_;
    WelfordStats rStats_;
    WelfordStats altitudeStats_;
    WelfordStats hAccStats_;
    WelfordStats speedStats_;

    double radialSamples_[MAX_RADIAL_SAMPLES];
    size_t radialCount_ = 0;

    static double degToRad(double deg);
    static double radToDeg(double rad);
    static double normalizeAngle360(double deg);

    static void localXY(
        double lat_rad,
        double lon_rad,
        double ref_lat_rad,
        double ref_lon_rad,
        double &x_m,
        double &y_m
    );

    static double bearingFromDxDy(double dx_m, double dy_m);

    double radialPercentile(double p) const;

    static void printIsoTime(Stream &out, const GnssSample &s);
    static const char *fixTypeName(uint8_t fixType);
};
