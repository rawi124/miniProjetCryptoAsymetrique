#include "premier.h"
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

int test_primalite_solovay(mpz_t N)
{
	/*
	teste si l entier N est premier ou pas
	si premier renvoie 1 sinon 0 
	*/
	mpz_t a, res, un, N_1, div, deux, X, impair, zero;
	init_mpz(1, un);//affecte l entier 1 a l mpz_t un 
	init_mpz(2, deux);//affecte l entier 2 a l mpz_t deux 
	init_mpz(0, zero);//affecte l entier 1 a l mpz_t un 
	mpz_init(a);
	mpz_init(impair);
	mpz_init(N_1);
	mpz_init(div);
	mpz_init(res);//res contiendra le resultatt, si res = 1 alors N est probablement premier
	 
	
	mpz_sub (N_1, N, un);//N_1 = N - 1 
	mpz_cdiv_q (div, N_1, deux);
	alea_mpz(N, a);//genere a aleatoirement tel que a < N 
	mpz_powm (res, a, div, N);
	int jaco = mpz_jacobi (a, N);
	init_mpz(jaco, X);
	mpz_mod(impair, N, deux);
	
	
	//gmp_printf("impair : %Zd entier %Zd\n",impair, N);
	
	return mpz_cmp(res, X ) == 0 && mpz_cmp(impair, zero) != 0    ;
  	
}

void generer_premier_solovay(int n, mpz_t e )
{
	/*
	genere un entier premier de n bits et l affecte a e
	*/
	
	gmp_randstate_t etat; 
    	gmp_randinit_default (etat);
    	gmp_randseed_ui(etat, time(NULL));//pour avoir un entier different a chaque execution 
    	mp_bitcnt_t N = n ;
	mpz_urandomb(e, etat, N);//generer un entier  de N bits
	
	int x = test_primalite_solovay(e);
	//gmp_printf("Le nombre alea : %Zd la fonction renvoie %d\n",e,x);
	while(x != 1)
	{
		mpz_urandomb(e, etat, N);
		x = test_primalite_solovay(e);
		//gmp_printf("Le nombre alea : %Zd la fonction renvoie %d\n",e,x);
	}

}


void generer_premier_fermat(int n, mpz_t e )
{
	/*
	genere un entier premier de n bits et l affecte a e
	*/
	
	gmp_randstate_t etat; 
    	gmp_randinit_default (etat);
    	gmp_randseed_ui(etat, time(NULL));//pour avoir un entier different a chaque execution 
    	mp_bitcnt_t N = n ;
	mpz_urandomb(e, etat, N);//generer un entier  de N bits
	
	int x = test_primalite_fermat(e);
	//gmp_printf("Le nombre alea : %Zd la fonction renvoie %d\n",e,x);
	while(x != 1)
	{
		mpz_urandomb(e, etat, N);
		x = test_primalite_fermat(e);
		//gmp_printf("Le nombre alea : %Zd la fonction renvoie %d\n",e,x);
	}

}



int pgp_test(mpz_t e)
{
	/*
	effectue le test pgp avec les 4 premiers nombres premiers 2, 3, 5, 7
	renvoie 0 si le test echoue avec l un des entiers 1 sinon
	*/
	mpz_t un, deux, trois, cinques, septs, e_1, res_2, res_3, res_5, res_7; 
	mpz_init(e_1);
	init_mpz(1, un);//affecte l entier 1 a l mpz_t un 
	mpz_sub (e_1, e, un);//e_1 = e - 1
	
	mpz_init_set_ui(deux, 2);
	mpz_init_set_ui(trois, 3);
	mpz_init_set_ui(cinques, 5);
	mpz_init_set_ui(septs, 7);
	mpz_init(res_2);mpz_init(res_3);mpz_init(res_5);mpz_init(res_7);
	
	mpz_powm (res_2, deux, e_1, e);
	mpz_powm (res_3, trois, e_1, e);
	mpz_powm (res_5, cinques, e_1, e);
	mpz_powm (res_7, septs, e_1, e);
	
	return mpz_cmp(res_2, res_3) == 0 && mpz_cmp(res_5, res_7) == 0 && mpz_cmp(res_2, res_7) == 0  ;
	
}


