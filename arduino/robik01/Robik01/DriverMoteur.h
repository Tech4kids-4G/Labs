/*************************************************************/
/*   Fonction qui fait avancer la voiture en ligne droite    */
/*   version adapté par Omar GUEMMI                          */
/*************************************************************/
void AvanceEnLigneDroite()
{
  digitalWrite(IN1,HIGH);      
  digitalWrite(IN2,LOW);         // left wheel goes forward
  digitalWrite(IN3,LOW);      
  digitalWrite(IN4,HIGH);         // right wheel goes forward
  laVoitureEstAlArret = false;   
// allumeLEDVerte(); 
  Serial.println("go forward!");
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
 
  digitalWrite(ENA,LOW);
  digitalWrite(ENB,LOW);
  
  laVoitureEstAlArret = true;  
  Serial.print("laVoitureEstAlArret: "); Serial.println(laVoitureEstAlArret);
//  allumeLEDOrange(); 
}

/******************************************************/
/*   Fonction qui fait pivoter la voiture à gauche    */
/*       version adapté par Omar GUEMMI                */
/******************************************************/
void PivoteAGauche()
{

  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);  
 
  digitalWrite(ENA,HIGH);
  digitalWrite(ENB,HIGH);
  
  delay(dureePourPivoter);
  
  digitalWrite(ENA,LOW);
  digitalWrite(ENB,LOW);
  
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);  

  laVoitureEstAlArret = true;  
  
//  allumeLEDOrange();
}

/******************************************************/
/*   Fonction qui fait pivoter la voiture à droite    */
/*       version adapté par Omar GUEMMI               */
/******************************************************/
void PivoteADroite()
{

  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH); 
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);  

  
  delay(dureePourPivoter);
  
  digitalWrite(ENA,LOW);
  digitalWrite(ENB,LOW);
  
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

  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);  

  digitalWrite(ENA,HIGH);
  digitalWrite(ENB,HIGH);
  
  delay(dureeDunDemiTour);
  
  digitalWrite(ENA,LOW);
  digitalWrite(ENB,LOW);
  
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);  

  
  laVoitureEstAlArret = true;  
  
//  allumeLEDRouge();
}
