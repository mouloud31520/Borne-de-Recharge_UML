#ifndef TIMER_H
#define TIMER_H

/*!
* \file timer.h
* \brief Gestion du timer
* \author ZIANE Mouloud  & JACQUET Prince
* \version 1
*/

#include <unistd.h>
#include <donnees_borne.h>
#include <memoire_borne.h>
#include <iostream>

/*! namespace std 
*/
using namespace std;


/*! \class timer
* \brief classe representant le timer
*
* La classe gere le timer
*/
class timer
{
entrees *io; /* structeur de memoire partagee pour communiquer avec le simulateur */
  int shmid;
  int depart_timer;

public:

/*!
* \brief Constructeur
*
* Constructeur de la classe timer
*
*/
	timer();

/*!
* \brief initialisation du timer 
*
* Methode qui permet d'initialiser le timer 
*
*
*/
 	void initialiser();

/*!
* \brief valeur d timer
*
* Methode qui permet d'obtenir la valeur timer
* \return la methode return la valeur de timer
*
*/
	int timer_valeur();

/*!
* \brief remise a zero du timer
*
* Methode qui permet de remettre la valeur
* du timer a zero
*
*/
	void timer_raz();
};

#endif //timer_H
