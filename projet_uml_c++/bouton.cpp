/*!
* \file bouton.cpp
* \brief Gestion des appui sur les boutons
* \author ZIANE Mouloud  & JACQUET Prince
* \version 1
* \date 05 AVRIL 2021
*
* Programme de la classe bouton
*
*/
#include <unistd.h>
#include "bouton.h"

/*-------------------------------------*/
bouton::bouton()
{
	io=acces_memoire(&shmid);
}
/*-------------------------------------*/
int bouton::charge()
{
	if(io->bouton_charge==1)
		bout = 1;
	else
		bout = 0;
	return bout;

}
/*-------------------------------------*/
int bouton::stop()
{
	if(io->bouton_stop==1)
		bout = 1;
	else
		bout = 0;
	return bout;
}
