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
  Serial.println("setup : Fin initiatiosation! ");
} 

void init_variables(){
  rightDistance = 0;
  leftDistance = 0;
  middleDistance = 0;
  distance = 0 ;
  right45=0;
  left45=0;
//  Serial.print("initiatiosation des variables middleDistance, right45, left45, distance, rightDistance, leftDistance  : ");
//  Serial.print(middleDistance);Serial.print(" , "); 
//  Serial.print(right45);Serial.print(" , "); 
//  Serial.print(left45); Serial.print(" , ");
//  Serial.print(distance);Serial.print(" , ");
//  Serial.print(rightDistance);Serial.print(" , ");
//  Serial.println(leftDistance);
}


void getMiddleDistance(){
  Serial.println("Le calcule de la distance en position 90° est cours....  ");
  myservo.write(90);//setservo position according to scaled value
  delay(100);
  for(i=0; i <= 2; ++i) {
      middleDistance += Distance_test();
      delay(50); 
    }
  int_printfln(middleDistance /= i, "La ditance mésurée en position 90° (MiddleDistance) cm: ");
}

void getRightDistance(){
  Serial.println("Le calcule de la distance en position 0° est cours....  ");
  myservo.write(0);//setservo position according to scaled value
  delay(100);
  for(i=0; i <= 1; ++i) {
      rightDistance += Distance_test();
      delay(50); 
    }
  int_printfln(rightDistance /= i, "La ditance mésurée en position 0° (Right) cm: ");
}
void getRight45Distance(){
  Serial.println("Le calcule de la distance en position 45° est cours....  ");
  myservo.write(45);//setservo position according to scaled value
  delay(100);
  for(i=0; i <= 1; ++i) {
      right45 += Distance_test();
      delay(50); 
    }
  int_printfln(right45 /= i, "La ditance mésurée en position 45° (Right45) cm : ");
}

void getLeft45Distance(){
  Serial.println("Le calcule de la distance en position 135° est cours....  ");
  myservo.write(135);//setservo position according to scaled value
  delay(100);
  for(i=0; i <= 1; ++i) {
      left45 += Distance_test();
      delay(50); 
    }
  int_printfln(left45 /= i,"La ditance mésurée en position 135° (Left45) cm : ");
}
void getLeftDistance(){
  Serial.println("Le calcule de la distance en position 180° est cours....  ");
  myservo.write(180);//setservo position according to scaled value
  delay(100);
  for(i=0; i <= 1; ++i) {
      leftDistance += Distance_test();
      delay(50); 
    }
  int_printfln(leftDistance /= i,"La ditance mésurée en position 180° (Left) cm : ");
}

void setServo90(){
  Serial.println("\nRetour à la position initial du servo 90° ");
  myservo.write(90);//setservo position according to scaled value
}

void sort(int a[], int size){
  
//  for(int k=0 ; k<5;k++){
//     Serial.print("\n vant la boucle value : "); Serial.println(a[k]); 
//    }
    
  for(int s=0 ; s<(size-1);s++){
    for(int t=0 ; t<(size-(s+1));t++){
      if(a[t] > a[t+1]){
        int l = a[t];
        a[t] = a[t+1];
        a[t+1] = l;
        }
      } 
    }
//   for(int k=0 ; k<5;k++){
//     Serial.print("\n value : "); Serial.println(a[k]); 
//    }
   Serial.print("\nMIN value : "); Serial.print(a[0]); 
   Serial.print("\nMAX value : "); Serial.println(a[4]); 
}

void sortWithIndex(int a[],char c[], int size){
     
  for(int s=0 ; s<(size-1);s++){
    for(int t=0 ; t<(size-(s+1));t++){
      if(a[t] > a[t+1]){
        int l = a[t];
        char dc = c[t];
        a[t] = a[t+1];
        c[t] = c[t+1];
        a[t+1] = l;
        c[t+1] = dc;
        }
      } 
    }

   Serial.print("\nMIN value : "); Serial.print(a[0]); Serial.print("direction : "); Serial.print(c[0]);
   Serial.print("\nMAX value : "); Serial.print(a[4]); ; Serial.print("direction : "); Serial.println(c[4]);
}

char getDirection(int a[],char c[], int size){
  sortWithIndex(a,c,size);
  return c[4];
}

void alog2()
{

  init_variables();
  Serial.println("###################   DEBUT  pour une nouvelle mesure ############################################# ");   
  getMiddleDistance();
  getRight45Distance();
  getRightDistance();   
  getLeft45Distance();
  getLeftDistance();
  setServo90();
  int distances[5] = {rightDistance, right45, middleDistance, left45, leftDistance};
  char orientation[5] = {'r', 's', 'm', 'n','l'};
  char way = getDirection(distances,orientation,5);
  
  if (way == 'm') { _mForward(); delay(100);}
  else if (way == 'r' || way == 's'){
    Serial.println("Je tourne a droite");
    _mStop();
    delay(100);
    _mBack();
    delay(500);
    _mright();
    delay(500);
    _mForward();   
    } else if (way == 'n' || way == 'l'){
    Serial.println("Je tourne a gauche");
    _mStop();
    delay(100);
    _mBack();
    delay(500);
    _mleft();
    delay(500);
    _mForward();   
    }
   
  }

void loop() 
{ 
alog2 ();
                
}



