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
    
    pinMode(IN1,OUTPUT);
    pinMode(IN2,OUTPUT);
    pinMode(IN3,OUTPUT);
    pinMode(IN4,OUTPUT);
    pinMode(ENA,OUTPUT);
    pinMode(ENB,OUTPUT);
    digitalWrite(ENA,HIGH);  
    digitalWrite(ENB,HIGH);   
    SERVO.attach(PWM_SERVO);// attach servo on pin 3 to servo object   
    RegardeToutDroit();
    Serial.println("setup : Fin initiatiosation! ");   
  }
