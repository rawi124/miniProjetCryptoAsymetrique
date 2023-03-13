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
#include "premier.h"


#define PRINT(e)  gmp_printf("Le nombre a afficher : %Zd\n",e);

/********************************************************************************
*
*	MAIN
*
**********************************************************************************/


int main()
{


		printf("**************************test des fonctions de primalité : ***********************************\n\n");
		int len = 1024 ;
		
		printf(" generation d'un nombre premier de longeur %d par la methode de fermat: \n\n",len);
		
		mpz_t e ;mpz_init(e);
        generer_premier_fermat(len, e);
        PRINT(e);
        printf("verification avec la fonction pgp_test\n");
        printf("pour la partie de test la fonction pgp renvoie 0 si le test echoue  1 sinon \n");
        int x = pgp_test(e);
        printf("le resultat %d\n", x);
        
        printf("generation d'un nombre premier de longeur %d par la methode de solvay: \n\n", len);
        mpz_t e_1 ;mpz_init(e_1);
        generer_premier_solovay(len,e_1);
        PRINT(e_1);
        printf("verification avec la fonction pgp_test\n");
        printf("pour la partie de test la fonction pgp renvoie 0 si le test echoue  1 sinon \n");
        x = pgp_test(e_1);
        printf("le resultat %d\n", x);
        
        printf(" generation d'un nombre premier de longeur %d par la methode de fermat: \n\n",len+1024);
        mpz_t e_2 ;mpz_init(e_2);
        generer_premier_fermat(len+1024, e_2);
        PRINT(e_2);
        printf("verification avec la fonction pgp_test\n");
        printf("pour la partie de test la fonction pgp renvoie 0 si le test echoue  1 sinon \n");
        x = pgp_test(e_2);
        printf("le resultat  %d\n", x);
        
        printf("generation d'un nombre premier de longeur %d par la methode de solvay: \n\n", len+1024);
        mpz_t e_3 ;mpz_init(e_3);
        generer_premier_solovay(len+1024,e_3);
        PRINT(e_3);
        printf("verification avec la fonction pgp_test\n");
        printf("pour la partie de test la fonction pgp renvoie 0 si le test echoue  1 sinon \n");
        x = pgp_test(e_3);
        printf("le resultat %d\n", x);
        
        
       
	return 0;


}
