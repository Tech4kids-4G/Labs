//www.elegoo.com
//2016.09.23

#include <Servo.h> //servo library
Servo myservo; // create servo object to control servo
int Echo = A4;  
int Trig = A5; 
int in1 = 6;
int in2 = 7;
int in3 = 8;
int in4 = 9;
int ENA = 5;
int ENB = 11;
int ABS = 150;
int rightDistance = 0,leftDistance = 0,middleDistance = 0, distance = 0 , right45=0, left45=0;
int i;

/* Constantes pour le timeout */
const unsigned long MEASURE_TIMEOUT = 25000UL; // 25ms = ~8m ÃƒÂ  340m/s

/* Vitesse du son dans l'air en mm/us */
const float SOUND_SPEED = 340.0 / 1000;



void _mForward()
{
 analogWrite(ENA,ABS);
 analogWrite(ENB,ABS);
 digitalWrite(in1,LOW);//digital output
  digitalWrite(in2,HIGH);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
 Serial.println("go forward!");
}

void _mBack()
{
 analogWrite(ENA,ABS);
 analogWrite(ENB,ABS);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
 Serial.println("go back!");
}

void _mleft()
{
 analogWrite(ENA,ABS);
 analogWrite(ENB,ABS);
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH); 
 Serial.println("go left!");
}

void _mright()
{
 analogWrite(ENA,ABS);
 analogWrite(ENB,ABS);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
 Serial.println("go right!");
} 
void _mStop()
{
  digitalWrite(ENA,LOW);
  digitalWrite(ENB,LOW);
  Serial.println("Stop!");
} 
 /*Ultrasonic distance measurement Sub function*/
int Distance_test()   
{

  /* 1. Lance une mesure de distance en envoyant une impulsion HIGH de 10µs sur la broche TRIGGER */
  digitalWrite(Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);
  /* 2. Mesure le temps entre l'envoi de l'impulsion ultrasonique et son écho (si il existe) */
  long measure = pulseIn(Echo, HIGH, MEASURE_TIMEOUT);
  /* 3. Calcul la distance à partir du temps mesuré */
  float distance_mm = measure / 2.0 * SOUND_SPEED;
  int_printfln(distance_mm / 10,"Distance in cm = "); 
  delay(500);
  return (int)distance_mm / 10;

}  

// print int value with message
void int_printfln(int value, String message){
  Serial.print("int_printfln -- > " + message + " ");
  Serial.println(value);   
}

// print string value with message
void int_printfln(String value, String message){
  Serial.print("string_printfln -- > " + message + " ");
  Serial.println(value);   
}
void setup() 
{ 
  myservo.attach(3);// attach servo on pin 3 to servo object 
  Serial.begin(9600);     
  pinMode(Echo, INPUT);    
  pinMode(Trig, OUTPUT);
  digitalWrite(Trig, LOW);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
  _mStop();
  int_printfln(middleDistance, "premiere fois middleDistance : ");
} 

void init_variables(){
  rightDistance = 0;
  leftDistance = 0;
  middleDistance = 0;
  distance = 0 ;
  right45=0;
  left45=0;
  Serial.print("initiatiosation des variables middleDistance, right45, left45  : ");
  Serial.print(middleDistance);  Serial.print(" , "); Serial.print(right45);Serial.print(" , "); Serial.println(left45);  
}


void getMiddleDistance(){
  myservo.write(90);//setservo position according to scaled value
  delay(100);
  for(i=0; i <= 4; ++i) {
      middleDistance += Distance_test();
      delay(50); 
    }
  int_printfln(middleDistance /= i, "MiddleDistance cm: ");
}

void getRightDistance(){
  myservo.write(10);//setservo position according to scaled value
  delay(100);
  for(i=0; i <= 3; ++i) {
      rightDistance += Distance_test();
      delay(50); 
    }
  int_printfln(rightDistance /= i, "Right distance cm: ");
}
void getRight45Distance(){
  myservo.write(45);//setservo position according to scaled value
  delay(100);
  for(i=0; i <= 3; ++i) {
      right45 += Distance_test();
      delay(50); 
    }
  int_printfln(right45 /= i, "Right45 cm: ");
}

void getLeft45Distance(){
  myservo.write(135);//setservo position according to scaled value
  delay(100);
  for(i=0; i <= 3; ++i) {
      left45 += Distance_test();
      delay(50); 
    }
  int_printfln(left45 /= i, "Left45 cm: ");
}
void getLeftDistance(){
  myservo.write(180);//setservo position according to scaled value
  delay(100);
  for(i=0; i <= 3; ++i) {
      leftDistance += Distance_test();
      delay(50); 
    }
  int_printfln(leftDistance /= i, "Left distance cm: ");
}

void setServo90(){
  Serial.println("\nRetour à la position initial du servo 90° ");
  myservo.write(90);//setservo position according to scaled value
}

void alog2()
{

 init_variables();
 Serial.println("###################   DEBUT  pour une nouvelle mesure ############################################# ");
  _mStop();
  getMiddleDistance();
  getRight45Distance();   
  getLeft45Distance();
  setServo90();
  Serial.print("\nDistance des 3 mésures: middleDistance,right45,left45 : ");
  Serial.println(middleDistance);  Serial.print(" , "); Serial.print(right45);Serial.print(" , "); Serial.println(left45);

  if(middleDistance<=50 || right45<=50 || left45<=50)
    {     
      _mStop();
      delay(50);                         
      _mBack();
      delay(100);
      getRightDistance(); // servo 10°
      delay(100);  
      getLeftDistance(); // servo 180°                                                
      delay(100); 
      setServo90();    
      Serial.println("retour à la position 90° décision en cour si :  rightDistance > leftDistance ");
      int_printfln(rightDistance, "rightDistance =");
      int_printfln(leftDistance, "leftDistance =");       
      if(rightDistance>leftDistance)  
      {
        _mright();
        delay(100);
        Serial.println("###################   FIN  _mright ############################################# ");
       }
       else if(rightDistance<leftDistance)
       {
        _mleft();
        delay(100);
        Serial.println("###################   FIN  _mleft ############################################# ");
       }
       else if((rightDistance<=50)||(leftDistance<=50))
       {
        _mBack();
        delay(100);
        Serial.println("###################   FIN  _mBack ############################################# ");
       }
       else
       {
        _mForward();
        Serial.println("###################   FIN  _mForward ############################################# ");
       }
    }  
    else
        _mForward();   
        delay(300);
                  
  }

void alogov1 (){
    middleDistance = Distance_test();
  #ifdef send
  Serial.print("middleDistance=");
  Serial.println(middleDistance);
   #endif
    
    if(middleDistance>25)
    { 
      _mForward(); //All clear, move forward!
    }
    else {  // distance middleDistance <= 25 
      _mStop(); //Object detected! Stop the robot and check left and right for the better way out!
      Serial.println("check rigtht first");
      myservo.write(10);//setservo position according to scaled value regarde à droite
      delay(1000); 
      rightDistance = Distance_test();
      //delay(1000); 
      Serial.print("rightDistance=");
      Serial.println(rightDistance);

      if (rightDistance > middleDistance){
          
         Serial.print("rightDistance >  middleDistance :");
         Serial.println(rightDistance >  middleDistance);
         Serial.println("set servo 90° go");
         myservo.write(90);//setservo position according to scaled value regarde à droite
          delay(1000);
          _mright();
           delay(1000);
          _mStop();
          _mForward();
       }
      
    }  

  }
void loop() 
{ 
alog2();
                  
}



