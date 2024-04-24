#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

double f(double x) {
    return 5.0 + sin(x);
}

double soma(double a, double b, double n) {
    double h = (b - a) / n;
    double approx = (f(a) + f(b)) / 2.0;
    for (int i = 1; i <= n - 1; i++) {
        double x_i = a + i * h;
        approx += f(x_i);
    }
    approx *= h;
    return approx;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("\nInsira um argumento de entrada: Número de threads.\n");
        return 1;
    }
    double a = 0.0;
    double b = 10.0;
    double n = 1000000000.0;

    int n_threads = strtol(argv[1], NULL, 10);

    double global = 0.0;

#pragma omp parallel num_threads(n_threads)
    {
        double parcial = 0.0;

#pragma omp for reduction(+:parcial)
        for (int i = 0; i < n_threads; i++) {
            double local_a = a + i * (b - a) / n_threads;
            double local_b = local_a + (b - a) / n_threads;
            parcial += soma(local_a, local_b, n / n_threads);
        }

#pragma omp critical
        {
            global += parcial;
        }
    }

    printf("\nA integral estimada é: %.14e\n", global);

    return 0;
}
