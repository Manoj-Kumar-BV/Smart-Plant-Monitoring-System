#define BLYNK_TEMPLATE_ID "TMPL3qNuHZQDb"
#define BLYNK_TEMPLATE_NAME "Plant MonitoringCopy"
#define BLYNK_AUTH_TOKEN "v4JGKdBMGn2OWR3hvJz5apoWRJnlTBC-"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>

char auth[] = BLYNK_AUTH_TOKEN;  // Enter your Blynk Auth token
char ssid[] = "OP";               // Enter your WIFI SSID
char pass[] = "00000007";         // Enter your WIFI Password

DHT dht(D4, DHT11);
BlynkTimer timer;

#define soil A0  // A0 Soil Moisture Sensor
#define PIR D5   // D5 PIR Motion Sensor
#define RELAY_PIN_1 D3  // D3 Relay for Water Pump
#define RELAY_PIN_2 D2  // D2 Relay for Fan
#define VPIN_BUTTON_1 V12
#define VPIN_BUTTON_2 V4

int relay1State = LOW;
int relay2State = LOW;

void setup() {
  Serial.begin(9600);
  pinMode(PIR, INPUT);
  pinMode(RELAY_PIN_1, OUTPUT);
  pinMode(RELAY_PIN_2, OUTPUT);
  digitalWrite(RELAY_PIN_1, LOW);
  digitalWrite(RELAY_PIN_2, LOW);

  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
  dht.begin();

  timer.setInterval(1000L, soilMoistureSensor);
  timer.setInterval(1000L, DHT11sensor);
  timer.setInterval(1000L, PIRsensor);
}

void DHT11sensor() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Blynk.virtualWrite(V0, t);
  Blynk.virtualWrite(V1, h);
}

void soilMoistureSensor() {
  int value = analogRead(soil);
  value = map(value, 0, 1024, 0, 100);
  value = (value - 100) * -1;

  Blynk.virtualWrite(V3, value);
}

void PIRsensor() {
  bool value = digitalRead(PIR);
  if (value) {
    Blynk.logEvent("pirmotion", "WARNING! Motion Detected!");
    Blynk.virtualWrite(V5, HIGH);
  } else {
    Blynk.virtualWrite(V5, LOW);
  }
}

BLYNK_WRITE(VPIN_BUTTON_1) {
  relay1State = param.asInt();
  digitalWrite(RELAY_PIN_1, relay1State); // Control Water Pump
}

BLYNK_WRITE(VPIN_BUTTON_2) {
  relay2State = param.asInt();
  digitalWrite(RELAY_PIN_2, relay2State); // Control Fan
}

void loop() {
  Blynk.run();
  timer.run();
}
