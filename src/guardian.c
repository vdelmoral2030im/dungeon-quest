/* ===========================================================================
 * guardian.c  -  TU TRABAJO del Lab 06.
 * ========================================================================= */

#include "guardian.h"
#include "entrada.h"

#include <stdio.h>
#include <stdlib.h>    /* rand */

int guardian_comparar(int secreto, int intento)
{
    if (secreto > intento) {
        return 1;
    } else if (secreto < intento) {
        return -1;
    } else {
        return 0;
    }
}

int guardian_jugar(int intentos)
{
    int secreto = rand() % 100 + 1;

    printf("\n  El guardian piensa un numero del 1 al 100. Tienes %d intentos.\n\n", intentos);

    for (int i = 1; i <= intentos; i++) {
        printf("  Intento %d de %d\n", i, intentos);
        int intento = get_int("  Tu clave: ");
        int cmp = guardian_comparar(secreto, intento);

        if (cmp == 0) {
            printf("\n  La puerta se abre. Acertaste!\n");
            return 1;
        } else if (cmp > 0) {
            printf("  La clave es mas alta.\n\n");
        } else {
            printf("  La clave es mas baja.\n\n");
        }
    }

    printf("\n  Se acabaron los intentos. La clave era %d.\n", secreto);
    return 0;
}
