/**********************************************
*
*		Projet pour M1 DID
*
***********************************************/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <gmp.h>
#include <math.h>
#include <inttypes.h>
#include "fonctions.h"


#define PRINT(e)  gmp_printf("Le nombre a afficher : %Zd\n",e);

/********************************************************************************
*
*	MAIN
*
**********************************************************************************/


int main()
{
	mpz_t e ;mpz_init(e);
	
        //generer_premier_fermat(1024, e);
        generer_premier_solovay(700,e);
        PRINT(e);
        //int x = pgp_test_fermat(e);
        //printf("res %d\n", x);
        
        


	return 0;


}
