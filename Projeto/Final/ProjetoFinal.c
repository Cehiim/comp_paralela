#include <stdio.h> // Biblioteca de input/output
#include <stdlib.h> // Biblioteca de alocação de memória
#include <pthread.h> // Biblioteca de manipulação de threads
#include <mpfr.h> // Biblioteca de cálculo de precisão arbitrária

#define N_CASA 100000
int num_exec = 1000;
int num_threads = 16;
mpfr_t result;
int exec_por_thread = num_exec/num_threads;


void fatorial (int n, mpfr_t fat_result) { // Função para calcular o fatorial de um número 'n'
  mpfr_set_ui(fat_result, 1.0, MPFR_RNDU); // Define o valor de "fat_result" para 1.0
                                           // "MPFR_RNDU" é uma constante que indica o modo de arredondamento para cima
  for (int i = 1; i < n+1; i ++){
    mpfr_mul_ui(fat_result, fat_result, i, MPFR_RNDU); // Dentro do loop, "fat_result" é multiplicado pelo valor de 'i'
  }
}

void *threadexec(void* args) { // Função de execução para cada thread
  int thread_id = (int)args;
  mpfr_t temp, fat, div, um;
  mpfr_init2(temp, N_CASA); // Define a precisão especificada para cada variável (número de casas decimais após o ponto)
  mpfr_init2(fat, N_CASA);
  mpfr_init2(div, N_CASA);
  mpfr_init2(um, N_CASA);
  int aux;
  mpfr_set_d(temp, 0.0, MPFR_RNDU); // Define o valor de "temp" para 0.0
  mpfr_set_d(um, 1.0, MPFR_RNDU); // Define o valor de "um" para 1.0
  for (int i = 0; i < exec_por_thread; i ++) {
    aux = ((i*num_threads) + thread_id); // Define o número que será calculado como fatorial para iteração
                                         // "(i*num_threads)" é feito para distribuir o trabalho de cálculo do fatorial entre as threads
                                         // "(... + thread_id)" garante que cada thread esteja calculando fatoriais de números diferentes
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
pthread_t threads[num_threads];
mpfr_init2(result, N_CASA);
mpfr_set_d(result, 0.0, MPFR_RNDU);
  
for (int i = 0; i < num_threads; i++) {
pthread_create(&threads[i], NULL, threadexec, (void*)i);
}
for (int i = 0; i < num_threads; i++) {
pthread_join(threads[i], NULL);
}
mpfr_out_str(stdout, 10, 0, result, MPFR_RNDU);
mpfr_clear(result);
return 0;
}
