/***********************************************************************************************/
/*                        VOITURE AUTOMATISÉE ANTI-COLLISION v0.1                              */
/*                                                                                             */
/*                La voiture explore en ligne droite et évite les obstacles.                   */ 
/*                                                                                             */
/*                <!> Modifier le fichier "configuration.h" si nécessaire.<!>                  */
/*                                                                                             */
/*                                     Rev git: v1.0                                           */
/*                                                                                             */
/*                                                                                             */
/*                           le 02/11/2017 par Omar GUEMMI                                     */
/*                                                                                             */
/*                                                                                             */
/***********************************************************************************************/

/*****************************************************************/
/*                         LIBRAIRIES                            */
/*****************************************************************/
#include <Servo.h> 
#include "AffectationDesEntreesSorties.h"
#include "DeclarationDesVariables.h"
#include "Configuration.h"
#include "DriverLEDs.h"
#include "DriverMoteur.h"
#include "DriverServo.h"
#include "DriverUltraSonicSensor.h"
#include "Initialisation.h"
#include "AlgorithmeQuiChercheUneIssue.h"

/*****************************************************************/
/*                        INITIALISATION                         */
/*****************************************************************/
void setup() {Initialisation();}

/*****************************************************************/
/*                                                               */
/*                        BOUCLE INFINIE                         */
/*                Algorithme définit dans la vidéo.              */
/*                                                               */
/*****************************************************************/

void loop() {   
   RegardeToutDroit(); 
  
        AvanceEnLigneDroite();
}

//void loop() {   
//   RegardeToutDroit(); 
//   if(LaVoieEstLibre())
//   {
//     RegardeAGauche();      
//     if(LaVoieEstLibre()) 
//     { 
//       RegardeToutDroit();       
//       if(LaVoieEstLibre()) 
//       {
//         RegardeADroite();          
//         if(LaVoieEstLibre()) 
//         {
//           if(laVoitureEstAlArret)
//           {AvanceEnLigneDroite();}
//         }
//         else{ChercheUneIssue();}
//       }
//       else{ChercheUneIssue();}
//     }     
//     else{ChercheUneIssue();} 
//   }  
//   else{ChercheUneIssue();} 
//   delay(1);
//}
