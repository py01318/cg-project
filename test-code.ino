// L298N①（X軸 左側）
const int EN_1 = 3;    // ①ENA+ENB
const int IN1_1 = 4;   // ①IN1 + IN3
const int IN2_1 = 2;   // ①IN2 + IN4

// L298N②（X軸 右側）
const int EN_2 = 5;    // ②ENA+ENB
const int IN1_2 = 7;   // ②IN1 + IN3
const int IN2_2 = 6;   // ②IN2 + IN4

// L298N③（Y軸）
const int EN_3 = 8;    // ③ENB
const int IN1_3 = 10;  // ③IN3
const int IN2_3 = 9;   // ③IN4

// L298N③（Z軸）
const int EN_4 = 11;   // ③ENA
const int IN1_4 = 12;  // ③IN1
const int IN2_4 = 13;  // ③IN2

void setup() {
  // X軸①
  pinMode(EN_1, OUTPUT);
  pinMode(IN1_1, OUTPUT);
  pinMode(IN2_1, OUTPUT);

  // X軸②
  pinMode(EN_2, OUTPUT);
  pinMode(IN1_2, OUTPUT);
  pinMode(IN2_2, OUTPUT);

  // Y軸③
  pinMode(EN_3, OUTPUT);
  pinMode(IN1_3, OUTPUT);
  pinMode(IN2_3, OUTPUT);

  // Z軸④
  pinMode(EN_4, OUTPUT);
  pinMode(IN1_4, OUTPUT);
  pinMode(IN2_4, OUTPUT);
}

void loop() {
  // --- X軸テスト ---（正転50% → 停止 → 逆転50%）
  setMotor(EN_1, IN1_1, IN2_1, true, 128); // X軸 正転
  setMotor(EN_2, IN1_2, IN2_2, true, 128);
  delay(1500);

  stopMotor(EN_1);  //停止
  stopMotor(EN_2);
  delay(1000);

  setMotor(EN_1, IN1_1, IN2_1, false, 128); // X軸 逆転
  setMotor(EN_2, IN1_2, IN2_2, false, 128);
  delay(1500);

  stopMotor(EN_1); //停止
  stopMotor(EN_2);
  delay(1000);

  // --- Y軸テスト ---（正転50% → 停止 → 逆転50%）
  setMotor(EN_3, IN1_3, IN2_3, true, 128);  // Y軸 正転
  delay(1000);

  stopMotor(EN_3); //停止
  delay(500);

  setMotor(EN_3, IN1_3, IN2_3, false, 128); // Y軸 逆転
  delay(1000);

  stopMotor(EN_3); //停止
  delay(1000);

  // --- Z軸テスト ---（正転50% → 停止 → 逆転50%）
  setMotor(EN_4, IN1_4, IN2_4, true, 128);  // Z軸 上昇
  delay(1000);

  stopMotor(EN_4); //停止
  delay(500);

  setMotor(EN_4, IN1_4, IN2_4, false, 128); // Z軸 降下
  delay(1000);

  stopMotor(EN_4); //停止
  delay(2000);
}

// 共通モーター制御
void setMotor(int enPin, int in1, int in2, bool forward, byte speedVal) {
  digitalWrite(in1, forward ? HIGH : LOW);
  digitalWrite(in2, forward ? LOW  : HIGH);
  analogWrite(enPin, speedVal);
}

// 共通モーター停止
void stopMotor(int enPin) {
  analogWrite(enPin, 0);
}
