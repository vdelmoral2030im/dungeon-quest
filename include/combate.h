/* ===========================================================================
 * combate.h  -  El heroe contra un enemigo, por turnos.          [Lab 08]   
 * ========================================================================= */
#ifndef COMBATE_H
#define COMBATE_H

#include "bestiario.h"

/* El heroe. Su nombre es un arreglo fijo: una COPIA dentro del struct, no
 * un puntero a otro lado (compara con el char * del NodoEnemigo). */
typedef struct {
    char nombre[32];
    int  vida;
    int  ataque;
} Luchador;

/* Pelean por turnos hasta que uno llega a 0. El HEROE golpea primero:
 *   - le resta su ataque a la vida del enemigo; si el enemigo queda en
 *     vida <= 0, gana el heroe
 *   - si no, el enemigo le resta su ataque a la vida del heroe; si el heroe
 *     queda en vida <= 0, pierde
 * Devuelve 1 si gana el heroe y 0 si pierde. Si ninguno de los dos puede
 * hacer dano (los dos ataques <= 0), devuelve 0 sin pelear: el heroe se
 * retira. Las vidas de los dos quedan modificadas: por eso son punteros. */
int combate_pelear(Luchador *heroe, NodoEnemigo *enemigo);

#endif /* COMBATE_H */
