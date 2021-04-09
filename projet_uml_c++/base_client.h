#ifndef BASECLIENT_H
#define BASECLIENT_H

/*!
* \file base_client.h
* \brief Gestion de la base client
* \author ZIANE Mouloud  & JACQUET Prince
* \version 1
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <unistd.h>

/*!
namespace std
*/

using namespace std;


/*! \class base_client
* \brief classe representant la base client
*
* La classe gere la base client
*/

class base_clients
{
  vector<int> liste_numero;  /*!< vecteur represantant la liste des clients*/
  public:
  
  /*!
* \brief Constructeur
*
* Constructeur de la classe base_client
*
* Permet de lire le fichier qui contient les numéro clients 
* et de les stocker dans le vecteur liste_numéro 
*
*/
  base_clients();
  
  /*!
* \brief authetification  d'un client
*
* Methode qui permet d' authentifier un numéro de carte 
*
* \param int a : le numéro de la carte à  authentifier
*
*\return true si numero present dans la liste,
* sinon renvoi false 
*/	
  int authentifier(int a);
  
  /*!
* \brief Ajout d'un client
*
* Methode qui permet d'ajouter un numéro client a liste 
* des anciens clients
*
* \param int a : le numéro du client à ajouter
*
*/
  void ajouter_client(int a);
  
  /*!
* \brief suppression d'un client
*
* Methode qui permet de supprimer un numéro client de la  
* liste des anciens clients
*
* \param int a : le numéro du client à supprimer
*
*/	
  void supprimer_client(int a);
  
};

#endif // BASECLIENT_H
