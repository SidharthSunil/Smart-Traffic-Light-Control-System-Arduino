double calibrate=0, Length=0;
float time_for_speed=0, velocity=0 ,time_for_length=0;
boolean active=0;
int objectlength= 24;
int trig1 = 10;
int trig2 = 11;
void setup()
{
  Serial.begin(9600);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  pinMode(trig1, OUTPUT);
  pinMode(trig2, OUTPUT);
}


void loop()
{
  calibrate= millis();
  long dur1, dur2;
  long dist1, dist2;
   digitalWrite(trig1, HIGH);
  // digitalWrite(trig2, HIGH);
   delay(1000);
   digitalWrite(trig1, LOW);
   dur1 = pulseIn(8,HIGH);  
   dist1 = (dur1/2)/29.1;
  // digitalWrite(trig2, LOW);
    if( dur1<=20)
    {
        digitalWrite(trig2, HIGH);
        delay(500);
        digitalWrite(trig2, LOW);
        dur2 = pulseIn(9,HIGH);
        dist2 = (dur2/2)/29.1;
       
        while(dist2<=20);
        time_for_speed= millis()- calibrate;

        digitalWrite(trig2, HIGH);
        delay(500);
        digitalWrite(trig2, LOW);
        dur2 = pulseIn(9,HIGH);
        dist2 = (dur2/2)/29.1;
       
        while(dist2>20);
        time_for_length= millis()-calibrate;
        velocity= 5/time_for_speed;
        Length= velocity*time_for_length;
        Length= Length- objectlength;
        active=1;
    }

    if(active==1)
    {
      Serial.print("length ");
      Serial.print(Length);
      Serial.println(" cm");
      delay(2000);
      active=0;
    }

}
