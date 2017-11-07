/**********************************/
/*   Déclarations des variables   */
/**********************************/
int     distanceMesuree         = 0;      // Variable qui stockera la distance mesurée
boolean laVoitureEstAlArret     = true;   // Variable qui retient si la voiture est à l'arrêt



int   rightDistance             = 0;
int   leftDistance              = 0;
int   middleDistance            = 0; 
int   distance                  = 0;
int   right45                   = 0; 
int   left45                    = 0;
int   i;

/* Constantes pour le timeout */
const unsigned long MEASURE_TIMEOUT = 25000UL; // 25ms = ~8m ÃƒÂ  340m/s

/* Vitesse du son dans l'air en mm/us */
const float SOUND_SPEED = 340.0 / 1000;
