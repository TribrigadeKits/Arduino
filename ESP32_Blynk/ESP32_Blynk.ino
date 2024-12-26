#define BLYNK_TEMPLATE_ID "TMPL6scgko8VB"
#define BLYNK_TEMPLATE_NAME "Esp32"
#define BLYNK_AUTH_TOKEN "cX968gv0RuAwcCo4I8peTIz0ggGeEnG4"
#define in1 14
#define in2 15
#define in3 18
#define in4 19
const char SSID[] = "ICT-student";
const char PASS[] = "Z4xejEV7esup";
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
int value;

void fowardMotor1() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
}

void backwardMotor1() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
}

void fowardMotor2() {
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void backwardMotor2() {
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void stopMotor1() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
}

void stopMotor2() {
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
void setup() {
  // put your setup code here, to run once:
  Blynk.begin(BLYNK_AUTH_TOKEN, SSID, PASS);
  Serial.begin(9600);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

}

BLYNK_WRITE(V0) {
  value = param.asInt();
  // value == 1 ? fowardMotor1() : stopMotor1();
  if (value == 1)
    fowardMotor1();
  else 
    stopMotor1();
}

BLYNK_WRITE(V1) {
  value = param.asInt();
  // value == 1 ? fowardMotor1() : stopMotor1();
  if (value == 1)
    backwardMotor1();
  else 
    stopMotor1();
}

BLYNK_WRITE(V2) {
  value = param.asInt();
  // value == 1 ? fowardMotor1() : stopMotor1();
  if (value == 1)
    fowardMotor2();
  else 
    stopMotor2();
}

BLYNK_WRITE(V3) {
  value = param.asInt();
  // value == 1 ? fowardMotor1() : stopMotor1();
  if (value == 1)
    backwardMotor2();
  else 
    stopMotor2();
}

void loop() {
  // put your main code here, to run repeatedly:
  Blynk.run() ? Serial.println("Da ket noi") : Serial.println("chua ket noi");
  

}
