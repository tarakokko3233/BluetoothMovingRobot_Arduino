#include <DynamixelWorkbench.h>

#define DEVICE_NAME "1" // Dynamixel on Serial3(USART3) for OpenCM 485EXP
#define BAUDRATE  1000000
#define DXL_ID_1  1
#define DXL_ID_2  2

#define SPEED_FOR_ID_1  400
#define SPEED_FOR_ID_2  100

DynamixelWorkbench dxl_wb;

void setup() {
  Serial.begin(BAUDRATE);
  while(!Serial); // Wait for Opening Serial Monitor

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

}

void loop() {

moveForward(100000000000000); // 10cm前進
Serial.println("moved forward");
delay(1000); // 小休止
Serial.println("stopped");
turn(10); // 90度回転
Serial.println("turned");
delay(1000); // 小休止
Serial.println("stopped");
moveForward(100000000000000); // 10cm前進
Serial.println("moved forward");
delay(10000); // 一時停止

Serial.println("stopped");
turn(10);
Serial.println("turned");
}


 
