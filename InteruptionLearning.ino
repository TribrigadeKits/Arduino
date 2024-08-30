const int buttonPin1 = 2;   // Chân kết nối với button 1
const int buttonPin2 = 3;   // Chân kết nối với button 2
const int led_green = 4;    // Chân kết nối với đèn LED xanh
const int led_red = 5;      // Chân kết nối với đèn LED đỏ
volatile bool isPressed1 = false;  // Trạng thái của button 1
volatile bool isPressed2 = false;  // Trạng thái của button 2

void setup() {
  pinMode(led_green, OUTPUT);      // Thiết lập chân LED xanh là OUTPUT
  pinMode(led_red, OUTPUT);        // Thiết lập chân LED đỏ là OUTPUT
  pinMode(buttonPin1, INPUT_PULLUP); // Thiết lập chân button 1 là INPUT với pull-up
  pinMode(buttonPin2, INPUT_PULLUP); // Thiết lập chân button 2 là INPUT với pull-up
  attachInterrupt(digitalPinToInterrupt(buttonPin1), handleInterruptForButton1, CHANGE); // Thiết lập ngắt cho button 1
  attachInterrupt(digitalPinToInterrupt(buttonPin2), handleInterruptForButton2, CHANGE); // Thiết lập ngắt cho button 2
  Serial.begin(9600);
}

void loop() {
  // Kiểm tra trạng thái của isPressed1 và isPressed2 để thực hiện các hành động tương ứng
  if (isPressed1) {
    digitalWrite(led_green, HIGH); // Bật đèn LED xanh
  } else {
    digitalWrite(led_green, LOW);  // Tắt đèn LED xanh
  }

  if (isPressed2) {
    digitalWrite(led_red, HIGH); // Bật đèn LED đỏ
  } else {
    digitalWrite(led_red, LOW);  // Tắt đèn LED đỏ
  }
}

void handleInterruptForButton1() {
  static unsigned long lastInterruptTime1 = 0;  // Biến để lưu thời gian ngắt cuối cùng cho button 1
  unsigned long interruptTime1 = millis();  // Lấy thời gian hiện tại

  // Kiểm tra debounce (tránh nhiễu) 
  if (interruptTime1 - lastInterruptTime1 >= 200) {
    // Đổi trạng thái của isPressed1
    isPressed1 = !isPressed1;
    lastInterruptTime1 = interruptTime1;
    Serial.println("Button 1 Pressed");
  }
}

void handleInterruptForButton2() {
  static unsigned long lastInterruptTime2 = 0;  // Biến để lưu thời gian ngắt cuối cùng cho button 2
  unsigned long interruptTime2 = millis();  // Lấy thời gian hiện tại

  // Kiểm tra debounce (tránh nhiễu) 
  if (interruptTime2 - lastInterruptTime2 >= 200) {
    // Đổi trạng thái của isPressed2
    isPressed2 = !isPressed2;
    lastInterruptTime2 = interruptTime2;
    Serial.println("Button 2 Pressed");
  }
}
