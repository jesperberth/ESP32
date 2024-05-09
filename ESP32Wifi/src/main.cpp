#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

#define WIFI_SSID "Berths iPhone"
#define WIFI_PASSWORD "4k80fxw2e4zc6"

void setup() {
  Serial.begin(921600);
  pinMode(LED_BUILTIN, OUTPUT);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  Serial.println("Starting wifi");
}

bool isConnected = false;

void loop() {
  if (WiFi.status() == WL_CONNECTED && !isConnected) {
    Serial.println("Connected");
    digitalWrite(LED_BUILTIN, HIGH);
    isConnected = true;
  }

  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("Not Connected");
    digitalWrite(LED_BUILTIN, HIGH);
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
    delay(1000);
    isConnected = false;
  }

  if (isConnected){
    HTTPClient http;

    http.begin("https://api.chucknorris.io/jokes/random");
    int httpCode = http.GET();

    if (httpCode > 0){
      String payload = http.getString();
      Serial.println(httpCode);

      char json[1000];
      payload.toCharArray(json, 1000);
      StaticJsonDocument<1000> doc;
      deserializeJson(doc, json);

      const char* joke = doc["value"];

      Serial.println(joke);
    }
    else {
      Serial.println("Error on HTTP request");
    }
    http.end();
    delay(10000);
  }
}
