/* ===========================================================================
 * mapa.h  -  El mapa del dungeon y la tabla de dano: MATRICES.       [Lab 10]
 * ---------------------------------------------------------------------------
 * Una matriz parece una cuadricula, pero en memoria es UNA SOLA FILA de
 * casillas, una fila de la matriz detras de otra (row-major):
 *
 *   mapa[0][0] mapa[0][1] ... mapa[0][11] mapa[1][0] mapa[1][1] ...
 *   \___________ fila 0 _______________/ \_______ fila 1 ______ ...
 *
 *   mapa[i][j]  esta en la casilla numero  i * MAPA_COLS + j
 *   mapa[i][j]  es lo mismo que            *(*(mapa + i) + j)
 *
 * Es la cinta de la maquina de Turing (Lab 03), doblada en filas.
 *
 * Las firmas son EXACTAS: no las cambies, las pruebas las usan asi.
 * ========================================================================= */
#ifndef MAPA_H
#define MAPA_H

#define MAPA_FILAS 8
#define MAPA_COLS  12

/* Las matrices de numeros se declaran de MAT_MAX x MAT_MAX y se usa solo
 * la esquina de arriba a la izquierda (filas x cols). */
#define MAT_MAX 10

/* ---------------------------------------------------------------- el mapa
 * Simbolos:  '#' muro   '.' pasillo   '@' heroe   'E' enemigo   'T' tesoro
 * El mapa NO guarda texto: son caracteres sueltos, sin '\0' al final.     */

/* DADA. Llena el mapa con el nivel 1 del dungeon. */
void mapa_cargar(char mapa[MAPA_FILAS][MAPA_COLS]);

/* DADA. Dibuja el mapa en pantalla, fila por fila. */
void mapa_imprimir(char mapa[MAPA_FILAS][MAPA_COLS]);

/* DADA. Muestra la direccion en memoria de algunas casillas: la prueba de
 * que la matriz es una sola fila. */
void mapa_imprimir_memoria(char mapa[MAPA_FILAS][MAPA_COLS]);

/* Devuelve el simbolo de la casilla (fila, col), usando SOLO aritmetica de
 * punteros (sin corchetes). Si la casilla esta fuera del mapa, devuelve
 * '\0' sin leer la memoria. */
char mapa_celda(char mapa[MAPA_FILAS][MAPA_COLS], int fila, int col);

/* Cuantas casillas del mapa tienen ese simbolo. Usa mapa_celda. */
int mapa_contar(char mapa[MAPA_FILAS][MAPA_COLS], char simbolo);

/* ------------------------------------------------------- la tabla de dano
 * A (filas_a x cols_a) por B (filas_b x cols_b) da C (filas_a x cols_b):
 *
 *   C[i][j] = A[i][0]*B[0][j] + A[i][1]*B[1][j] + ... + A[i][k]*B[k][j]
 *
 * En el juego: A = heroes x atributos, B = atributos x enemigos, y
 * C = cuanto dano le hace cada heroe a cada enemigo.                      */

/* DADA. Muestra la esquina filas x cols de M. */
void matriz_imprimir(int M[][MAT_MAX], int filas, int cols);

/* C = A x B. Devuelve 1 si multiplico, y 0 si NO se puede: cols_a != filas_b,
 * o alguna dimension fuera de 1..MAT_MAX. Si devuelve 0, NO toca C. */
int matriz_multiplicar(int A[][MAT_MAX], int filas_a, int cols_a,
                       int B[][MAT_MAX], int filas_b, int cols_b,
                       int C[][MAT_MAX]);

#endif /* MAPA_H */
