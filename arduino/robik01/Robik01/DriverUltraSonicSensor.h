/**********************************************/
/*  Fonction qui détecte si la voie est libre */
/*                                            */
/*  Retourne True si la voie est libre        */
/*  Retourne False s'il y a un obstacle       */
/**********************************************/
boolean LaVoieEstLibre()
{
  digitalWrite(DOUT_ULTRASONIC_TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(DOUT_ULTRASONIC_TRIG, HIGH);
  delayMicroseconds(20);
  digitalWrite(DOUT_ULTRASONIC_TRIG, LOW);
  
  distanceMesuree = pulseIn(DIN_ULTRASONIC_ECHO, HIGH) / 58;  
  Serial.print("distanceMesuree : "); Serial.println(distanceMesuree);
  Serial.print("seuilDistance : "); Serial.println(seuilDistance);
  Serial.print("resultat du calcule : "); Serial.println(seuilDistance < distanceMesuree);

  if(seuilDistance < distanceMesuree)  
  {return true;}
  else
  {return false;}   
}
