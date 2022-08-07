const int sensorMin = 0;     
const int sensorMax = 1024; 

int buzzer = 12;
int smokeA0 = A5;
int sensorThres = 400;

void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(smokeA0, INPUT);
  Serial.begin(9600);
}

void loop() {
  int analogSensor = analogRead(smokeA0);

  Serial.print("smoke: ");
  Serial.println(analogSensor);
  // Checks if it has reached the threshold value
  if (analogSensor > sensorThres)
  {
   
    
    tone(buzzer, 1000, 200);
  }
  else
  {
    
    noTone(buzzer);
  }
  delay(300);


 int sensorReading = analogRead(A0);
  
int range = map(sensorReading, sensorMin, sensorMax, 0, 3);
  

  switch (range) {
  case 0:    
    Serial.println("** Close Fire **");
    tone(buzzer, 1000, 200);
    break;
  case 1:    
    Serial.println("** Distant Fire **");
    tone(buzzer, 1000, 200);
    break;
  case 2:    
    Serial.println("No Fire");
    break;
  }
}
