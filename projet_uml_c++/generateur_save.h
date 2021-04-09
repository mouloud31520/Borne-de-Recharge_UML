#ifndef GENERATEUR_SAVE_H
#define GENERATEUR_SAVE_H


/*!
* \file generateur_save.h
* \brief Gestion du generateur save
* \author ZIANE Mouloud  & JACQUET Prince
* \version 1
*/

#include <donnees_borne.h>
#include <memoire_borne.h>
#include <unistd.h>
#include "bouton.h"

/*!
namespace std
*/
using namespace std;

/*! \class ganerateur_save
* \brief classe representant le generateur save
*
* La classe gere le generateur et la machine a etat
*/

class generateur_save
{
entrees *io;  /* structeur de memoire partagee pour communiquer avec le simulateur */

int shmid;

bouton B;   /*objet de la classe bouton*/

 public:
 
 /*!
* \brief Constructeur
*
* Constructeur de la classe generateur_save
*
*/
 generateur_save();


/*!
* \brief gestion de la machine a etat fini
*
* Methode qui permet de gerer la machine a etat
* represantante la charge de la batterie
*
*
*/
 void mef(); 
 
/*!
* \brief obtention de la valeur de la tension
*
* Methode qui retourne la tension sur le fil pilote
*
*
*/ 
float tension(); 

/*!
* \brief lancemment de la MEF
*
* Methode qui lance la charge de la batterie
*
*
*/
void charger();

/*!
* \brief ouvertur du contacteur AC
*
* Methode qui permet d'ouvrir le contacteur AC
*
*
*/
void ouvrir_AC();

/*!
* \brief fermeture du contacteur AC
*
* Methode qui permet de fermer le contacteur AC
*
*
*/
void fermer_AC();

/*!
* \brief deconecter le vehicule de la prise
*
* Methode qui permet d'allumer la led de la trappe
* et d'etteindre celle de la charge comme signe 
* de deconection du vehicule
*
*/
void deconnecter();

/*!
* \brief generateur de PWM
*
* Methode qui permet de controller la tension
* de commande 
*
*/
void generer_pwm(pwm type);
};


#endif //GENERATEUR_SAVE_H
