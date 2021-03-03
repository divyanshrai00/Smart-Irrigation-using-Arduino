int m = 0;
int WATER_LEVEL = 0;
void setup()
{
  pinMode(A0,INPUT_PULLUP);
  pinMode(A1,INPUT);
  pinMode(8,OUTPUT);                             // buzzer
  pinMode(7,OUTPUT);                             //pump
  Serial.begin(9600);
}
void loop()
{
  int m = analogRead(A0);                       // to measure moisture in the soil
  int WATER_LEVEL = analogRead(A1);             // to measure water level in the pump 
  Serial.println(m);
  delay(200);
  Serial.println(WATER_LEVEL);
  delay(200);
  if(m>=980 && WATER_LEVEL>=2500)
  {
    digitalWrite(8,LOW);                        //pump is OFF
    digitalWrite(7,LOW);                        //buzzer is OFF
  }
  else if(m<980 && WATER_LEVEL>=2500)
  {
    digitalWrite(7,HIGH);                       //pump starts
    digitalWrite(8,LOW);                        //buzzer is OFF
  }
  else
  {
    digitalWrite(8,HIGH);                       //buzzer is ON
  }
}
