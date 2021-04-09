/*!
* \file prise.cpp
* \brief Gestion des prises
* \author ZIANE Mouloud  & JACQUET Prince
* \version 1
* \date 05 AVRIL 2021
*
* Programme de la classe prise
*/
#include <unistd.h>
#include "prise.h"



/*---------------------------------------------*/
prise::prise()
{
	
	io=acces_memoire(&shmid);
}

/*---------------------------------------------*/
void prise::verouiller_trappe()
{
	io->led_trappe=OFF;

}

/*---------------------------------------------*/
void prise::deverouiller_trappe()
{
	io->led_trappe=VERT;

}

/*---------------------------------------------*/
void prise::set_prise()
{
	io->led_prise=VERT;

}

