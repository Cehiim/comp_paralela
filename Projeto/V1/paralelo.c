#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

long double result = 0.00;
int numdeexec = 64;
int numporthread = 0;
int numthreads = 16;

long double fat (int num) {
long double fat = 1;
for (int i = 1; i < num + 1; i ++){
fat = fat*i;
}
return fat;
}

void *threadexec(void* args) {
int numthread = (int)args;
long double temp = 0.00;
for (int i = 0; i < numporthread; i ++) {
temp = temp + 1/(fat((i*numthreads)+numthread));
}
result = result+temp;
}

int main() {
pthread_t threads[numthreads];
numporthread = numdeexec/numthreads;
for (int i = 0; i < numthreads; i++) {
pthread_create(&threads[i], NULL, threadexec, (void*)i);
}
for (int i = 0; i < numthreads; i++) {
pthread_join(threads[i], NULL);
}
printf("\n%.70Lf\n", result);
return 0;
}
