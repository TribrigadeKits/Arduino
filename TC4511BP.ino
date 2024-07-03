// A B C D TC4511BP pins 
int a_pin = 2;
int b_pin = 3;
int c_pin = 4;
int d_pin = 5;

// 0-9 表示するためのデータ
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
// 数字を表示するための関数
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
}

void loop() {
  // put your main code here, to run repeatedly:
  
  current = millis();　  // 現在の時点を取る
  // millisでチャタリング対策
  if (digitalRead(button) == 1) {
    if (current - previous >= 20) {
      // ボータンを押した時点を20ｍｓを経過させる
      if (digitalRead(button) == 1) {
        count++;
        if (count > 9)
          count = 0;
      }
    }
    previous = current;　// countした後時間を更新する
  }
  display(count);
}
