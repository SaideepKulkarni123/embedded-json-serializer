#include <stdio.h>
#include <string.h>
#include "json_serializer.h"

int main(void) {
    GatewayPayload payload;
    memset(&payload, 0, sizeof(payload));

    strcpy(payload.gatewayId, "gateway_1234");
    strcpy(payload.date, "1970-01-01");
    strcpy(payload.deviceType, "stromleser");
    payload.interval_minutes = 15;
    payload.total_readings = 1;

    payload.values.device_count = 1;

    DeviceReading *dev = &payload.values.readings[0];
    strcpy(dev->media, "water");
    strcpy(dev->meter, "waterstarm");
    strcpy(dev->deviceId, "stromleser_50898527");
    strcpy(dev->unit, "m3");
    dev->data_count = 1;

    MeterDataPoint *dp = &dev->data[0];
    strcpy(dp->timestamp, "1970-01-01 00:00");
    strcpy(dp->meter_datetime, "1970-01-01 00:00");
    dp->total_m3 = 107.752f;
    strcpy(dp->status, "OK");

    char json_buffer[1024];

    int result = serialize_to_json(&payload, json_buffer, sizeof(json_buffer));
    if (result == 0) {
        printf("%s\n", json_buffer);
    } else {
        printf("Serialization error: %d\n", result);
    }

    return 0;
}
