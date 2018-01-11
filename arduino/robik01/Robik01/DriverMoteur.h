/*************************************************************/
/*   Fonction qui fait avancer la voiture en ligne droite    */
/*   version adapté par Omar GUEMMI                          */
/*************************************************************/
void AvanceEnLigneDroite()
{
  
  // stope les 2moteurs
  analogWrite(ENA,vitesseDesMoteursPourArreter);
  analogWrite(ENB,vitesseDesMoteursPourArreter);           
 
  digitalWrite(IN1,HIGH);      
  digitalWrite(IN2,LOW);         // left wheel goes forward
  digitalWrite(IN3,LOW);      
  digitalWrite(IN4,HIGH);         // right wheel goes forward
  
  laVoitureEstAlArret = false;   
  
  // démarrer les 2moteurs
  analogWrite(ENA,vitesseDesMoteursPourAvancerENLigneDroite);
  analogWrite(ENB,vitesseDesMoteursPourAvancerENLigneDroite);
  Serial.println("go forward!");
}

/*************************************************************/
/*   Fonction qui fait reculer la voiture en ligne droite    */
/*   version adapté par Omar GUEMMI                          */
/*************************************************************/
void ReculeEnLigneDroite()
{
  
  // stope les 2moteurs
  analogWrite(ENA,vitesseDesMoteursPourArreter);
  analogWrite(ENB,vitesseDesMoteursPourArreter);           
  
  digitalWrite(IN1,LOW);      
  digitalWrite(IN2,HIGH);         // left wheel goes backward
  digitalWrite(IN3,HIGH);      
  digitalWrite(IN4,LOW);          // right wheel goes backward
  laVoitureEstAlArret = false;   

 // avancer les 2moteurs
  analogWrite(ENA,vitesseDesMoteursPourAvancer);
  analogWrite(ENB,vitesseDesMoteursPourAvancer);
  
// allumeLEDVerte(); 
  Serial.println("go backward!");
}


/*************************************************/
/*       Fonction qui stoppe la voiture          */
/*       version adapté par Omar GUEMMI          */
/*************************************************/
void Arret()
{
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);  
 
  // stope les 2moteurs
  analogWrite(ENA,vitesseDesMoteursPourArreter);
  analogWrite(ENB,vitesseDesMoteursPourArreter);           
  
  laVoitureEstAlArret = true;  
  Serial.print("laVoitureEstAlArret: "); Serial.println(laVoitureEstAlArret);
//  allumeLEDOrange(); 
}


/******************************************************/
/*   Fonction qui fait pivoter la voiture à droite    */
/*       version adapté par Omar GUEMMI                */
/******************************************************/
void PivoteADroite()
{

  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);  
 
 // avancer les 2moteurs
  analogWrite(ENA,vitesseDesMoteursPourAvancer);
  analogWrite(ENB,vitesseDesMoteursPourAvancer);           
  
  delay(dureePourPivoter);
  
  // stope les 2moteurs
  analogWrite(ENA,vitesseDesMoteursPourArreter);
  analogWrite(ENB,vitesseDesMoteursPourArreter);           
  
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);  

  laVoitureEstAlArret = true;  
  
//  allumeLEDOrange();
}

/******************************************************/
/*   Fonction qui fait pivoter la voiture à gauche    */
/*       version adapté par Omar GUEMMI               */
/******************************************************/
void PivoteAGauche()
{

  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW); 
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);  

 // avancer les 2moteurs
  analogWrite(ENA,vitesseDesMoteursPourAvancer);
  analogWrite(ENB,vitesseDesMoteursPourAvancer);           
  
  delay(dureePourPivoter);
  
  // stope les 2moteurs
  analogWrite(ENA,vitesseDesMoteursPourArreter);
  analogWrite(ENB,vitesseDesMoteursPourArreter);           
  
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);   
 
  
  laVoitureEstAlArret = true;  
  
//  allumeLEDOrange();
}

/******************************************************/
/*      Fonction qui fait faire un demi-tour          */
/*       version adapté par Omar GUEMMI               */
/******************************************************/
void DemiTour()
{

  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW); 
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);  

 // avancer les 2moteurs
  analogWrite(ENA,vitesseDesMoteursPourAvancer);
  analogWrite(ENB,vitesseDesMoteursPourAvancer);           
  
  delay(dureeDunDemiTour);
  
  // stope les 2moteurs
  analogWrite(ENA,vitesseDesMoteursPourArreter);
  analogWrite(ENB,vitesseDesMoteursPourArreter);           
  
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);   
 
  
  laVoitureEstAlArret = false;  
  
//  allumeLEDOrange();
}
