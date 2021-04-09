/*!
* \file generateur_save.cpp
* \brief La machine à etat du generateur (MEF).
* \author ZIANE Mouloud  & JACQUET Prince
* \version 1
* \date 05 AVRIL 2021
*
* Programme de la classe generateur save
*
*/


#include "generateur_save.h"

/*-------------------------------------*/
generateur_save::generateur_save()
{
	io=acces_memoire(&shmid);	
}
/*-------------------------------------*/
void generateur_save::generer_pwm(pwm type)
{
	io->gene_pwm = type;
	sleep(1);
}
/*-------------------------------------*/
float generateur_save:: tension()
{
	return io->gene_u;
}
/*-------------------------------------*/
void generateur_save::charger()
{
	mef();
}
/*-------------------------------------*/
void generateur_save::ouvrir_AC()
{
	io->contacteur_AC = 0;
}
/*-------------------------------------*/
void generateur_save::fermer_AC()
{
	io->contacteur_AC = 1;
}
/*-------------------------------------*/
void generateur_save::deconnecter()
{
	io->led_trappe=VERT;
	io->led_charge=OFF;
	
}
/*------------------MEF-------------------*/

void generateur_save::mef()
{
	unsigned int etat_present;
	unsigned int etat_suivant;
	unsigned int fin;

	fin = 0;
	etat_present = 0;
	etat_suivant = 0;
	while(fin != 1)
	{etat_present = etat_suivant;
		switch(etat_present){
		case 0 :{
			generer_pwm(DC);
			io->led_charge=ROUGE;
			io->led_trappe=VERT;
			if(tension() == 9)
				{etat_suivant = 1;}
			if(B.stop() == 1)
				{io->bouton_stop = 0;
				etat_suivant = 4;}
			}break;
		case 1 :{
			io->led_prise=VERT;
			generer_pwm(AC_1K);
			io->led_trappe=OFF;
			if(tension() == 6)
				etat_suivant = 2;
			if(B.stop() == 1)
				{io->bouton_stop = 0;
				etat_suivant = 4;}			
			}break;
		case 2 :{
			fermer_AC();
			generer_pwm(AC_CL);
			if(tension() == 6)
				etat_suivant = 3;
			if((B.stop() == 1) || (tension() == 9))
				{io->bouton_stop = 0;
				etat_suivant = 4;}	
			}break;

		case 3 :{
			if((B.stop() == 1) || (tension() == 9))
				{io->bouton_stop = 0;
				etat_suivant = 4;}
			}break;

		case 4 :{
				ouvrir_AC();
				io->led_charge=VERT;
				generer_pwm(DC);
				fin = 1;	
			}break;
		}
	}
	
	
}

