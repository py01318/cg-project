const int IN3 = 2;  // L298N IN3
const int IN4 = 5;  // L298N IN4
const int ENB = 8;  // L298N ENB (PWM対応ピン)

void setup() {
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);

  analogWrite(ENB, 150); // モーター速度（0～255）

  // 初期停止
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void loop() {
  // 正回転
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(1000);  // 1秒

  // 停止
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  delay(1000);

  // 逆回転
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(1000);

  // 停止
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  delay(1000);
}
