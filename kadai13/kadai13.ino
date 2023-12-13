#include <DynamixelWorkbench.h>

#define DEVICE_NAME "1" // Dynamixel on Serial3(USART3) for OpenCM 485EXP
#define BAUDRATE  1000000
#define DXL_ID_1  1
#define DXL_ID_2  2

DynamixelWorkbench dxl_wb;
void performMovement() {
  // モーターの速度を設定
  dxl_wb.goalVelocity(DXL_ID_1, 400);
  dxl_wb.goalVelocity(DXL_ID_2, -400);
  Serial.println("go");
  delay(1100);

  // モーターを停止
  dxl_wb.goalVelocity(DXL_ID_1, 0);
  dxl_wb.goalVelocity(DXL_ID_2, 0);
  delay(500);
  Serial.println("stop");

  // 右ホイールと左ホイールの速度を設定して回転
  dxl_wb.goalVelocity(DXL_ID_1, 500);
  dxl_wb.goalVelocity(DXL_ID_2, 0);
  delay(1200);
  Serial.println("turn");

  // 再び停止
  dxl_wb.goalVelocity(DXL_ID_1, 0);
  dxl_wb.goalVelocity(DXL_ID_2, 0);
  Serial.println("stop");
   delay(500);

  dxl_wb.goalVelocity(DXL_ID_1, 400);
  dxl_wb.goalVelocity(DXL_ID_2, -400);
  Serial.println("go");
  delay(1100);

  
 dxl_wb.goalVelocity(DXL_ID_1, 0);
  dxl_wb.goalVelocity(DXL_ID_2, 0);
  Serial.println("stop");
    delay(500);
}

void setup() {
  Serial.begin(BAUDRATE);
  //while(!Serial); // Wait for Opening Serial Monitor

  const char *log;
  bool result = false;
  uint16_t model_number = 0;

  result = dxl_wb.init(DEVICE_NAME, BAUDRATE, &log);
  if (result == false) {
    Serial.println(log);
    Serial.println("Failed to init");
    return;
  }

  result = dxl_wb.ping(DXL_ID_1, &model_number, &log);
  if (result == false)
  {
    Serial.println(log);
    Serial.println("Failed to ping");
  }
  else
  {
    Serial.println("Succeeded to ping");
    Serial.print("id : ");
    Serial.print(DXL_ID_1);
    Serial.print(" model_number : ");
    Serial.println(model_number);
  }
  result = dxl_wb.ping(DXL_ID_2, &model_number, &log);
  if (result == false)
  {
    Serial.println(log);
    Serial.println("Failed to ping");
  }
  else
  {
    Serial.println("Succeeded to ping");
    Serial.print("id : ");
    Serial.print(DXL_ID_2);
    Serial.print(" model_number : ");
    Serial.println(model_number);
  }


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



  // ロボットの動作を実行
  performMovement();

}

void loop() {
  
} 
