/* ===========================================================================
 * entrada.c  -  MODULO DADO. La implementacion de entrada.h
 * ========================================================================= */

#include "entrada.h"

#include <stdio.h>
#include <string.h>

#define TAM_LINEA 128

int get_int(const char *mensaje)
{
    char linea[TAM_LINEA];
    int valor;

    while (1) {
        printf("%s", mensaje);
        fflush(stdout);

        if (fgets(linea, sizeof linea, stdin) == NULL) {
            return 0;                         /* se acabo la entrada */
        }
        if (sscanf(linea, "%d", &valor) == 1) {
            return valor;                     /* habia un numero */
        }
        printf("  Eso no es un numero. Intenta de nuevo.\n");
    }
}

int get_texto(const char *mensaje, char *destino, int capacidad)
{
    printf("%s", mensaje);
    fflush(stdout);

    if (fgets(destino, capacidad, stdin) == NULL) {
        destino[0] = '\0';
        return 0;
    }

    /* fgets guarda tambien el Enter: lo quitamos */
    destino[strcspn(destino, "\r\n")] = '\0';
    return 1;
}

void pausa(void)
{
    printf("\n  (pulsa Enter para continuar)");
    fflush(stdout);

    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        /* descartar hasta el Enter */
    }
    printf("\n");
}
