/* ===========================================================================
 * combate.c  -  TU TRABAJO del Lab 08: el combate.
 * ========================================================================= */

#include "combate.h"
#include <stddef.h>

int combate_pelear(Luchador *heroe, NodoEnemigo *enemigo)
{
    if (heroe == NULL || enemigo == NULL) {
        return 0;
    }

    if (heroe->vida <= 0) {
        return 0;
    }

    if (enemigo->vida <= 0) {
        return 1;
    }

    if (heroe->ataque <= 0 && enemigo->ataque <= 0) {
        return 0;
    }

    while (1) {
        enemigo->vida -= heroe->ataque;
        if (enemigo->vida <= 0) {
            return 1;
        }

        heroe->vida -= enemigo->ataque;
        if (heroe->vida <= 0) {
            return 0;
        }
    }
}