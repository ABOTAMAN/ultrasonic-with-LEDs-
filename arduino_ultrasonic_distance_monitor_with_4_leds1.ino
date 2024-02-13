
int led1=6;
int led2=9;
int led3=10;
int led4=11;

int trig=7;
int echo=8;

long t=0;
long d=0;


void setup(){
 Serial.begin(9600);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(trig,OUTPUT);
  pinMode(echo, INPUT);
 
}

void loop()
{
  digitalWrite(trig,LOW);
  delayMicroseconds(2); 
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  
  t=pulseIn(echo,HIGH);
  d=0.0343*(t/2);
  Serial.println(d);
  
  if(d>250){
    
    analogWrite(led4,map(d,250,335,0,255));
  }
  else{
  analogWrite(led4,0);
}
    if(d>200){
    
    analogWrite(led3,map(d,200,250,0,255));
  }
  else{
  analogWrite(led3,0);
}
   
  if(d>100){
    
    analogWrite(led2,map(d,100,200,0,255));
  }
   else{
  analogWrite(led2,0);
}

  if(d>5){
    
    analogWrite(led1,map(d,5,100,0,255));
  }
  
  else{
  analogWrite(led1,0);
}
  


  
}