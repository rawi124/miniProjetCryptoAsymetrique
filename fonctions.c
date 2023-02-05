#include "fonctions.h"
#include <gmp.h>
#include <time.h>


void init_mpz(int N, mpz_t e)
{
  	mpz_init(e);//initialise e a zero
  	mpz_init_set_ui(e, N);//affecte la valeur N a e
}

void exp_mpz(mpz_t e, int N ,int EXP, int P){
	/*
	affecte a l mpz_t e la valeur n^exp mod p 
	*/
	mpz_t n, p ;
	init_mpz(N, n);
  	init_mpz(P, p);
  	
  	mpz_powm_ui(e, n, EXP, p);
}
void alea_mpz(mpz_t n, mpz_t e){
	/*
	genere une valeur aleatoire inferieur a n et l affecte a l mpz_t e
	*/
	gmp_randstate_t etat; 
  	
    	gmp_randinit_default (etat);
    	gmp_randseed_ui(etat, time(NULL));//pour avoir un entier different a chaque execution 
        mpz_urandomm(e, etat, n);//Genere un entier entre 0 et n-1 inclus 

}


int test_primalite_fermat(mpz_t N)
{
	/*
	teste si l entier N est premier ou pas
	si premier renvoie 1 sinon 0 
	*/
	mpz_t a, res, un, N_1;
	init_mpz(1, un);//affecte l entier 1 a l mpz_t un 
	mpz_init(a);
	mpz_init(N_1);
	mpz_init(res);//res contiendra le resultatt, si res = 1 alors N est probablement premier 
	
	mpz_sub (N_1, N, un);//N_1 = N - 1 
	alea_mpz(N, a);//genere a aleatoirement tel que a < N 
	mpz_powm (res, a, N_1, N);
	
	//gmp_printf("Le nombre a tester si premier : %Zd\n",N);
	
	return mpz_cmp(res, un) == 0 ;
  	
}


int generer_premier_fermat(int n)
{
	/*
	genere un entier premier de n bits
	*/
	mpz_t e ;
	gmp_randstate_t etat; 
    	gmp_randinit_default (etat);
    	gmp_randseed_ui(etat, time(NULL));//pour avoir un entier different a chaque execution 
    	mp_bitcnt_t N = n ;
	mpz_urandomb(e, etat, N);//generer un entier  de N bits
	
	int x = test_primalite_fermat(e);
	gmp_printf("Le nombre alea : %Zd la fonction renvoie %d\n",e,x);
	while(x != 1)
	{
		mpz_urandomb(e, etat, N);
		x = test_primalite_fermat(e);
		gmp_printf("Le nombre alea : %Zd la fonction renvoie %d\n",e,x);
	}
        
	return e ;
}


