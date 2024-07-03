int a_pin = 2;
int b_pin = 3;
int c_pin = 4;
int d_pin = 5;
int button = 6;
int com1 = 7;
int com2 = 8;
int com3 = 9;
int com4 = 10;
int d_com[] = {0, 0};
int binary[10][4] = {
  { 0, 0, 0, 0 },
  { 0, 0, 0, 1 },
  { 0, 0, 1, 0 },
  { 0, 0, 1, 1 },
  { 0, 1, 0, 0 },
  { 0, 1, 0, 1 },
  { 0, 1, 1, 0 },
  { 0, 1, 1, 1 },
  { 1, 0, 0, 0 },
  { 1, 0, 0, 1 }
};
int count = 0;
unsigned long current = 0;
unsigned long previous = 0;
void display(int num) {
  for (int i = 0; i < 4; i++) {
    digitalWrite(d_pin - i, binary[num][i]);
  }
}
void setup() {
  // put your setup code here, to run once:
  pinMode(a_pin, OUTPUT);
  pinMode(b_pin, OUTPUT);
  pinMode(c_pin, OUTPUT);
  pinMode(d_pin, OUTPUT);
  pinMode(button, INPUT);
  pinMode(com1, OUTPUT);
  pinMode(com2, OUTPUT);
  pinMode(com3, OUTPUT);
  pinMode(com4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  digitalWrite(com3, LOW);
  digitalWrite(com4, LOW);
  current = millis();
  if (digitalRead(button) == 1) {
    if (current - previous >= 20) {
      if (digitalRead(button) == 1) {
        count++;
        if (count > 9)
          count = 0;
      }
    }
    previous = current;
  }
  display(count);
}
