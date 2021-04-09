/*!
* \file voyants.cpp
* \brief Gestion d'allumage des voyants
* \author ZIANE Mouloud  & JACQUET Prince
* \version 1
* \date 05 AVRIL 2021
*
* Programme de la classe voyants
*/

#include <unistd.h>
#include "voyants.h"

/*-------------------------------------------*/
voyants::voyants(){
	
	io=acces_memoire(&shmid);

}

/*---------------------------------------------*/
void voyants:: set_charge()
{

    io->led_charge=VERT;
}

/*---------------------------------------------*/
void voyants::set_dispo()
{

	io->led_dispo=VERT;
}

/*-----------------------------------------------*/
void voyants::blink_charge()
{
	int i=0;	
    for(i=0;i<8;i++)
    {
		
		usleep(500000);
		io->led_charge=VERT;
		usleep(500000);
		io->led_charge=OFF;	
	}
}

/*-----------------------------------------------*/
void voyants::blink_chargeR()
{
	int i=0;	
    for(i=0;i<8;i++)
    {
		
		usleep(500000);
		io->led_defaut=ROUGE;
		usleep(500000);
		io->led_defaut=OFF;	
	}
}

