/**********************************************
*
*		Projet pour M1 DID
*
*/




#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <gmp.h>
#include <math.h>
#include <inttypes.h>
#include "fonctions.h"




int affichage(uint64_t * res, int size, char *txt)
{
	printf("%s = ",txt);
	for (int i=0;i<size;i++) printf("%16.16lX ",res[size-1-i]);
	printf(" ;\n\n");
	
	return 0;
}


/********************************************************************************
*
*	MAIN !!!!!!!!!!
*
*/


int main()
{


	int i,size=SIZE;
	size_t count;
	uint64_t a[SIZE],b[SIZE], res[SIZE<<1], test[SIZE<<1] , indicateur = 0;
	uint64_t x=0xffffffffffffffff,y=0xffffffffffffffff,c=1;
	



	srand(time(NULL));
	indicateur = 0 ;
	for (i=0;i<size;i++)
	{
		// pour avoir A[i] et B[i] entre 0x00000000 et 0xffffffff
		a[i] = (((uint64_t)(rand()+rand())<<32)^(rand()+rand()));
		b[i] = (((uint64_t)(rand()+rand())<<32)^(rand()+rand()));
	}


	printf("--------------------------------------------------------------------------\n");
	printf("                             SIZE = %d 64 bit words\n",size);
	printf("--------------------------------------------------------------------------\n");

	
	affichage(a,size,"a");	
	
	affichage(b,size,"b");
		

	


	printf("Au revoir et merci !\n");

	return 0;


}
