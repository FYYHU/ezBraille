
int Touch_Sensor_Pin = 22;
int Touch_Sensor_value;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Touch_Sensor_Pin, INPUT);

}

void loop() {
  Touch_Sensor_value = 0;
  Touch_Sensor_value = digitalRead(Touch_Sensor_Pin);
  if (Touch_Sensor_value == HIGH){
      Serial.println("touch sensed");
    }

}
