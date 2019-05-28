#define trigPin 8
#define echoPin 6
#define button 9
#define greenLed 10
#define redLed 11
#define blueLed 12
#define buzzer 13

int survey=0;
bool s = false, s2 = false;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(button, INPUT_PULLUP);
  pinMode(greenLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  while(digitalRead(button)!=LOW){
  }
  delay(5000);
  digitalWrite(greenLed, HIGH);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  survey = pulseIn(echoPin, HIGH)/1000;
  Serial.println(survey);
}

void loop() {
  if(s==false){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  int tmp;
  tmp = (pulseIn(echoPin, HIGH)/1000);
  Serial.println(tmp);
  if(survey != tmp ){
   Serial.println("niedziala");
   digitalWrite(buzzer, HIGH);
   digitalWrite(greenLed, LOW);
   s=true; 
  }
  delay(500);
  }
  else if(s==true){
    if(s2 == false){
     digitalWrite(redLed, HIGH);
     delay(250);
     digitalWrite(redLed, LOW);
     digitalWrite(blueLed, HIGH);
     delay(250);
     digitalWrite(blueLed, LOW);
     if(digitalRead(button)==LOW){
      s2=true;
      digitalWrite(redLed, LOW);
      digitalWrite(greenLed, LOW);
      digitalWrite(blueLed, LOW);
      digitalWrite(buzzer, LOW);
     }
    }
    else{
      
    }
  }
}
