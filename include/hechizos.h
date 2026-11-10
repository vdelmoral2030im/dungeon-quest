/* ===========================================================================
 * hechizos.h  -  Los cuatro algoritmos del Lab 01, ahora en C.      [Lab 06]
 * ---------------------------------------------------------------------------
 * Son LOS MISMOS que escribiste en Python la primera semana.
 * No hay ningun algoritmo nuevo: cambia el idioma, no la idea.
 *
 * Las firmas son EXACTAS: no las cambies, las pruebas las usan asi.
 * ========================================================================= */

#ifndef HECHIZOS_H
#define HECHIZOS_H

/* Por que estos tipos:
 *
 *   int        32 bits   hasta  2.147.483.647
 *   long       32 bits en Windows, 64 en Mac/Linux  (!)
 *   long long  64 bits   hasta  9.223.372.036.854.775.807
 *
 * fibonacci devuelve long long porque F(92) ya tiene 19 digitos.
 * F(93) ya NO cabe: es la sorpresa de esta semana. */

/* Maximo comun divisor, algoritmo de Euclides. Precondicion: a, b >= 0. */
long mcd(long a, long b);

/* n-esimo Fibonacci, version iterativa. F(0) = 0, F(1) = 1. */
long long fibonacci(int n);

/* Cuenta de 0 a n-1 y devuelve la cuenta. El control LINEAL del Lab 01. */
long simple_loop(long n);

/* Dos lazos anidados de 0 a n-1. El control CUADRATICO del Lab 01. */
long double_loop(long n);

#endif /* HECHIZOS_H */
