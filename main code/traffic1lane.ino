int trigPin = 3;
int echoPin = 4;
int ledG = 6;
int ledR = 5;
int Time = 30;

int flag = 4;         //Time slice

void setup() {
  Serial.begin(9600);
  pinMode(ledG, OUTPUT);
  pinMode(ledR, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  low();
 // pinMode(LED_BUILTIN, OUTPUT);
  // put your setup code here, to run once:

}
  
void loop() {
  long duration, distance;
  digitalWrite(trigPin,HIGH);
  delay(500);
  digitalWrite(trigPin, LOW);
  duration=pulseIn(echoPin, HIGH);
  distance =(duration/2)/29.1;
  //Serial.print(distance);
 // Serial.println("CM");
  delay(10);
 // low();
 if((distance<=20)) 
  {
    //delay(500);
    high();
   // digitalWrite(ledG, HIGH);
   // digitalWrite(LED_BUILTIN, HIGH);
    flag = 4;
    Time--;
    delay(1000);
    if(Time == 0)
     {
      low();
      delay(5000);
     // Time = 30;
     }
      
}
   else if(distance>20)
 {
    if(flag!=0)
    {
      flag--;
      if(Time!=30)
      {
        Time--;
      }
      delay(1000);
    }
    
    if(flag == 0 || Time == 0){
      low();
     // Time = 30;
      flag = 4;
      delay(3000);
    }
    
   }
}

void low()
{
  digitalWrite(ledG, LOW);
  digitalWrite(ledR,HIGH);
  Time = 30;
  //digitalWrite(LED_BUILTIN, LOW);
}

void high()
{
  digitalWrite(ledG, HIGH);
  digitalWrite(ledR, LOW);
}
