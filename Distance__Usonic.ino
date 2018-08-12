#define trigger 3
#define echo 2
#define relay 8
#define LIMIT 40+

long duration, distance;
int count=0;
void setup()
{
 pinMode(trigger,OUTPUT);
 pinMode(echo,INPUT);
 pinMode(relay,OUTPUT);
 digitalWrite(relay,LOW);

 Serial.begin(9600);
 Serial.println("\nReady");
}

void loop()
{
 digitalWrite(trigger,LOW);
 delayMicroseconds(2);
 digitalWrite(trigger,HIGH);
 delayMicroseconds(10);
 digitalWrite(trigger,LOW);
 //delayMicroseconds(2);
 duration = pulseIn(echo, HIGH);
 distance= duration*0.034/2;
 Serial.print("Distance: ");
 Serial.print(distance);
 Serial.print(" cm ");
 Serial.print(" and in meters: ");
 Serial.println(distance/100);
 Serial.print("\n Count: ");
 Serial.println(count); 
 if (distance<LIMIT)
  {
    digitalWrite(relay,HIGH);
    count=100;
  }
 else if(distance>LIMIT ||count==0)
  {  
     if(count==0)
     { digitalWrite(relay,LOW);
     }
  }
 
  if(count>0)
   {   count--;
   } 
  delay(100); 
}
