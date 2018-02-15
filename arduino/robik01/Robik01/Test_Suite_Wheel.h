/******************************************************/
/*           Initialisation de la voiture             */
/******************************************************/
  

  void test_Robit001()
  {    
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
