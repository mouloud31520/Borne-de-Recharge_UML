#ifndef BOUTON_H
#define BOUTON_H

/*!
* \file bouton.h
* \brief Detection des appuit sur les boutons
* \author ZIANE Mouloud  & JACQUET Prince
* \version 1
*/

#include <donnees_borne.h>
#include <memoire_borne.h>

/*! namespace std
*/
using namespace std;

/*! \class bouton
* \brief classe representant les boutons
*
* La classe gere les boutons de la borne de  recharge
*/

class bouton
{

entrees *io;   /* structeur de memoire partagee pour communiquer avec le simulateur */

int shmid;

int bout;

public:

/*!
* \brief Constructeur
*
* Constructeur de la classe bouton
*
*/
bouton();

/*!
* \brief appui sur stop
*
* Methode qui permet de détécter un appui
* sur le bouton stop
*
*/
int stop();

/*!
* \brief appui sur charge
*
* Methode qui permet de détécter un appui
* sur le bouton charge
*
*/
int charge();



};

#endif //BOUTON_H
