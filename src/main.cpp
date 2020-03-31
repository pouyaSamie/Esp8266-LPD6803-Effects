#include "main.h"

using namespace LPD6803;
using namespace Effects;

const char* ssid = "";
const char* password = "";
unsigned long lastUpdate = 0 ;

uint8_t NUM_LEDS  = 40;
unsigned int patternInterval = 30;

LEDStrip strip = LEDStrip(NUM_LEDS, D7, D6);
// ClockWise clockwiseEffect = ClockWise(strip);
//RainBowEffect rainbow = RainBowEffect(strip);
Fx* fx;
ESP8266WebServer server(80);

void setup()
{
  Serial.begin(115200);
  Serial.println();
  ServerSetup();
  strip.begin();
  //fx = FactoryFx().GetFx(1,strip);
  
}

void loop() {
  
  if (strip.outputReady ())
  {
    server.handleClient();
  }
  if(fx!=nullptr)
    if(millis() - lastUpdate > patternInterval) {
         fx->UpdatePattern();
         lastUpdate = millis();
    }
      

  delay(50);
}

void ServerSetup(){

  // Connect to Wi-Fi network with SSID and password
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.on("/animation", animation);
  server.begin();

}

void handleRoot(){
 server.send(200, "text/plain", "hello from esp8266!");

}


void animation(){
int mode = -1;
if (server.hasArg ("mode"))
   mode =  server.arg ("mode").toInt ();

if (server.hasArg ("wait"))
   patternInterval =  server.arg ("wait").toInt ();

 String s = "animation:" + String(mode);
 s+="wait:" + String(patternInterval);
 server.send(200, "text/plain", s);
 fx = FactoryFx().GetFx(mode,strip,patternInterval);
//  fx->Start(30);

}


