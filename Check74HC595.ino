// Chân kết nối với 74HC595
int dataPin = 11;  // SER
int latchPin = 12; // RCLK
int clockPin = 10; // SRCLK

void setup() {
  // Thiết lập các chân là OUTPUT
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}

void loop() {
  for (int i = 0; i < 65536; i++) { // Lặp qua 16-bit giá trị
    digitalWrite(latchPin, LOW);    // Hạ thấp chân latch để chuẩn bị nhận dữ liệu
    shiftOut(dataPin, clockPin, MSBFIRST, (i >> 8));  // Gửi byte cao
    shiftOut(dataPin, clockPin, MSBFIRST, i);         // Gửi byte thấp
    digitalWrite(latchPin, HIGH);   // Nâng cao chân latch để khóa dữ liệu
    delay(50);                     // Đợi 500ms trước khi thay đổi mẫu
  }
}
