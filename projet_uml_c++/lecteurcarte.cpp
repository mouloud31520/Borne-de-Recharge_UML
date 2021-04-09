/*!
* \file lecteurcarte.cpp
* \brief La lecture de la carte
* \author ZIANE Mouloud  & JACQUET Prince
* \version 1
* \date 05 AVRIL 2021
*
* Programme de la classe lecteurcarte
*
*/
#include "lecteurcarte.h"
#include "base_client.h"


/*---------------------------------------*/
LecteurCarte::LecteurCarte()
{
	initialisations_ports();
	cout << "Initialisation des ports reussi" <<endl;
	io=acces_memoire(&shmid);
	if(io==NULL)
	cout<<"Erreur d'initialisation"<<endl;

}

/*---------------------------------------*/
void LecteurCarte::lire_carte()
{

int numero_client;


    cout<<"/***************************/"<<endl;
    cout<<"Entrer le Numéro de votre Badge SVP"<< endl;
    cout<<"/***************************/"<<endl;

    cin >> numero_carte ;
	T.initialiser();

    cout<<"/***************************/"<<endl;
	cout<<"Numéro de Badge =  "<< numero_carte << endl;
    cout<<"/***************************/"<<endl;

	if(lecture_base.authentifier(numero_carte)==1)
	{
		numero_client=numero_carte;

        cout<<"/***************************/"<<endl;
		cout<<"Authentification OK "<< endl;
        cout<<"/***************************/"<<endl;

		V.blink_charge();
		

        while((T.timer_valeur()) < 20 && (BT.charge()== 0) && (BT.stop() == 0)){}

        if(BT.stop() == 1)
			{

			io->bouton_stop = 0;

			}

        if(T.timer_valeur() >= 20)
			{

			cout<<"Temps écoulé"<<endl;
			liberation_ports();
			initialisations_ports();

			}
		
		if(BT.charge()==1){

                io->bouton_charge = 0;
				io->led_dispo=OFF;
				io->led_charge=VERT;

                cout<<"/***************************/"<<endl;     
				cout<<"Votre demande de charge Véhicule est Accepté "<<endl;	
                cout<<"/***************************/"<<endl;
				cout<<"Appuyer sur prise pour Brancher votre véhicule"<<endl;	
    
				G.charger();
                cout<<"/***************************/"<<endl;
                cout<<"Entrer le numero de votre Badge"<< endl;
                cin >> numero_carte ;
                cout<<"/***************************/"<<endl;

                while(numero_carte!=numero_client)
                {
					usleep(1000000);
					io->led_defaut=ROUGE;
					usleep(1000000);
					io->led_defaut=OFF;
                    cout<<"Résseyer d'Entrer le Numero de Votre Badge"<< endl;
                    cin >> numero_carte ;
						
				}
           
                G.deconnecter();

             
                cout<<"Appuyer sur Prise pour Débrancher votre  Véhicule"<<endl;
                cout<<"/***************************/"<<endl;

                while(G.tension()!=12){}

				P.verouiller_trappe();
				io->led_prise=OFF;				
				io->led_dispo=VERT;
	
				}	
		}	

    else
	{

    cout<<"/***************************/"<<endl;
	cout<<"Error, Veuillez Résseyer ! " << endl;
    cout<<"/***************************/"<<endl;

	liberation_ports();
	initialisations_ports();
	V.blink_chargeR();

	}	
				
		
}


/*---------------------------------------*/

int LecteurCarte::get_numero_carte()
{
	return numero_carte;
}
/*---------------------------------------*/
void LecteurCarte::ajout(int a)
{
  lecture_base.ajouter_client(a);
}
/*---------------------------------------*/
void LecteurCarte::suppr(int a)
{
lecture_base.supprimer_client(a);
}

