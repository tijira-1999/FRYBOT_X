int channel[6];

void setup() {
  // put your setup code here, to run once:
     // receiver pins
    pinMode(10,INPUT);  //channel 1
    pinMode(5,INPUT);   //channel 2
    pinMode(6,INPUT);   //channel 3
    pinMode(9,INPUT);   //channel 4 
    pinMode(1,INPUT);   //channel 5
    pinMode(0,INPUT);   //channel 6

    Serial.begin(9600);

}

void loop() 
{
  // put your main code here, to run repeatedly:
  
  channel[0] = pulseIn(10,HIGH);
  channel[1] = pulseIn(5,HIGH);
  channel[2] = pulseIn(6,HIGH);
  channel[3] = pulseIn(9,HIGH);
  channel[4] = pulseIn(1,HIGH);
  channel[5] = pulseIn(0,HIGH);
  
  Serial.print("channel[0]  ");
  Serial.println(channel[0]);
  Serial.println(" ");
  
  Serial.print("channel[1]  ");
  Serial.println(channel[1]);
  Serial.println(" ");
  
  Serial.print("channel[2]  ");
  Serial.println(channel[2]);
  Serial.println(" ");
 
  Serial.print("channel[3]  ");
  Serial.println(channel[3]);
  Serial.println(" ");

  Serial.print("channel[5]  ");
  Serial.println(channel[5]);
  Serial.println(" ");
  delay(1000);
}
