
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <DHTesp.h>
#include "code.h"

const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";

#define DHTPIN D2

DHTesp dht;
ESP8266WebServer server(80);

void handleRoot() {
    server.send_P(200, "text/html", webpage);
}

void handleData() {
    float temperature = dht.getTemperature();
    float humidity = dht.getHumidity();

    String json = "{\"temperature\":" + String(temperature, 1) +
                  ",\"humidity\":" + String(humidity, 1) + "}";

    server.send(200, "application/json", json);
}

void setup() {
    Serial.begin(115200);

    dht.setup(DHTPIN, DHTesp::DHT11);

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
    }

    Serial.println(WiFi.localIP());

    server.on("/", handleRoot);
    server.on("/data", handleData);

    server.begin();
}

void loop() {
    server.handleClient();
}
