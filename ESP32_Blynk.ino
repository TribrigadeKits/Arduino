#define BLYNK_TEMPLATE_ID "TMPL6scgko8VB"
#define BLYNK_TEMPLATE_NAME "Esp32"
#define BLYNK_AUTH_TOKEN "cX968gv0RuAwcCo4I8peTIz0ggGeEnG4"
const char SSID[] = "*********";
const char PASS[] = "*********";
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
int value;
void setup() {
  // put your setup code here, to run once:
  Blynk.begin(BLYNK_AUTH_TOKEN, SSID, PASS);
  Serial.begin(9600);
  pinMode(25, OUTPUT);

}

BLYNK_WRITE(V0) {
  value = param.asInt();
  value == 1 ? digitalWrite(25, HIGH) : digitalWrite(25, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  Blynk.run() ? Serial.println("Da ket noi") : Serial.println("chua ket noi");
  

}
