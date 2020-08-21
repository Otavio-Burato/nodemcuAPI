#include <ESP8266WiFi.h>
#include <MQTTClient.h>

const char* ssid     = "SSID";
const char* password = "PASSWORD";

WiFiClient WiFiclient;
MQTTClient client;

unsigned long lastMillis = 0;

void setup() {
    Serial.begin(115200);
    pinMode(A0,INPUT); 
    pinMode(D4,OUTPUT);
    delay(10);
    
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
    }
    Serial.println(WiFi.localIP());
    delay(2000);
    
    client.begin("$HOST.local", WiFiclient);
    connect();
}

void connect() {
    while (!client.connect("nodemcu", "try", "try")) {
        digitalWrite(D4,HIGH);
    }
    digitalWrite(D4,LOW);
}

void loop() {
    long value= 0;
    client.loop();
    if(!client.connected()) {
        connect();
    }
    delay(1000);
    value = analogRead(A0);
    value = map(value,0,1023,0,255);
    
    client.publish("message", (String)value);
    
}
