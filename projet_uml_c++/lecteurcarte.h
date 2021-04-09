#ifndef LECTEURCARTE_H
#define LECTEURCARTE_H

/*!
* \file lecteurcarte.h
* \brief La lecture de la carte
* \author ZIANE Mouloud  & JACQUET Prince
* \version 1
*/

#include <lcarte.h>
#include <iostream>
#include <unistd.h>
#include <donnees_borne.h>
#include <memoire_borne.h>
#include <vector>
#include <fstream>
#include <string>
#include "base_client.h"
#include "generateur_save.h"
#include "prise.h"
#include "bouton.h"
#include "timer.h"
#include "voyants.h"

/*! namespace std
*/
using namespace std;

/*! \class LecteurCarte
* \brief classe representant le lecteur carte
*
* La classe gere la lecture des cartes clients
*/
class LecteurCarte
{	
	int numero_carte;
	int shmid;
	entrees *io;    /* structeur de memoire partagee pour communiquer avec le simulateur */     
	voyants V;	   /*objet de la classe voyants */
	bouton BT;	  /*objet de la classe bouton*/
	prise P;     /*objet de la classe prise */
	timer T;	/*objet de la classe timer */
	generateur_save G;	 /*objet de la classe generateur_save */
	 
	
  public : 
    base_clients lecture_base;  /*objet de la classe base_client */
	
	/*!
* \brief Constructeur
*
* Constructeur de la classe LecteurCarte
*
*/
	LecteurCarte();

/*!
* \brief gestion du lecteur de carte
*
* Methode qui permet de gerer le lecteur 
* de carte et la comunication entre les 
* objets des autre classes
*
*/
	void lire_carte();
	
/*!
* \brief acces au numero de la carte 
*
* Methode qui permet d'obtenir le numero 
* de carte meme s'il est privé
*
*
*/
	int get_numero_carte();

/*!
* \brief ajout de client
*
* Methode qui permet d'utiliser la methode 
* de la classe base_client ajouter_client
*\param int a : le numéro du client à ajouter
*
*/
	void ajout(int a);

/*!
* \brief suppression de client
*
* Methode qui permet d'utiliser la methode 
* de la classe base_client supprimer_client
*\param int a : le numéro du client à supprimer
*
*/
	void suppr(int a);
};

#endif // LECTEURCARTE_H
