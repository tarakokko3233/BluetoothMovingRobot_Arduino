#include <DynamixelWorkbench.h>

#define DEVICE_NAME "1" // Dynamixel on Serial3(USART3) for OpenCM 485EXP
#define BAUDRATE  1000000
#define DXL_ID_1  1
#define DXL_ID_2  2
#define DXL_ID_3  3

DynamixelWorkbench dxl_wb;

void setup() {
  Serial.begin(57600);
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

  // Try to ping motor with ID 1
  result = dxl_wb.ping(DXL_ID_1, &model_number, &log);
  if (result == true) {
    result = dxl_wb.changeID(DXL_ID_1, DXL_ID_2, &log);
    if (result == true) {
      Serial.println("Changed ID from 1 to 2");
    } else {
      Serial.print("Failed to change ID: ");
      Serial.println(log);
    }
  } else {
    result = dxl_wb.ping(DXL_ID_2, &model_number, &log);
    if (result == true) {
      result = dxl_wb.changeID(DXL_ID_2, DXL_ID_1, &log);
      if (result == true) {
        Serial.println("Changed ID from 2 to 1");
      } else {
        Serial.print("Failed to change ID: ");
        Serial.println(log);
      }
    } else {
      Serial.println("No motors found with ID 1 or 2");
    }
  }
}

void loop() {
  // Do nothing here
}
