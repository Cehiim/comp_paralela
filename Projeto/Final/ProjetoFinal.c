#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <mpfr.h>
#include <gmp.h>

#define N_CASA 1000

mpfr_t result;
int numdeexec = 8;
int numporthread = 0;
int numthreads = 1;


void fatorial (int num, mpfr_t result) {
mpfr_set_ui(result, 1.0, MPFR_RNDU);
for (int i = 1; i < num+1; i ++){
mpfr_mul_ui(result, result, i, MPFR_RNDU); 
}
}

void *threadexec(void* args) {
int numthread = (int)args;
mpfr_t temp, fat, div, um;
mpfr_init2(temp, N_CASA);
mpfr_init2(fat, N_CASA);
mpfr_init2(div, N_CASA);
mpfr_init2(um, N_CASA);
int aux;
mpfr_set_d(temp, 0.0, MPFR_RNDU);
mpfr_set_d(um, 1.0, MPFR_RNDU);
for (int i = 0; i < numporthread; i ++) {
aux = ((i*numthreads) + numthread);
fatorial(aux, fat);
mpfr_div(div, um, fat, MPFR_RNDU);
mpfr_add(temp, temp, div, MPFR_RNDU);
}
mpfr_add(result, result, temp, MPFR_RNDU);
mpfr_clear(temp);
mpfr_clear(fat);
mpfr_clear(div);
mpfr_clear(um);
return NULL;
}

int main() {
pthread_t threads[numthreads];
numporthread = numdeexec/numthreads;
mpfr_init2(result, N_CASA);
mpfr_set_d(result, 0.0, MPFR_RNDU);
for (int i = 0; i < numthreads; i++) {
pthread_create(&threads[i], NULL, threadexec, (void*)i);
}
for (int i = 0; i < numthreads; i++) {
pthread_join(threads[i], NULL);
}
mpfr_out_str(stdout, 10, 0, result, MPFR_RNDU);
mpfr_clear(result);
return 0;
}
