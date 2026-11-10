/* ===========================================================================
 * hechizos.c  -  TU TRABAJO del Lab 06: traduce el Lab 01 a C.
 * ---------------------------------------------------------------------------
 * Abre tu notebook del Lab 01 al lado y traduce linea por linea.
 * Cuando termines, `make test` (o probar.bat) te dice si quedo bien.
 * ========================================================================= */

#include "hechizos.h"

/* ---------------------------------------------------------------------------
 * PYTHON (Lab 01):
 *
 *     def mcd(a, b):
 *         while b:
 *             a, b = b, a % b
 *         return a
 *
 * CUIDADO: en C NO existe  a, b = b, a % b.
 * Si escribes  b = a % b;  y despues  a = b;  el segundo ya usa el b NUEVO.
 * Necesitas una variable temporal.
 * ------------------------------------------------------------------------- */
long mcd(long a, long b)
{
    while (b != 0) {
        long temp = b;     /* guardamos el b viejo: C no tiene a, b = b, a % b */
        b = a % b;
        a = temp;
    }
    return a;
}

/* ---------------------------------------------------------------------------
 * PYTHON:
 *
 *     def fibonacci(n):
 *         a, b = 0, 1
 *         for _ in range(n):
 *             a, b = b, a + b
 *         return a
 *
 * El for de C tiene tres partes:  for (int i = 0; i < n; i++)
 * Usa long long para a y b.
 * ------------------------------------------------------------------------- */
long long fibonacci(int n)
{
    long long a = 0, b = 1;
    for (int i = 0; i < n; i++) {
        long long siguiente = a + b;
        a = b;
        b = siguiente;
    }
    return a;
}

/* PYTHON:   count = 0;  for i in range(n): count += 1;  return count */
long simple_loop(long n)
{
    long count = 0;
    for (long i = 0; i < n; i++) {
        count += 1;
    }
    return count;
}

/* PYTHON:   dos for anidados de range(n), count += 1 en el de adentro */
long double_loop(long n)
{
    long count = 0;
    for (long i = 0; i < n; i++) {
        for (long j = 0; j < n; j++) {
            count += 1;
        }
    }
    return count;
}
