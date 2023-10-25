/*
  Yarrboard
  
  Author: Zach Hoeken <hoeken@gmail.com>
  Website: https://github.com/hoeken/yarrboard
  License: GPLv3
*/

#ifndef YARR_SERVER_H
#define YARR_SERVER_H

#include <Arduino.h>
#include <ArduinoJson.h>
#include <CircularBuffer.h>

#include <AsyncJson.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>

#include "protocol.h"
#include "prefs.h"
#include "wifi.h"
#include "ota.h"
#include "adchelper.h"

#include "index.html.gz.h"

#ifdef YB_HAS_OUTPUT_CHANNELS
  #include "output_channel.h"
#endif

#ifdef YB_HAS_FANS
  #include "fans.h"
#endif

typedef struct {
  unsigned int client_id;
  char buffer[YB_RECEIVE_BUFFER_LENGTH];
} WebsocketRequest;

void server_setup();
void server_loop();

void onEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type, void *arg, uint8_t *data, size_t len);
void handleWebSocketMessage(void *arg, uint8_t *data, size_t len, AsyncWebSocketClient *client);
void handleWebsocketMessageLoop(WebsocketRequest* request);
void handleWebServerRequest(JsonVariant input, AsyncWebServerRequest *request);
void sendToAllWebsockets(const char * jsonString);

bool isWebsocketClientLoggedIn(JsonVariantConst input, uint32_t client_id);
bool isApiClientLoggedIn(JsonVariantConst input);
bool isSerialClientLoggedIn(JsonVariantConst input);

bool logClientIn(uint32_t client_id);
int getWebsocketRequestSlot();
void closeClientConnection(AsyncWebSocketClient *client);


int getFreeSlots();

#endif /* !YARR_SERVER_H */