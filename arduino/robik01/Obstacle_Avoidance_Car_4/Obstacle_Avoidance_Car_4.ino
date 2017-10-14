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
  digitalWrite(Trig, LOW);   
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);  
  delayMicroseconds(20);
  digitalWrite(Trig, LOW);   
  float Fdistance = pulseIn(Echo, HIGH);  
  //Fdistance= Fdistance/58; 
  float distance_cm = Fdistance / 2.0 * SOUND_SPEED / 10 ;   
  Serial.print("Distance in cm=");
  Serial.println(distance_cm);   
  return (int)distance_cm;
}  

void setup() 
{ 
  myservo.attach(3);// attach servo on pin 3 to servo object
 
  Serial.begin(9600);     
  pinMode(Echo, INPUT);    
  pinMode(Trig, OUTPUT);  
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
  _mStop();
   // OGM---------------------
     Serial.print(" premiere fois middleDistance : ");
     Serial.println(middleDistance);
     //----------------

} 

void alog2(){

rightDistance = 0;
leftDistance = 0;
middleDistance = 0;
distance = 0 ;
right45=0;
left45=0;

 Serial.print("initiatiosation des variables middleDistance, right45, left45  : ");
 Serial.print(middleDistance);  Serial.print(" , "); Serial.print(right45);Serial.print(" , "); Serial.println(left45);
  Serial.println("###################   DEBUT  pour une nouvelle mesure ############################################# ");
  _mStop();
    myservo.write(90);//setservo position according to scaled value
    delay(100); 
    for(i=0; i <= 4; ++i) {
      middleDistance += Distance_test();
     // OGM---------------------
     Serial.print("middleDistance ++ : ");
     Serial.println(middleDistance);
     //----------------
      delay(50); 
    }
    // OGM--------------------------------
    Serial.print("la valeur de i apres 90 = ");
    Serial.println(i);
    //------------------------------------
    middleDistance /= i; // middleDistance = middleDistance / i
    Serial.print("middleDistance=");
    Serial.println(middleDistance);
    
    myservo.write(45);//setservo position according to scaled value
    delay(300); 
    for(i=0; i <= 3; ++i) {
      right45 += Distance_test();
       // OGM---------------------
     Serial.print("right45 ++ : ");
     Serial.println(right45);
     //----------------
      delay(100); 
    }
    
     // OGM--------------------------------
    Serial.print("la valeur de i  aprea right45 = ");
    Serial.println(i);
    //------------------------------------
    right45 /= i;
    Serial.print("la distance à right45= ");
    Serial.println(right45);

    myservo.write(135);//setservo position according to scaled value
    delay(300); 
    for(i=0; i <= 3; ++i) {
      left45 += Distance_test();
     // OGM---------------------
     Serial.print("left45 ++ : ");
     Serial.println(left45);
     //----------------
      delay(100); 
    }
      // OGM--------------------------------
    Serial.print("la valeur de i  aprea left45 = ");
    Serial.println(i);
    //------------------------------------
    left45 /= i;
    Serial.print("la distance à  left45= ");
    Serial.println(left45);

    
      // OGM--------------------------------
    Serial.println("retour à la position initial du servo 90° ");
     //------------------------------------
    myservo.write(90);//setservo position according to scaled value

    if(middleDistance<=50 || right45<=50 || left45<=50)
    {     
      _mStop();
      delay(300);                         
      _mBack();
      delay(300);
      _mStop();
      delay(500);                         
      myservo.write(5);          
      delay(150); //avant 100     
      // OGM--------------------------------
      Serial.print("distance des 3 mésures: middleDistance,right45,left45 : ");
      Serial.print(middleDistance);  Serial.print(" , "); Serial.print(right45);Serial.print(" , "); Serial.println(left45);
      Serial.println(" le servo est 5°");
    //------------------------------------
      for(i=0; i <= 3; ++i) {
        rightDistance += Distance_test();
        delay(150); // avant 100
      }
      rightDistance /= i;
      Serial.print("rightDistance à 5° =");
      Serial.println(rightDistance);
      delay(100);                                                  
      myservo.write(180);  
       // OGM--------------------------------
      Serial.print("distance des 3 mésures: middleDistance,right45,left45 : ");
      Serial.print(middleDistance);  Serial.print(" , "); Serial.print(right45);Serial.print(" , "); Serial.println(left45);
      Serial.println(" le servo est 180°");
    //------------------------------------            
      delay(150); // avant 100
      for(i=0; i <= 3; ++i) {
        leftDistance += Distance_test();
        delay(150); 
      }
      leftDistance /= i;
      Serial.print("leftDistance=");
      Serial.println(leftDistance);

      
      myservo.write(90);    
      Serial.println("retour à la position 90° décision en cour si :  rightDistance > leftDistance ");
      Serial.print("rightDistance = ");  Serial.println (rightDistance);
      Serial.print("leftDistance = ");  Serial.println (leftDistance);            
      if(rightDistance>leftDistance)  
      {
        _mright();
        delay(150);
        Serial.println("###################   FIN  _mright ############################################# ");
       }
       else if(rightDistance<leftDistance)
       {
        _mleft();
        delay(100);
         Serial.println("###################   FIN  _mleft ############################################# ");
       }
       else if((rightDistance<=30)||(leftDistance<=30))
       {
        _mBack();
        delay(500);
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
        delay(500);
                  
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



