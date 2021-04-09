#ifndef PRISE_H
#define PRISE_H

/*!
* \file prise.h
* \brief Gestion des prises
* \author ZIANE Mouloud  & JACQUET Prince
* \version 1
*/

#include <iostream>
#include <donnees_borne.h>
#include <memoire_borne.h>

/*! namespace std
*/
using namespace std;

/*! \class prise
* \brief classe representant la prise et la trappe
*
* La classe gere la la prise et la trappe
*/

class prise
{

entrees *io;    /* structeur de memoire partagee pour communiquer avec le simulateur */
int shmid;

public:

/*!
* \brief Constructeur
*
* Constructeur de la classe prise
*
*/
prise();

/*!
* \brief verouillage de la trappe
*
* Methode qui permet de verouiller la trappe
*
*/
void verouiller_trappe();

/*!
* \brief deverouillage de la trappe
*
* Methode qui permet de deverouiller la trappe
*
*/
void deverouiller_trappe();

/*!
* \brief controle de prise
*
* Methode qui permet de mettre la led
* de prise en VERT
*
*/
void set_prise();

};

#endif //PRISE_H
