#include "Effects/FactoryFx.h"
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

void setup();
void loop();
void ServerSetup();
void ReadRequest(WiFiClient client);
void handleRoot();
void animation();