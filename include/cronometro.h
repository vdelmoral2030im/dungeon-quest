/* ===========================================================================
 * cronometro.h  -  El Cronometro del Lab 01, version C.              [Lab 06]
 * ========================================================================= */

#ifndef CRONOMETRO_H
#define CRONOMETRO_H

/* DADA. Ejecuta f(n), guarda lo que devuelve en *resultado y retorna los
 * segundos que tardo.
 *
 * El primer parametro es un PUNTERO A FUNCION: le pasas el NOMBRE de una
 * funcion, sin parentesis:     medir(simple_loop, 1000000, &r);
 * Lo veras a fondo en el Lab 11. Hoy solo lo usas.
 *
 * Por que el resultado sale por puntero y no como retorno: si nadie usa lo
 * que calcula f, el compilador puede borrar la llamada entera "porque no
 * sirve para nada", y medirias cero. Guardandolo, la llamada se queda. */
double medir(long (*f)(long), long n, long *resultado);

/* TU TRABAJO: mide simple_loop y double_loop con varios n e imprime
 * una tabla  n | segundos. */
void cronometro_tabla(void);

#endif /* CRONOMETRO_H */
