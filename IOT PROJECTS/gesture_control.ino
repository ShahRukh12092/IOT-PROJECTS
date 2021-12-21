#define IN1 9    // rear motor
#define IN2 10
#define IN3 11    // front motor
#define IN4 12

char str[2],i;

void forward()
{
    digitalWrite(IN1, 1);
    digitalWrite(IN2, 0);
    digitalWrite(IN3, 1);
    digitalWrite(IN4, 0);

}

void backward()
{

      digitalWrite(IN1, 0);
      digitalWrite(IN2, 1);
      digitalWrite(IN3, 0);
      digitalWrite(IN4, 1);

}

void left()
{
   


   digitalWrite(IN1, 0);
      digitalWrite(IN2, 0);
      digitalWrite(IN3, 1);
      digitalWrite(IN4, 0);
}

void right()
{
  

   digitalWrite(IN1, 1);
    digitalWrite(IN2, 0);
    digitalWrite(IN3, 0);
    digitalWrite(IN4, 0);
}

void Stop()
{
   digitalWrite(IN1, LOW);
   digitalWrite(IN2, LOW);
   digitalWrite(IN3, LOW);
   digitalWrite(IN4, LOW);
}

void setup() 
{
  Serial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() 
{
  while(Serial.available())
  {
    char ch=Serial.read();
    str[i++]=ch;
    
    if(str[i-1]=='1')
    {
     Serial.println("Forward");
     forward();
     i=0;
    }

    else if(str[i-1]=='2')
    {
     Serial.println("Backward");
      backward();
     i=0;
    }

    else if(str[i-1]=='3')
    {
      
      Serial.println("Right");
     right();

      i=0;
    }
    
    else if(str[i-1]=='4')
    {
      Serial.println("Left");
      left();
      i=0;
    }

    else if(str[i-1]=='5')
    {
      Serial.println("Stop");
      Stop();
      i=0;
    }
    delay(100);
  }
}
