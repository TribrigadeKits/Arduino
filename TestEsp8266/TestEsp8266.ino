#define BLYNK_TEMPLATE_ID "TMPL6scgko8VB"
#define BLYNK_TEMPLATE_NAME "Esp8266"
#define BLYNK_AUTH_TOKEN "cX968gv0RuAwcCo4I8peTIz0ggGeEnG4"
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
const int green_led = D0;
const int yellow_led = D1;
const int red_led = D2;
int button_green, button_yellow, button_red;
char ssid[] = "ARRIS-BA421";
char pass[] = "34M87aAPrAep8";
void setup() {
  // put your setup code here, to run once:
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  pinMode(green_led, OUTPUT);
  pinMode(yellow_led, OUTPUT);
  pinMode(red_led, OUTPUT);
}

BLYNK_WRITE(V3) {
  button_green = param.asInt();
  button_green == 1 ? digitalWrite(green_led, HIGH) : digitalWrite(green_led, LOW);
}

BLYNK_WRITE(V4) {
  button_yellow = param.asInt();
  button_yellow == 1 ? digitalWrite(yellow_led, HIGH) : digitalWrite(yellow_led, LOW);
}

BLYNK_WRITE(V5) {
  button_red = param.asInt();
  button_red == 1 ? digitalWrite(red_led, HIGH) : digitalWrite(red_led, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
 Blynk.run();
}
