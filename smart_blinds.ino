// Code rotates motor for 5 seconds in one direction and 5 seconds in reverse direction. 
#define motorA 3
#define motorB 2
#define lightSensor 0
#define pushButton 7

int lightLevel;
int isPushed;
int blindsLimit = 0; //variable for is the blinds are fully open/closed, 0 means false

void setup()
{
  pinMode(motorA, OUTPUT);
  pinMode(motorB, OUTPUT);
  pinMode(lightSensor, INPUT);
  pinMode(pushButton, INPUT_PULLUP);
  pinMode(12, OUTPUT);
  Serial.begin(9600);
}
void loop()
{ 
  lightLevel = analogRead(lightSensor);
  
  while(lightLevel < 300 && blindsLimit == 0){
    digitalWrite(motorA, LOW);
    digitalWrite(motorB, HIGH);
    while(digitalRead(pushButton) == 0){
      delay(10);
      blindsLimit = 1;
    }
  break;
  }
  
  while(lightLevel > 300 && blindsLimit == 1){
    digitalWrite(motorA, HIGH);
    digitalWrite(motorB, LOW);
    while(digitalRead(pushButton) == 0){
      delay(10);
      blindsLimit = 0;
    }
  break;
  }
  
  digitalWrite(motorA, LOW);
  digitalWrite(motorB, LOW);
  
}
