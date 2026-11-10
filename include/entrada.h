/* ===========================================================================
 * entrada.h  -  Leer del teclado sin que el programa se rompa.
 * ---------------------------------------------------------------------------
 * MODULO DADO: no lo modifiques. Lo vas a usar todo el semestre.
 *
 * Un .h es la VITRINA del modulo: dice QUE funciones existen.
 * El COMO esta en src/entrada.c
 * ========================================================================= */

#ifndef ENTRADA_H      /* include guard: evita que el archivo se lea dos veces */
#define ENTRADA_H

/* Muestra `mensaje` y lee un entero. Si el usuario escribe algo que no es
 * un numero, avisa y vuelve a preguntar: el programa NUNCA se cae.
 * Si la entrada se termina (Ctrl+D / Ctrl+Z), devuelve 0.
 *
 * Uso:   int opcion = get_int("  Tu opcion: ");
 *
 * POR QUE NO scanf("%d"): si el usuario escribe "hola", scanf deja esas
 * letras en la entrada y el siguiente scanf las vuelve a leer, una y otra
 * vez. Bucle infinito. Por eso en este curso se lee con fgets + sscanf. */
int get_int(const char *mensaje);

/* Lee una linea de texto (sin el Enter final) y la guarda en `destino`,
 * que tiene espacio para `capacidad` caracteres.
 * Devuelve 1 si leyo algo, 0 si la entrada se termino. */
int get_texto(const char *mensaje, char *destino, int capacidad);

/* Espera a que el usuario pulse Enter. */
void pausa(void);

#endif /* ENTRADA_H */
