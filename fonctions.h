
#ifndef FONCTIONS_H
#define FONCTIONS_H

#include <inttypes.h>
#include <gmp.h>

#define SIZE 4

void init_mpz(int N, mpz_t e);

void exp_mpz();

void alea_mpz(mpz_t n, mpz_t e);

int test_primalite_fermat(mpz_t N);

void generer_premier_fermat(int n, mpz_t e );

int pgp_test_fermat(mpz_t e);

void generer_premier_solovay(int n, mpz_t e );

int test_primalite_solovay(mpz_t N);
#endif
