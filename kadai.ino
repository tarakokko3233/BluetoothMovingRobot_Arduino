#include <DynamixelWorkbench.h>
#include <OLLO.h> 
OLLO myOLLO;

#define DEVICE_NAME "1" // Dynamixel on Serial3(USART3) for OpenCM 485EXP
#define BAUDRATE  1000000
#define DXL_ID_1  1
#define DXL_ID_2  2



// IRセンサーの閾値
#define IR_THRESHOLD 50

DynamixelWorkbench dxl_wb;

void setup() {
  Serial.begin(BAUDRATE);
  Serial3.begin(9600);
  

  // Dynamixelの初期化
  const char *log;
  bool result = false;
  uint16_t model_number = 0;

  result = dxl_wb.init(DEVICE_NAME, BAUDRATE, &log);
  if (result == false) {
    Serial.println(log);
    Serial.println("Failed to init");
    return;
  }

  // DynamixelモーターのPingテスト
  result = dxl_wb.ping(DXL_ID_1, &model_number, &log);
  if (result == false) {
    Serial.println(log);
    Serial.println("Failed to ping DXL_ID_1");
  } else {
    Serial.println("Succeeded to ping DXL_ID_1");
  }

  result = dxl_wb.ping(DXL_ID_2, &model_number, &log);
  if (result == false) {
    Serial.println(log);
    Serial.println("Failed to ping DXL_ID_2");
  } else {
    Serial.println("Succeeded to ping DXL_ID_2");
  }

  // モーターのベロシティ制御モード設定
  result = dxl_wb.setVelocityControlMode(DXL_ID_1, &log);
  if (!result) {
    Serial.println(log);
    Serial.println("Failed to set wheel mode for ID 1");
  } else {
    Serial.println("Succeeded to set wheel mode for ID 1");
  }
  
  result = dxl_wb.setVelocityControlMode(DXL_ID_2, &log);
  if (!result) {
    Serial.println(log);
    Serial.println("Failed to set wheel mode for ID 2");
  } else {
    Serial.println("Succeeded to set wheel mode for ID 2");
  }

  // IRセンサーの初期化
  myOLLO.begin(1, IR_SENSOR); // 左のIRセンサー
  myOLLO.begin(4, IR_SENSOR); // 右のIRセンサー

  Serial3.println("Setup3 complete"); 
  Serial.println("Setup complete"); 
  }


void loop() {
  int leftIRValue = myOLLO.read(1, IR_SENSOR);
  int rightIRValue = myOLLO.read(4, IR_SENSOR);

  bool leftBlocked = leftIRValue > IR_THRESHOLD;
  bool rightBlocked = rightIRValue > IR_THRESHOLD;

  if (leftBlocked && rightBlocked) {
    stopMovement();
  } else if (leftBlocked) {
    turnAndReturn("left");
  } else if (rightBlocked) {
    turnAndReturn("right");
  } else {
    moveForward();
  }
  // シリアルポートにデータがあるか確認
  if (Serial3.available()) {
    // データを読み取り、変数に格納
    char receivedChar = Serial3.read();
    
    // 受信したデータを処理（例：シリアルモニタに表示）
    Serial.println(receivedChar);
  }
  Serial.print(leftIRValue);
  Serial.print(",");
  Serial.println(rightIRValue);
  Serial3.print("Left IR: ");
  Serial3.print(leftIRValue);
  Serial3.print(", Right IR: ");
  Serial3.println(rightIRValue);


  delay(500);
}

unsigned long turnLeft(unsigned long duration = 0) {
  unsigned long startTime = millis();

  if (duration == 0) { // 曲がり始めるとき
  dxl_wb.goalVelocity(DXL_ID_1, 0); // 左に曲がる
  dxl_wb.goalVelocity(DXL_ID_2, 100);
    return millis() - startTime;
  } else { // 元に戻るとき
    dxl_wb.goalVelocity(DXL_ID_1, 0); // 右に曲がる
    dxl_wb.goalVelocity(DXL_ID_2, 100);
    delay(duration);
    return 0;
  }
}

unsigned long turnRight(unsigned long duration = 0) {
  unsigned long startTime = millis();

  if (duration == 0) { // 曲がり始めるとき
    dxl_wb.goalVelocity(DXL_ID_1, -100); // 右に曲がる
    dxl_wb.goalVelocity(DXL_ID_2, 0);
    return millis() - startTime;
  } else { // 元に戻るとき
    dxl_wb.goalVelocity(DXL_ID_1, 100); // 左に曲がる
    dxl_wb.goalVelocity(DXL_ID_2, 0);
    delay(duration);
    return 0;
  }
}

void turnAndReturn(String direction) {
  unsigned long turnTime;
  if (direction == "left") {
    turnTime = turnLeft();
    delay(2000); // 2秒間まっすぐ進む
    turnRight(turnTime);
  } else {
    turnTime = turnRight();
    delay(2000); // 2秒間まっすぐ進む
    turnLeft(turnTime);
  }
  moveForward();
}

void moveForward() {
  dxl_wb.goalVelocity(DXL_ID_1, -200);
  dxl_wb.goalVelocity(DXL_ID_2, 200);
}

void stopMovement() {
  dxl_wb.goalVelocity(DXL_ID_1, 0);
  dxl_wb.goalVelocity(DXL_ID_2, 0);
}
