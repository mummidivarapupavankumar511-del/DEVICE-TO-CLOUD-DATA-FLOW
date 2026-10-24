#include <WiFi.h>
#include <DHT.h>
#include <PubSubClient.h>

#define DHT_PIN 4
#define DHT_TYPE DHT22

const char* ssid = "Wokwi-GUEST";
const char* password = "";

const char* mqtt_server = "test.mosquitto.org";
const int mqtt_port = 1883;

const char* topic =
  "skillaudit/esp32/dht22/sensor123";

DHT dht(DHT_PIN, DHT_TYPE);

WiFiClient espClient;
PubSubClient client(espClient);

unsigned long lastRead = 0;
const unsigned long interval = 5000;

void connectWiFi() {
  Serial.print("Connecting to WiFi");

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi connected!");
}

void connectMQTT() {
  while (!client.connected()) {
    Serial.print("Con…
