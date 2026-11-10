/* ===========================================================================
 * test_lab06.c  -  Pruebas del Lab 06 (La Forja).   NO LO MODIFIQUES.
 * ---------------------------------------------------------------------------
 * Se corre con:   make test        (Mac, Linux, terminal UCRT64 de MSYS2)
 *                 probar.bat       (Windows)
 * ========================================================================= */

#include "prueba.h"
#include "hechizos.h"
#include "cronometro.h"
#include "guardian.h"

int main(void)
{
    printf("\n  Pruebas del Lab 06 - La Forja\n");
    printf("  -----------------------------\n");

    /* --- mcd --- */
    VERIFICAR(mcd(48, 18) == 6,      "mcd(48, 18) == 6");
    VERIFICAR(mcd(1071, 462) == 21,  "mcd(1071, 462) == 21");
    VERIFICAR(mcd(17, 5) == 1,       "mcd(17, 5) == 1   (primos entre si)");
    VERIFICAR(mcd(7, 0) == 7,        "mcd(7, 0) == 7    (caso borde)");

    /* --- fibonacci --- */
    VERIFICAR(fibonacci(0) == 0,     "fibonacci(0) == 0");
    VERIFICAR(fibonacci(1) == 1,     "fibonacci(1) == 1");
    VERIFICAR(fibonacci(10) == 55,   "fibonacci(10) == 55");
    VERIFICAR(fibonacci(50) == 12586269025LL,
              "fibonacci(50) == 12586269025   (ya no cabe en un int)");
    VERIFICAR(fibonacci(92) == 7540113804746346429LL,
              "fibonacci(92) == 7540113804746346429   (el ultimo que cabe)");

    /* --- los lazos --- */
    VERIFICAR(simple_loop(0) == 0,   "simple_loop(0) == 0");
    VERIFICAR(simple_loop(7) == 7,   "simple_loop(7) == 7");
    VERIFICAR(double_loop(0) == 0,   "double_loop(0) == 0");
    VERIFICAR(double_loop(4) == 16,  "double_loop(4) == 16");

    /* --- el cronometro --- */
    long r = -1;
    double t = medir(simple_loop, 1000, &r);
    VERIFICAR(r == 1000 && t >= 0.0, "medir(simple_loop, 1000) entrega 1000");

    /* --- el guardian --- */
    VERIFICAR(guardian_comparar(50, 30) == 1,
              "guardian: clave 50, intento 30 -> 'mas alto' (1)");
    VERIFICAR(guardian_comparar(50, 70) == -1,
              "guardian: clave 50, intento 70 -> 'mas bajo' (-1)");
    VERIFICAR(guardian_comparar(50, 50) == 0,
              "guardian: clave 50, intento 50 -> acierto (0)");
    VERIFICAR(guardian_comparar(1, 100) == -1,
              "guardian: clave 1, intento 100 -> 'mas bajo' (-1)");

    return RESUMEN("Lab 06");
}
