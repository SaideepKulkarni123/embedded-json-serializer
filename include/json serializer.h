#ifndef JSON_SERIALIZER_H
#define JSON_SERIALIZER_H

#include <stddef.h>

/* Limits – adjust if needed */
#define MAX_DEVICES     5
#define MAX_DATAPOINTS  5

/* Data structures */

typedef struct {
    char timestamp[20];          // "YYYY-MM-DD HH:MM"
    char meter_datetime[20];
    float total_m3;
    char status[8];              // "OK"
} MeterDataPoint;

typedef struct {
    char media[16];
    char meter[16];
    char deviceId[32];
    char unit[8];
    int data_count;
    MeterDataPoint data[MAX_DATAPOINTS];
} DeviceReading;

typedef struct {
    int device_count;
    DeviceReading readings[MAX_DEVICES];
} MeasurementBlock;

typedef struct {
    char gatewayId[32];
    char date[11];               // YYYY-MM-DD
    char deviceType[16];
    int interval_minutes;
    int total_readings;
    MeasurementBlock values;
} GatewayPayload;

/* API */
int serialize_to_json(
    const GatewayPayload *input,
    char *output_buffer,
    size_t buffer_size
);

#endif /* JSON_SERIALIZER_H */
