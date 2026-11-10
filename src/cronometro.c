
#include "cronometro.h"
#include "hechizos.h"

#include <stdio.h>
#include <time.h>      /* clock, CLOCKS_PER_SEC */

double medir(long (*f)(long), long n, long *resultado)
{
    clock_t inicio = clock();
    *resultado = f(n);
    clock_t fin = clock();
    return (double) (fin - inicio) / CLOCKS_PER_SEC;
}

void cronometro_tabla(void)
{
    long simples[] = {1000000L, 10000000L, 100000000L};
    long dobles[]  = {1000L, 3000L, 10000L};
    long r;

    printf("\n  %-14s %12s %12s\n", "funcion", "n", "segundos");

    for (int i = 0; i < 3; i++) {
        double t = medir(simple_loop, simples[i], &r);
        printf("  %-14s %12ld %12.6f\n", "simple_loop", simples[i], t);
    }
    for (int i = 0; i < 3; i++) {
        double t = medir(double_loop, dobles[i], &r);
        printf("  %-14s %12ld %12.6f\n", "double_loop", dobles[i], t);
    }
}
