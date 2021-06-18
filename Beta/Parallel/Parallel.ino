//int trigPin = 11;
int echoPin = 10;
int trigPii = 12;
int led = 8;
int cnt = 0;
int flag=0;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
 // pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPii, OUTPUT);
 // pinMode(LED_BUILTIN, OUTPUT);
  // put your setup code here, to run once:

}

void loop() {
  long duration, distance;
  //digitalWrite(trigPin,HIGH);
  //delay(500);
  //digitalWrite(trigPin, LOW);
  
  digitalWrite(trigPii, HIGH);
  delay(50);
  digitalWrite(trigPii, LOW);
  
  duration=pulseIn(echoPin, HIGH);
  distance =(duration/2)/29.1;
  //Serial.print(distance);
  //Serial.println("CM");
  delay(10);
 
 if((distance<=20)) 
  {
    digitalWrite(led, LOW);
   // digitalWrite(LED_BUILTIN, HIGH);
   flag = 0;
}
   else if(distance>20)
 {
     digitalWrite(led, HIGH);
     
     if(flag==0){
      cnt++;
      flag=1;
      Serial.println(cnt);
     }
     
   //  digitalWrite(LED_BUILTIN, LOW);
   }
}
