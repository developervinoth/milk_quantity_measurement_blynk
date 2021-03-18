//dependencies
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

//auth and pin declaration
int relay=14; //D5
char auth[] = "20YRJP7GBvKJJuPJLs-tS6XYITeE6Zry";
int delay_int; 

//  WiFi credentials.

char ssid[] = "milk";
char pass[] = "12341234";

BLYNK_WRITE(V0){  // This function gets called each time something changes on the widget
  int delay_int = param.asInt(); 
  delay_int=map(delay_int, 0, 1000, 0, 15000);
  Serial.println(delay_int);
  digitalWrite(relay, HIGH);
  delay(delay_int);
  digitalWrite(relay, LOW);
}

void setup()
{
  // Debug console
  Serial.begin(9600);
pinMode(relay, OUTPUT);
  Blynk.begin(auth, ssid, pass);
}

void loop()
{

  Blynk.run();
}
