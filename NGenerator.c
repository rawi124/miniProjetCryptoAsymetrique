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

        generer_premier_fermat(10);
        


	return 0;


}
