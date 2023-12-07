#define SEG_G 1
#define SEG_F 2
#define SEG_E 4
#define SEG_D 5
#define SEG_C 7
#define SEG_B 9
#define SEG_A 10
#define SEG_DP 6

void setup() {
  pinMode(SEG_G, OUTPUT);
  pinMode(SEG_F, OUTPUT);
  pinMode(SEG_E, OUTPUT);
  pinMode(SEG_D, OUTPUT);
  pinMode(SEG_C, OUTPUT);
  pinMode(SEG_B, OUTPUT);
  pinMode(SEG_A, OUTPUT);
  pinMode(SEG_DP, OUTPUT);
}

void loop() {
  Serial.println("0");
  digitalWrite(SEG_G, HIGH);
  digitalWrite(SEG_F, LOW);
  digitalWrite(SEG_E, LOW);
  digitalWrite(SEG_D, LOW);
  digitalWrite(SEG_C, LOW);
  digitalWrite(SEG_B, LOW);
  digitalWrite(SEG_A, LOW);
  digitalWrite(SEG_DP, HIGH);
  delay(1000);
  Serial.println("1");
  digitalWrite(SEG_G, HIGH);
  digitalWrite(SEG_F, HIGH);
  digitalWrite(SEG_E, HIGH);
  digitalWrite(SEG_D, HIGH);
  digitalWrite(SEG_C, LOW);
  digitalWrite(SEG_B, LOW);
  digitalWrite(SEG_A, HIGH);
  digitalWrite(SEG_DP, HIGH);
  delay(1000);
  Serial.println("2");
  digitalWrite(SEG_G, LOW);
  digitalWrite(SEG_F, HIGH);
  digitalWrite(SEG_E, LOW);
  digitalWrite(SEG_D, LOW);
  digitalWrite(SEG_C, HIGH);
  digitalWrite(SEG_B, LOW);
  digitalWrite(SEG_A, LOW);
  digitalWrite(SEG_DP, HIGH);
  delay(1000);
  Serial.println("3");
  digitalWrite(SEG_G, LOW);
  digitalWrite(SEG_F, HIGH);
  digitalWrite(SEG_E, HIGH);
  digitalWrite(SEG_D, LOW);
  digitalWrite(SEG_C, LOW);
  digitalWrite(SEG_B, LOW);
  digitalWrite(SEG_A, LOW);
  digitalWrite(SEG_DP, HIGH);
  delay(1000);
  Serial.println("4");
  digitalWrite(SEG_G, LOW);
  digitalWrite(SEG_F, LOW);
  digitalWrite(SEG_E, HIGH);
  digitalWrite(SEG_D, HIGH);
  digitalWrite(SEG_C, LOW);
  digitalWrite(SEG_B, LOW);
  digitalWrite(SEG_A, HIGH);
  digitalWrite(SEG_DP, HIGH);
  delay(1000);
  Serial.println("5");
  digitalWrite(SEG_G, LOW);
  digitalWrite(SEG_F, LOW);
  digitalWrite(SEG_E, HIGH);
  digitalWrite(SEG_D, LOW);
  digitalWrite(SEG_C, LOW);
  digitalWrite(SEG_B, HIGH);
  digitalWrite(SEG_A, LOW);
  digitalWrite(SEG_DP, HIGH);
  delay(1000);
  Serial.println("6");
  digitalWrite(SEG_G, LOW);
  digitalWrite(SEG_F, LOW);
  digitalWrite(SEG_E, LOW);
  digitalWrite(SEG_D, LOW);
  digitalWrite(SEG_C, LOW);
  digitalWrite(SEG_B, HIGH);
  digitalWrite(SEG_A, LOW);
  digitalWrite(SEG_DP, HIGH);
  delay(1000);
  Serial.println("7");
  digitalWrite(SEG_G, HIGH);
  digitalWrite(SEG_F, HIGH);
  digitalWrite(SEG_E, HIGH);
  digitalWrite(SEG_D, HIGH);
  digitalWrite(SEG_C, LOW);
  digitalWrite(SEG_B, LOW);
  digitalWrite(SEG_A, LOW);
  digitalWrite(SEG_DP, HIGH);
  delay(1000);
  Serial.println("8");
  digitalWrite(SEG_G, LOW);
  digitalWrite(SEG_F, LOW);
  digitalWrite(SEG_E, LOW);
  digitalWrite(SEG_D, LOW);
  digitalWrite(SEG_C, LOW);
  digitalWrite(SEG_B, LOW);
  digitalWrite(SEG_A, LOW);
  digitalWrite(SEG_DP, HIGH);
  delay(1000);
  Serial.println("9");
  digitalWrite(SEG_G, LOW);
  digitalWrite(SEG_F, LOW);
  digitalWrite(SEG_E, HIGH);
  digitalWrite(SEG_D, LOW);
  digitalWrite(SEG_C, LOW);
  digitalWrite(SEG_B, LOW);
  digitalWrite(SEG_A, LOW);
  digitalWrite(SEG_DP, HIGH);
  delay(1000);
  
  
}
