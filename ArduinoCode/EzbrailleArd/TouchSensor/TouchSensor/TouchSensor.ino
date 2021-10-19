

int Touch_Sensor_Pin = 24;
int Touch_Sensor_value = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("initialize");
  pinMode(Touch_Sensor_Pin, INPUT);

}

void loop() {
  Touch_Sensor_value = digitalRead(Touch_Sensor_Pin);
  if (Touch_Sensor_value == 1){
      Serial.println("touch sensed");
      delay(1000);
    }
}
