#include <Arduino.h>
#include <WiFiManager.h>

#define WIFI_AP_NAME "ESP32-Deploy"
#define WIFI_AP_PASSWORD "ansible64!"

WiFiManager wifiManager;

void setup() {
    Serial.begin(921600);
    Serial.println("\n Starting");
    wifiManager.resetSettings();
    wifiManager.setMinimumSignalQuality(50);
    WiFiManagerParameter custom_text("<p>This is just a text paragraph</p>");
    wifiManager.addParameter(&custom_text);
    WiFiManagerParameter towerip("towerip", "Enter Tower IP", "ip", 50);
    WiFiManagerParameter toweroauth("toweroauth", "Enter Tower OAuth", "", 50);
    WiFiManagerParameter towerworkflow1("towerworkflow1", "Enter Tower Workflow 1", "", 50);
    WiFiManagerParameter towerworkflow2("towerworkflow2", "Enter Tower Workflow 2", "", 50);
    wifiManager.addParameter(&towerip);
    wifiManager.addParameter(&toweroauth);
    wifiManager.addParameter(&towerworkflow1);
    wifiManager.addParameter(&towerworkflow2);
    wifiManager.autoConnect(WIFI_AP_NAME);
    Serial.println("Tower IP: ");
    Serial.println(towerip.getValue());
}

void loop() {

}
