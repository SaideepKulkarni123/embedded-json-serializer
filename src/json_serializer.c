#include "json_serializer.h"
#include <stdio.h>
#include <string.h>

#define CHECK_SPACE() if (offset >= buffer_size) return -2

int serialize_to_json(
    const GatewayPayload *input,
    char *output_buffer,
    size_t buffer_size
) {
    if (!input || !output_buffer || buffer_size == 0) {
        return -1;
    }

    size_t offset = 0;

    offset += snprintf(output_buffer + offset, buffer_size - offset, "[{");
    CHECK_SPACE();

    offset += snprintf(output_buffer + offset, buffer_size - offset,
        "\"gatewayId\":\"%s\","
        "\"date\":\"%s\","
        "\"deviceType\":\"%s\","
        "\"interval_minutes\":%d,"
        "\"total_readings\":%d,",
        input->gatewayId,
        input->date,
        input->deviceType,
        input->interval_minutes,
        input->total_readings
    );
    CHECK_SPACE();

    offset += snprintf(output_buffer + offset, buffer_size - offset,
        "\"values\":{"
        "\"device_count\":%d,"
        "\"readings\":[",
        input->values.device_count
    );
    CHECK_SPACE();

    for (int i = 0; i < input->values.device_count; i++) {
        DeviceReading *dev = &input->values.readings[i];

        offset += snprintf(output_buffer + offset, buffer_size - offset,
            "{"
            "\"media\":\"%s\","
            "\"meter\":\"%s\","
            "\"deviceId\":\"%s\","
            "\"unit\":\"%s\","
            "\"data\":[",
            dev->media,
            dev->meter,
            dev->deviceId,
            dev->unit
        );
        CHECK_SPACE();

        for (int j = 0; j < dev->data_count; j++) {
            MeterDataPoint *dp = &dev->data[j];

            offset += snprintf(output_buffer + offset, buffer_size - offset,
                "{"
                "\"timestamp\":\"%s\","
                "\"meter_datetime\":\"%s\","
                "\"total_m3\":%.3f,"
                "\"status\":\"%s\""
                "}",
                dp->timestamp,
                dp->meter_datetime,
                dp->total_m3,
                dp->status
            );
            CHECK_SPACE();

            if (j < dev->data_count - 1) {
                offset += snprintf(output_buffer + offset, buffer_size - offset, ",");
                CHECK_SPACE();
            }
        }

        offset += snprintf(output_buffer + offset, buffer_size - offset, "]}");
        CHECK_SPACE();

        if (i < input->values.device_count - 1) {
            offset += snprintf(output_buffer + offset, buffer_size - offset, ",");
            CHECK_SPACE();
        }
    }

    offset += snprintf(output_buffer + offset, buffer_size - offset,
        "]}}]"
    );
    CHECK_SPACE();

    return 0;
}
