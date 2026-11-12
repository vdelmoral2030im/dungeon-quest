/* ===========================================================================
 * bestiario.h  -  Los enemigos del dungeon: una LISTA ENLAZADA.   [Lab 08]   
 * ---------------------------------------------------------------------------
 * La mochila era un arreglo: todo seguido en memoria. El bestiario son NODOS
 * sueltos; cada uno sabe donde esta el siguiente:
 *
 *   cabeza
 *     |
 *     v
 *   [Goblin] -> [Orco] -> [Dragon] -> NULL
 *
 * Insertar o quitar un enemigo en medio no mueve a los demas: solo se
 * cambian punteros.
 *
 * POR QUE  NodoEnemigo **cabeza : agregar al principio o purgar al primero
 * CAMBIA la cabeza, y la cabeza es una variable de quien llama. Igual que
 * el  Item **inv  de la mochila.
 *
 * Las firmas son EXACTAS: no las cambies, las pruebas las usan asi.
 * ========================================================================= */
#ifndef BESTIARIO_H
#define BESTIARIO_H

typedef struct NodoEnemigo {
    char               *nombre;     /* COPIA propia, pedida con malloc */
    int                 vida;
    int                 ataque;
    struct NodoEnemigo *siguiente;
} NodoEnemigo;

/* Agrega un enemigo al FINAL. 1 si lo agrego, 0 si no hubo memoria.
 * La lista empieza vacia:   NodoEnemigo *bestiario = NULL;
 * y se usa asi:             bestiario_agregar(&bestiario, "Goblin", 20, 4); */
int bestiario_agregar(NodoEnemigo **cabeza, const char *nombre, int vida, int ataque);

/* Inserta un enemigo en la posicion pos (0 = al principio). Si pos es
 * negativa, va al principio; si es mayor que el largo, va al final.
 * 1 si lo inserto, 0 si no hubo memoria. */
int bestiario_insertar(NodoEnemigo **cabeza, int pos, const char *nombre, int vida, int ataque);

/* Quita y libera a todos los enemigos con vida <= 0. */
void bestiario_purgar(NodoEnemigo **cabeza);

/* DADA. Muestra la lista, un enemigo por linea. */
void bestiario_imprimir(const NodoEnemigo *cabeza);

/* Libera TODA la lista: el nombre de cada nodo y el nodo. */
void bestiario_liberar(NodoEnemigo *cabeza);

#endif /* BESTIARIO_H */
