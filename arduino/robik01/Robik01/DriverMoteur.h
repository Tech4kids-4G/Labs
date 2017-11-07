/*************************************************************/
/*   Fonction qui fait avancer la voiture en ligne droite    */
/*   version adapté par Omar GUEMMI                          */
/*************************************************************/
void AvanceEnLigneDroite()
{
 
  digitalWrite(D0UT_MOTEUR_DROIT_1,HIGH);
  digitalWrite(D0UT_MOTEUR_DROIT_2,LOW);
  digitalWrite(D0UT_MOTEUR_GAUCHE_3,LOW);
  digitalWrite(D0UT_MOTEUR_GAUCHE_4,HIGH);  
 
 delay(500);
  
  laVoitureEstAlArret = false;   

  allumeLEDVerte(); 

  Serial.println("go forward!");
}

/*************************************************/
/*       Fonction qui stoppe la voiture          */
/*       version adapté par Omar GUEMMI          */
/*************************************************/
void Arret()
{
  digitalWrite(D0UT_MOTEUR_DROIT_1,LOW);
  digitalWrite(D0UT_MOTEUR_DROIT_2,LOW);
  digitalWrite(D0UT_MOTEUR_GAUCHE_3,LOW);
  digitalWrite(D0UT_MOTEUR_GAUCHE_4,LOW);  
 
  digitalWrite(DOUT_MOTEUR_ENA,LOW);
  digitalWrite(DOUT_MOTEUR_ENB,LOW);
  
  laVoitureEstAlArret = true;  
 
  allumeLEDOrange(); 
}

/******************************************************/
/*   Fonction qui fait pivoter la voiture à gauche    */
/*       version adapté par Omar GUEMMI                */
/******************************************************/
void PivoteAGauche()
{

  digitalWrite(D0UT_MOTEUR_DROIT_1,HIGH);
  digitalWrite(D0UT_MOTEUR_DROIT_2,LOW);
  digitalWrite(D0UT_MOTEUR_GAUCHE_3,LOW);
  digitalWrite(D0UT_MOTEUR_GAUCHE_4,HIGH);  
 
  digitalWrite(DOUT_MOTEUR_ENA,HIGH);
  digitalWrite(DOUT_MOTEUR_ENB,HIGH);
  
  delay(dureePourPivoter);
  
  digitalWrite(DOUT_MOTEUR_ENA,LOW);
  digitalWrite(DOUT_MOTEUR_ENB,LOW);
  
  digitalWrite(D0UT_MOTEUR_DROIT_1,LOW);
  digitalWrite(D0UT_MOTEUR_DROIT_2,LOW);
  digitalWrite(D0UT_MOTEUR_GAUCHE_3,LOW);
  digitalWrite(D0UT_MOTEUR_GAUCHE_4,LOW);  

  laVoitureEstAlArret = true;  
  
  allumeLEDOrange();
}

/******************************************************/
/*   Fonction qui fait pivoter la voiture à droite    */
/*       version adapté par Omar GUEMMI               */
/******************************************************/
void PivoteADroite()
{

  digitalWrite(D0UT_MOTEUR_DROIT_1,LOW);
  digitalWrite(D0UT_MOTEUR_DROIT_2,HIGH); 
  digitalWrite(D0UT_MOTEUR_GAUCHE_3,HIGH);
  digitalWrite(D0UT_MOTEUR_GAUCHE_4,LOW);  

  
  delay(dureePourPivoter);
  
  digitalWrite(DOUT_MOTEUR_ENA,LOW);
  digitalWrite(DOUT_MOTEUR_ENB,LOW);
  
  digitalWrite(D0UT_MOTEUR_GAUCHE_3,LOW);
  digitalWrite(D0UT_MOTEUR_GAUCHE_4,LOW);  
 
  
  laVoitureEstAlArret = true;  
  
  allumeLEDOrange();
}

/******************************************************/
/*      Fonction qui fait faire un demi-tour          */
/*       version adapté par Omar GUEMMI               */
/******************************************************/
void DemiTour()
{

  digitalWrite(D0UT_MOTEUR_DROIT_1,LOW);
  digitalWrite(D0UT_MOTEUR_DROIT_2,HIGH);
  
  digitalWrite(D0UT_MOTEUR_GAUCHE_3,HIGH);
  digitalWrite(D0UT_MOTEUR_GAUCHE_4,LOW);  

  digitalWrite(DOUT_MOTEUR_ENA,HIGH);
  digitalWrite(DOUT_MOTEUR_ENB,HIGH);
  
  delay(dureeDunDemiTour);
  
  digitalWrite(DOUT_MOTEUR_ENA,LOW);
  digitalWrite(DOUT_MOTEUR_ENB,LOW);
  
  digitalWrite(D0UT_MOTEUR_DROIT_1,LOW);
  digitalWrite(D0UT_MOTEUR_DROIT_2,LOW);
  
  digitalWrite(D0UT_MOTEUR_GAUCHE_3,LOW);
  digitalWrite(D0UT_MOTEUR_GAUCHE_4,LOW);  

  
  laVoitureEstAlArret = true;  
  
  allumeLEDRouge();
}
