#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

double f(double x) {
    return 5.0 + sin(x);
}

double Trap(double a, double b, int n) {
    double h = (b - a) / n;
    double my_result = (f(a) + f(b)) / 2.0;

    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        my_result += f(x);
    }

    my_result *= h;
    return my_result;
}

int main(int argc, char* argv[]) {

    if (argc != 5) {
        printf("insira: %s <a> <b> <n> <thread_count>\n", argv[0]);
        exit(1);
    }

    double a = strtod(argv[1], NULL);
    double b = strtod(argv[2], NULL);
    int n = strtol(argv[3], NULL, 10);
    int thread_count = strtol(argv[4], NULL, 10);

    double global = 0.0;

#   pragma omp parallel num_threads(thread_count) reduction(+:global)
    {
        int my_rank = omp_get_thread_num();
        int local_n = n / thread_count;
        double local_a = a + my_rank * local_n * ((b - a) / n);
        double local_b = local_a + local_n * ((b - a) / n);
        double my_result = Trap(local_a, local_b, local_n);
#   pragma omp critical 
{
        global += my_result;
        }
    }

    printf("da integral de %f a %f = %.14e\n", a, b, global);

    return 0;
}
