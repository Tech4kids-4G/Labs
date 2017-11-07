/******************************************************/
/*           Initialisation de la voiture             */
/******************************************************/
  
  void Initialisation()
  {
    Serial.println("setup : début initiatiosation! ");    
    Serial.begin(9600);     
    
    pinMode(DIN_ULTRASONIC_ECHO, INPUT);    
    pinMode(DOUT_ULTRASONIC_TRIG, OUTPUT);
    digitalWrite(DOUT_ULTRASONIC_TRIG, LOW);
    
    pinMode(D0UT_MOTEUR_DROIT_1,OUTPUT);
    pinMode(D0UT_MOTEUR_DROIT_2,OUTPUT);
    pinMode(D0UT_MOTEUR_GAUCHE_3,OUTPUT);
    pinMode(D0UT_MOTEUR_GAUCHE_4,OUTPUT);
    pinMode(DOUT_MOTEUR_ENA,OUTPUT);
    pinMode(DOUT_MOTEUR_ENB,OUTPUT);

    digitalWrite(DOUT_MOTEUR_ENA,HIGH);
    digitalWrite(DOUT_MOTEUR_ENA,HIGH);
   
    
    SERVO.attach(PWM_SERVO);// attach servo on pin 3 to servo object 
    
    RegardeToutDroit();
    
    Serial.println("setup : Fin initiatiosation! ");   
  }
