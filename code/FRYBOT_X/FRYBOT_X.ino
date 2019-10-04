double channel[6];
void setup() {
  // put your setup code here, to run once:
  pinMode(3,INPUT);
  pinMode(5,INPUT);
  pinMode(6,INPUT);
  pinMode(9,INPUT);
  pinMode(1,INPUT);
  pinMode(0,INPUT);
  digitalWrite(LED_BUILTIN, LOW);
//Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  channel[0] = pulseIn(3,HIGH);
  channel[1] = pulseIn(5,HIGH);
  channel[2] = pulseIn(6,HIGH);
  channel[3] = pulseIn(9,HIGH);
  channel[4] = pulseIn(0,HIGH);
  channel[5] = pulseIn(1,HIGH);
  
//Serial.print("channel[0]  ");
//  Serial.println(channel[0]);
//  Serial.println(" ");
//  delay(100);
//  Serial.print("channel[1]  ");
//  Serial.println(channel[1]);
//  Serial.println(" ");
//  
//  Serial.print("channel[2]  ");
//  Serial.println(channel[2]);
//  Serial.println(" ");
// 
//  Serial.print("channel[3]  ");
//  Serial.println(channel[3]);
//  Serial.println(" ");
//
//    Serial.print("channel[4]  ");
//  Serial.println(channel[4]);
//  Serial.println(" ");
//  delay(1000);

  if(channel[5]>1450 && channel[5]<1500){
    digitalWrite(LED_BUILTIN, HIGH);
  }
  else {
    digitalWrite(LED_BUILTIN, LOW);
  }
  
}
