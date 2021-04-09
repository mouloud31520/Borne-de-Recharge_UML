#ifndef VOYANTS_H
#define VOYANTS_H

/*!
* \file voyants.h
* \brief Gestion d'allumage des voyants
* \author ZIANE Mouloud  & JACQUET Prince
* \version 1
*/

#include <donnees_borne.h>
#include <memoire_borne.h>

/*! namespace std
*/
using namespace std;

/*! \class voyants
* \brief classe representant les voyants
*
* La classe gere les voyants
*/

class voyants
{

entrees *io; /* structeur de memoire partagee pour communiquer avec le simulateur */
int shmid;

public:

/*!
* \brief Constructeur
*
* Constructeur de la classe voyants
*
*/
voyants();

/*!
* \brief clignotement de la led charge
*
* Methode qui permet de faire clignoter
*la led charge en rouge
*
*
*/
void blink_chargeR();

/*!
* \brief allumge de la led dispo
*
* Methode qui permet d'allumer 
*la led dispo en vert
*
*
*/
void set_dispo();

/*!
* \brief clignotement de la led charge
*
* Methode qui permet de faire clignoter
*la led charge en vert
*
*
*/
void blink_charge();

/*!
* \brief allumge de la led charge
*
* Methode qui permet d'allumer 
*la led charge en vert
*
*
*/
 void set_charge();

};



#endif //VOYANTS_H
