#include <Servo.h>  //servo library
Servo myservo;      // create servo object to control servo

int Echo = A4;  
int Trig = A5; 
int middle = 0; 
#define ENA 5
#define ENB 6
#define IN1 7
#define IN2 8
#define IN3 9
#define IN4 11
#define carSpeed 110
#define Green 13
#define Red 11
#define Blue 10
#define Reed A3
int rightDistance = 0, leftDistance = 0, middleDistance = 0;
int distance;
int sameDistance [9999];
void lightOn (){
 digitalWrite(Blue,HIGH);
 digitalWrite(Green,HIGH);
 digitalWrite(Red, HIGH);
}
void lightOff() {
   digitalWrite(Blue,LOW);
 digitalWrite(Green,LOW);
 digitalWrite(Red,LOW);
}
void forward(){ 
  analogWrite(ENA, carSpeed);
  analogWrite(ENB, carSpeed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  Serial.println("Forward");
}

void back() {
  analogWrite(ENA, carSpeed);
  analogWrite(ENB, carSpeed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  Serial.println("Back");
}

void left (){
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  Serial.println("Left");
}

void right() {
   digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  Serial.println("Left");
}

void stop() {
  digitalWrite(ENA, LOW);
  digitalWrite(ENB, LOW);
  Serial.println("Stop!");
} 
int Distance_test() {
  digitalWrite(Trig, LOW);   
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);  
  delayMicroseconds(40);
  digitalWrite(Trig, LOW);   
  float Fdistance = pulseIn(Echo, HIGH);  
  Fdistance= Fdistance / 58;       
  return (int)Fdistance;
}   
void setup() { 
  myservo.attach(3);  
  Serial.begin(9600);     
  pinMode(Echo, INPUT);    
  pinMode(Trig, OUTPUT);  
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  stop();
} 
void loop() { 
  forward();
  for(int i=175;i>20;i--)
  {
    myservo.write(i);
    delay(5);
    distance=Distance_test();
    Serial.println(distance);
    int same [3];
      if ( i == 90) {
        middle= middle + 1;
        same[middle] = distance;
        Serial.println(middle);
        Serial.println(same[middle]);
        if (middle > 3 ) {
          middle = 0;
             if ( same[1] == same [2]){     
        back(); 
        delay(500);
        left();
        delay(180);
      }
        }
      }
   
    int x;
    int y;
    if ( distance < 20){
      if (i >90){
        x = i-90;
        right();
        delay(50+(x*5));
        stop();
        
      }else if ( i <90) {
        
        y = 90-i;
        left();
        delay (50 + (y*5));
        stop();
      
      }
    
      }
    }}    
  
