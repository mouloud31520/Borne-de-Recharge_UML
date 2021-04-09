/*!
* \file timer.cpp
* \brief Gestion du timer
* \author ZIANE Mouloud  & JACQUET Prince
* \version 1
* \date 05 AVRIL 2021
*
* Programme de la classe timer
*/

#include "timer.h"

/**-------------------------------------*/
timer::timer()
{
	io=acces_memoire(&shmid);
	if(io==NULL)
	cout<<"Erreur d'initialisation"<<endl;
}

/*-----------------------------------------*/
 void timer::initialiser()
{
	depart_timer=io->timer_sec;
}

 /*----------------------------------------*/
int timer::timer_valeur()
{
return (io->timer_sec)-depart_timer;
}

/*--------------------------------------*/
void timer::timer_raz()
{
depart_timer=0;
}
