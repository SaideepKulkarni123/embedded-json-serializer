# Embedded JSON Serialization Library

## Overview
This project implements an embedded-friendly C library that serializes structured
smart meter data into a predefined JSON format.  
The library is designed for firmware and gateway-level applications where
deterministic memory usage, robustness, and clean API design are critical.

The implementation focuses only on data modeling and JSON serialization.
Actual w-M-Bus communication, OMS, encryption, or real meter interaction
are intentionally out of scope.

---

## Platform and Programming Language

**Language:** C  
**Platform:** Platform-independent (tested on desktop, portable to STM32 / ESP32)

**Justification:**
- C is widely used in embedded firmware development.
- Allows precise control over memory and buffer usage.
- No dependency on external JSON libraries.
- Easy to integrate into STM32CubeIDE, ESP-IDF, or Arduino projects.

---

## Project Structure

mbedded-json-serializer/
├── include/
│ └── json_serializer.h // Public API and data structures
├── src/
│ └── json_serializer.c // JSON serialization implementation
├── examples/
│ └── main.c // Demo application
└── README.md


Description

Serializes the provided GatewayPayload structure into a JSON string.

Parameters

input – Pointer to populated input data structure

output_buffer – Caller-provided buffer for JSON output

buffer_size – Size of the output buffer

Return Values

0 → Success

-1 → Invalid input arguments

-2 → Output buffer too small

Example JSON Output
[
  {
    "gatewayId":"gateway_1234",
    "date":"1970-01-01",
    "deviceType":"stromleser",
    "interval_minutes":15,
    "total_readings":1,
    "values":{
      "device_count":1,
      "readings":[
        {
          "media":"water",
          "meter":"waterstarm",
          "deviceId":"stromleser_50898527",
          "unit":"m3",
          "data":[
            {
              "timestamp":"1970-01-01 00:00",
              "meter_datetime":"1970-01-01 00:00",
              "total_m3":107.752,
              "status":"OK"
            }
          ]
        }
      ]
    }
  }
]
