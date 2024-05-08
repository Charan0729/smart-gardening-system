#include <ESP8266WiFi.h>
#include <DHT.h>

#define DHTPIN D2          // Pin where the DHT11 is connected
#define DHTTYPE DHT11      // DHT 11
#define TRIGGER_PIN D5     // Pin for ultrasonic sensor trigger
#define ECHO_PIN D6        // Pin for ultrasonic sensor echo
#define SENSOR_PIN A0      // Pin for both LDR and soil moisture sensor
#define RELAY_PIN D7       // Pin for relay control
#define LED_PIN D8         // Pin for controlling the LED

const char* ssid = "WIFI USERNAME";
const char* password = "WIFI PASSWORD";

WiFiServer server(80);
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  delay(10);

  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);     // Set LED pin as output
  pinMode(RELAY_PIN, OUTPUT);   // Set relay pin as output
  
  dht.begin();

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  server.begin();
  Serial.println("WiFi connected");
  Serial.println("Server started");
  Serial.println(WiFi.localIP());
}

void loop() {
  WiFiClient client = server.available();

  if (!client) {
    return;
  }

  while (!client.available()) {
    delay(1);
  }

  String request = client.readStringUntil('\r');
  client.flush();

  if (request.indexOf("/readSensors") != -1) {
    String sensorData = readSensors();
    client.println(sensorData);
  }
}

String readSensors() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  float distance = getUltrasonicDistance();
  int lightIntensity = analogRead(SENSOR_PIN);
  int moisture = analogRead(SENSOR_PIN);

  String data = "Temperature: " + String(temperature) + "°C\n";
  data += "Humidity: " + String(humidity) + "%\n";
  data += "Distance: " + String(distance) + "cm\n";
  data += "Light Intensity: " + String(lightIntensity) + "\n";
  data += "Soil Moisture: " + String(moisture) + "\n";

  // Control LED based on light intensity readings
  if (lightIntensity < 500) { // adjust this threshold according to your environment
    digitalWrite(LED_PIN, HIGH); // Turn on LED
    data += "LED: ON\n";
  } else {
    digitalWrite(LED_PIN, LOW); // Turn off LED
    data += "LED: OFF\n";
  }

  // Control relay based on soil moisture readings
  if (moisture < 500) { // adjust this threshold according to your environment
    digitalWrite(RELAY_PIN, HIGH); // Turn on relay
    data += "Relay: ON\n";
  } else {
    digitalWrite(RELAY_PIN, LOW); // Turn off relay
    data += "Relay: OFF\n";
  }

  return data;
}

float getUltrasonicDistance() {
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);

  float duration = pulseIn(ECHO_PIN, HIGH);
  float distance = duration * 0.034 / 2;
  return distance;
}
