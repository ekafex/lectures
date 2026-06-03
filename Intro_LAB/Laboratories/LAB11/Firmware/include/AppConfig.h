#pragma once

#include <Arduino.h>

// ============================================================
// Board / UART configuration
// ============================================================

// Your confirmed wiring:
// NEO-M9N TX -> ESP32-S3 GPIO18 RX
// NEO-M9N RX -> ESP32-S3 GPIO17 TX
static constexpr int GNSS_RX_PIN = 18;
static constexpr int GNSS_TX_PIN = 17;

// Use ESP32 UART1 for GNSS.
static constexpr int GNSS_UART_NUM = 1;

// USB serial monitor.
static constexpr uint32_t USB_SERIAL_BAUD = 115200;

// u-blox F9/M9/M10 modules are commonly 38400 by default.
// We try several values to be robust.
static constexpr uint32_t GNSS_BAUD_CANDIDATES[] = {
    38400,
    9600,
    115200
};

static constexpr size_t GNSS_BAUD_CANDIDATE_COUNT =
    sizeof(GNSS_BAUD_CANDIDATES) / sizeof(GNSS_BAUD_CANDIDATES[0]);

// LAB11 wants approximately 1 sample per second.
static constexpr uint8_t GNSS_NAV_RATE_HZ = 1;

// PVT wait time. At 1 Hz, 1200 ms is safe.
static constexpr uint16_t GNSS_PVT_MAX_WAIT_MS = 1200;

// DOP query wait time. Short, because DOP is auxiliary.
static constexpr uint16_t GNSS_DOP_MAX_WAIT_MS = 250;

// Maximum number of radial samples stored for r68/r95.
// 1800 samples = 30 minutes at 1 Hz.
static constexpr size_t MAX_RADIAL_SAMPLES = 1800;

// Reject absurd jumps from cumulative walking distance.
// Useful in Experiment C if GNSS produces a large outlier.
static constexpr double MAX_REASONABLE_STEP_M = 50.0;

// Earth mean radius used for local coordinate conversion.
static constexpr double EARTH_RADIUS_M = 6371000.0;

// Print running summary every N valid samples.
// At 1 Hz, 60 means about once per minute.
static constexpr uint32_t SUMMARY_EVERY_VALID_SAMPLES = 60;
