const int trigR = 7;
const int echoR = 6;
const int trigL = 5;
const int echoL = 4;

int motR1 = 8;
int motR2 = 9;
int motR3 = 10;

int motL1 = 13;
int motL2 = 12;
int motL3 = 11;

long duration;
char data;
String SerialData = "";

void setup() {
  // put your setup code here, to run once:
  pinMode(motR1,OUTPUT);
  pinMode(motR2,OUTPUT);
  pinMode(motR3,OUTPUT);

  pinMode(motL1,OUTPUT);
  pinMode(motL2,OUTPUT);
  pinMode(motL3,OUTPUT);
  
  pinMode(trigR, OUTPUT);
  pinMode(echoR,INPUT); 
  pinMode(trigL, OUTPUT);
  pinMode(echoL,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  long inchesR;
  long inchesL;
  
  theTime(trigR,echoR);
  inchesR = duration;
  theTime(trigL,echoL);
  inchesL = duration;


  //inchesR = microsecondsToInches(durationR);
  //inchesL = microsecondsToInches(durationL);
  
      Serial.print(12-inchesR);
      Serial.print("inR, ");
      Serial.print(12-inchesL);
      Serial.print("inL, ");
      Serial.println(); 
  while((12-inchesR)>=2 && (12-inchesL)<=2){
      Serial.print(12-inchesR);
      Serial.print("inR, ");
      Serial.print(12-inchesL);
      Serial.print("inL, ");
      Serial.println(); 

      
      digitalWrite(motR1,HIGH);
      digitalWrite(motR2,LOW);
      digitalWrite(motR3,HIGH);

      digitalWrite(motL3,LOW);
      digitalWrite(motL2,LOW);
      digitalWrite(motL1,LOW);
      
      theTime(trigR,echoR);
      inchesR = duration;
      theTime(trigL,echoL);
      inchesL = duration;
      delay(10);
  }
  while((12-inchesR)<=2 && (12-inchesL)>=2){
      Serial.print(12-inchesR);
      Serial.print("inR, ");
      Serial.print(12-inchesL);
      Serial.print("inL, ");
      Serial.println(); 

      
      digitalWrite(motR1,LOW);
      digitalWrite(motR2,LOW);
      digitalWrite(motR3,LOW);

      digitalWrite(motL3,HIGH);
      digitalWrite(motL2,LOW);
      digitalWrite(motL1,HIGH);
      
      theTime(trigR,echoR);
      inchesR = duration;
      theTime(trigL,echoL);
      inchesL = duration;
      delay(10);
  }
    digitalWrite(motR1,HIGH);
    digitalWrite(motR2,LOW);
    digitalWrite(motR3,HIGH);
 
    digitalWrite(motL3,HIGH);
    digitalWrite(motL2,LOW);
    digitalWrite(motL1,HIGH);
 
 
  delay(1000);
}

long microsecondsToInches(long microseconds){
  return (microseconds/74/2);
}

void theTime(int trigger, int echo){
  digitalWrite(trigger,LOW);
  delayMicroseconds(2);
  digitalWrite(trigger,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger,LOW);
  duration = microsecondsToInches(pulseIn(echo,HIGH));
  
}
