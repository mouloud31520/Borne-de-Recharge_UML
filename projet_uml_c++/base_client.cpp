/*!
* \file base_client.cpp
* \brief Gestion de la base client
* \author ZIANE Mouloud  & JACQUET Prince
* \version 1
* \date 05 AVRIL 2021
*
* Programme de la classe base client
*/
#include "base_client.h"


/*------------------------------------------*/
base_clients::base_clients()
{
	int a=0;
	ifstream entre ("base.txt");
	while(!entre.eof())
		{
 		entre >>a;
 		liste_numero.push_back(a);
		}

}

/*------------------------------------------*/

//pour authentification


int base_clients::authentifier (int a)
{	int ok=0;
	for(unsigned int i=0; i< liste_numero.size(); i++)
		{
			if(liste_numero.at(i) == a)
			  {
			   ok=1;
			  }
		}
	if(ok != 1)
		{
			ok=0;
		}
return ok;
}

//zone admin
/*------------------------------------------*/
void base_clients::ajouter_client (int a)
{
 liste_numero.push_back(a);

ofstream entre("base.txt");
for (unsigned int i=0 ; i< liste_numero.size() ; i++)
entre <<liste_numero.at(i)<<endl; 
}


/*------------------------------------------*/
void base_clients::supprimer_client(int a)
{
unsigned int j=0;

for (unsigned int i=0 ; i< liste_numero.size() ; i++)

	{	

	 if(liste_numero.at(i) == a)
		{
			j=i;
		} 
	}

vector<int>::iterator vi =liste_numero.begin()+(j-1);
liste_numero.erase(vi);


ofstream entre("base.txt");

for (unsigned int i=0 ; i< liste_numero.size() ; i++)
entre <<liste_numero.at(i)<<endl; 

}







