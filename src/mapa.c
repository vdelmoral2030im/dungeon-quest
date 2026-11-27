/* ===========================================================================
 * mapa.c  -  TU TRABAJO del Lab 10: el mapa y la tabla de dano.
 * ---------------------------------------------------------------------------
 * Orden recomendado: mapa_celda -> mapa_contar -> matriz_multiplicar.
 * Despues de cada una: probar.bat  (o make test).
 * ========================================================================= */

#include "mapa.h"

#include <stdio.h>

/* El nivel 1. Cada linea tiene exactamente MAPA_COLS caracteres. */
static const char *NIVEL_1[MAPA_FILAS] = {
    "############",
    "#@...#....T#",
    "#.##.#.##..#",
    "#..E...#E..#",
    "##.###.#.###",
    "#....#...E.#",
    "#.T#...#...#",
    "############",
};

void mapa_cargar(char mapa[MAPA_FILAS][MAPA_COLS])
{
    for (int i = 0; i < MAPA_FILAS; i++) {
        for (int j = 0; j < MAPA_COLS; j++) {
            mapa[i][j] = NIVEL_1[i][j];
        }
    }
}

void mapa_imprimir(char mapa[MAPA_FILAS][MAPA_COLS])
{
    for (int i = 0; i < MAPA_FILAS; i++) {
        printf("  ");
        for (int j = 0; j < MAPA_COLS; j++) {
            printf("%c", mapa[i][j]);
        }
        printf("\n");
    }
}

void mapa_imprimir_memoria(char mapa[MAPA_FILAS][MAPA_COLS])
{
    /* Las casillas del final de la fila 0 y del principio de la fila 1 */
    int casillas[][2] = { {0, 0}, {0, 1}, {0, 10}, {0, 11}, {1, 0}, {1, 1} };
    int n = (int) (sizeof(casillas) / sizeof(casillas[0]));

    printf("  casilla      direccion          bytes desde mapa[0][0]\n");
    for (int k = 0; k < n; k++) {
        int i = casillas[k][0];
        int j = casillas[k][1];
        char *p = &mapa[i][j];
        printf("  mapa[%d][%2d]  %p  %3ld\n", i, j, (void *) p, (long) (p - &mapa[0][0]));
    }
    printf("  (un char ocupa %zu byte; una fila entera, %zu bytes)\n",
           sizeof(char), sizeof(mapa[0]));
}

char mapa_celda(char mapa[MAPA_FILAS][MAPA_COLS], int fila, int col)
{
    /* Primero se mira si esta dentro; solo entonces se lee la memoria. */
    if (fila < 0 || fila >= MAPA_FILAS || col < 0 || col >= MAPA_COLS) {
        return '\0';
    }
    return *(*(mapa + fila) + col);
}

int mapa_contar(char mapa[MAPA_FILAS][MAPA_COLS], char simbolo)
{
    int cuenta = 0;
    for (int i = 0; i < MAPA_FILAS; i++) {
        for (int j = 0; j < MAPA_COLS; j++) {
            if (mapa_celda(mapa, i, j) == simbolo) {
                cuenta++;
            }
        }
    }
    return cuenta;
}

void matriz_imprimir(int M[][MAT_MAX], int filas, int cols)
{
    for (int i = 0; i < filas; i++) {
        printf("  [");
        for (int j = 0; j < cols; j++) {
            printf(" %4d", M[i][j]);
        }
        printf(" ]\n");
    }
}

int matriz_multiplicar(int A[][MAT_MAX], int filas_a, int cols_a,
                       int B[][MAT_MAX], int filas_b, int cols_b,
                       int C[][MAT_MAX])
{
    /* Precondicion: si no se puede, se cancela ANTES de escribir en C. */
    if (cols_a != filas_b) {
        return 0;
    }
    if (filas_a < 1 || filas_a > MAT_MAX ||
        cols_a  < 1 || cols_a  > MAT_MAX ||
        cols_b  < 1 || cols_b  > MAT_MAX) {
        return 0;
    }

    for (int i = 0; i < filas_a; i++) {
        for (int j = 0; j < cols_b; j++) {
            C[i][j] = 0;                      /* C puede traer basura */
            for (int k = 0; k < cols_a; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return 1;
}