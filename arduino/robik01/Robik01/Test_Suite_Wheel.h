/******************************************************/
/*           Initialisation de la voiture             */
/******************************************************/
  
  void test_left_right_wheel_goes_forward()
  {
    
    Serial.println("début: test_left_right_wheel_goes_forward! ");   
    digitalWrite(IN1,HIGH);      
    digitalWrite(IN2,LOW);         // left wheel goes forward
    digitalWrite(IN3,LOW);      
    digitalWrite(IN4,HIGH);         // right wheel goes forward
    delay(500);  
    
    Serial.println("début: test_left_right_wheel_goes_forward! ");    
  }


  void test_left_right_wheel_goes_back()
  {
    
    Serial.println("début: test_left_right_wheel_goes_back! ");   
     
    digitalWrite(IN1,LOW);      
    digitalWrite(IN2,HIGH);         // left wheel goes forward
    digitalWrite(IN3,HIGH);      
    digitalWrite(IN4,LOW);       // right wheel goes forward
    delay(500);  
    
    Serial.println("fin: test_left_right_wheel_goes_back! ");    
  }

  void test_all (){
    
AvanceEnLigneDroite(); // ok
delay(500);
Arret(); //ok
delay(500);
DemiTour();
delay(500);
ReculeEnLigneDroite();
delay(500);
PivoteADroite();
delay(500);
PivoteAGauche();
delay(500);
  
  }
