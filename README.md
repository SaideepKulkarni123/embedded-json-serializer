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

