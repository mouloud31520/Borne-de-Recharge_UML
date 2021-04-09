/*!
* \file borne.c
* \brief Programme de la borne de  recharge electrique.
* \author ZIANE Mouloud  & JACQUET Prince
* \version 1
* \date 05 AVRIL 2021
*
*/

#include <iostream>
#include "memoire_borne.h"
#include "donnees_borne.h"
#include "lecteurcarte.h"
#include "base_client.h"



using namespace std;

/*!
*
* \fn int main (void)
*
*/

int main()
{int choix;
int code; // le code  admin est: 1996 => pour  ajouter  ou supprimer un client
int choix_admin;
int num_client;


    LecteurCarte lecteurcarte;

    while (1)
    
  {
    cout<<"*****************************************"<<endl;
    cout<<"BIENVENU"<<endl;
    cout<<"Veillez choisir une option SVP"<<endl;
    cout<<"1: Charger votre Véhicule"<<endl;
    cout<<"2: Gérer la base clients"<<endl;
    cout<<"*****************************************"<<endl;
    cout<<"Quel est votre choix"<<endl;
    cin>> choix;
    
    if (choix ==1)
    {
        lecteurcarte.lire_carte();
        cout<<"AU REVOIR"<<endl;
        cout<<"*****************************************"<<endl;
    }
    if (choix == 2)
    {
    cout<<"Veuillez Saisir Votre  Code d'Administrateur"<<endl;
    cin>>code;
    if (code == 1996)
    {cout<<"*****************************************"<<endl;
     cout<<"ADMIN Reconnu"<<endl;
     cout<<"Veillez choisir une option SVP"<<endl;
     cout<<"1: Ajouter un client"<<endl;
     cout<<"2: Supprimer un client "<<endl;
     cout<<"*****************************************"<<endl;
     cout<<"Quel est votre choix"<<endl;
     cin>>choix_admin;
      if(choix_admin==1)
			{
                cout<<"Entrer le numéro de votre Badge SVP"<<endl;
                cin >> num_client;
                lecteurcarte.ajout(num_client);
                cout<<"Numero de la carte ajouter=  "<< num_client<< endl;
				cout<<"Ajouter_Numéro_Client Reussi !"<<endl;
			}

            if(choix_admin==2)
			{
                cout<<"Entrer le numero de votre badge SVP"<<endl;
                cin >> num_client;
                lecteurcarte.suppr(num_client);
				cout<<"Supprimer_Numéro_Client Reussi !"<<endl;
				
			}
    }

        else
            {
                cout<<"Code Erroné"<<endl;
            }
    }
    
   }

}
