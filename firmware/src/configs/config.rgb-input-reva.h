#ifndef _CONFIG_H_8CH_MOSFET_REVA
#define _CONFIG_H_8CH_MOSFET_REVA

#define HARDWARE_VERSION "RGB-INPUT-REV-A"

#define YB_HAS_DIGITAL_INPUT_CHANNELS
#define YB_INPUT_CHANNEL_COUNT 16
#define YB_INPUT_CHANNEL_PINS { 13, 12, 14, 27, 26, 25, 33, 32, 35, 34, 39, 36, 2, 4, 16, 15 }

#define YB_HAS_ADC
#define YB_ADC_DRIVER_MCP3208

#define YB_HAS_RGB_OUTPUT
#define YB_RGB_CHANNEL_COUNT 16
#define YB_RGB_DRIVER_TLC5947

#endif // _CONFIG_H_8CH_MOSFET_REVB