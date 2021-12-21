const int LeftMotorForward = 1;
const int LeftMotorBackward = 2;
const int RightMotorForward = 3;
const int RightMotorBackward = 4;
const int buzzerPin = 7;
const int buzzerPin1 = 8;
const int flamePinF = 13;
const int flamePinL = 12;
const int flamePinR = 11;
int Flame = HIGH;

void setup(){

  pinMode(RightMotorForward, OUTPUT);
  pinMode(LeftMotorForward, OUTPUT);
  pinMode(LeftMotorBackward, OUTPUT);
  pinMode(RightMotorBackward, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(buzzerPin1, OUTPUT);
  pinMode(flamePinF, INPUT);
  pinMode(flamePinL, INPUT);
  pinMode(flamePinR, INPUT);
}

void loop(){
  Flame = digitalRead(flamePinF);
  if (Flame== LOW)
  {
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(buzzerPin1, HIGH);
    moveForward();
  }
  else
  {
    digitalWrite(buzzerPin, LOW);
    digitalWrite(buzzerPin1, LOW);
    moveStop();
  }
  
  Flame = digitalRead(flamePinL);
  if (Flame== LOW)
  {
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(buzzerPin1, HIGH);
    turnLeft();
    moveForward();
  }
  else
  {
    digitalWrite(buzzerPin, LOW);
    digitalWrite(buzzerPin1, LOW);
    moveStop();
  }
  
  Flame = digitalRead(flamePinR);
  if (Flame== LOW)
  {
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(buzzerPin1, HIGH);
    turnRight();
    moveForward();
  }
  else
  {
    digitalWrite(buzzerPin, LOW);
    digitalWrite(buzzerPin1, LOW);
    moveStop();
  }
}

void moveStop(){
  
  digitalWrite(RightMotorForward, LOW);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);
  digitalWrite(LeftMotorBackward, LOW);
}

void moveForward(){
    
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorBackward, LOW);
}

void turnRight(){

  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorBackward, HIGH);
  
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorForward, LOW);
  
}

void turnLeft(){
  digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
  
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);
}
