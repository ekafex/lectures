#pragma once

#include <Arduino.h>
#include <SparkFun_u-blox_GNSS_v3.h>
#include "GnssTypes.h"
#include "AppConfig.h"

class GnssReader
{
public:
    GnssReader(HardwareSerial &serialPort);

    bool begin(Stream &debugOut = Serial);
    bool readSample(GnssSample &sample);

private:
    HardwareSerial &serial_;
    SFE_UBLOX_GNSS_SERIAL gnss_;

    bool tryBeginAtBaud(uint32_t baud, Stream &debugOut);
    void configure(Stream &debugOut);

    static bool sampleIsUsableForLab(const GnssSample &s);
};
