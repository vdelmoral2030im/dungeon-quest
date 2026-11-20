/* ===========================================================================
 * herreria.h  -  Los pedidos al herrero: una COLA.                   [Lab 09]
 * ---------------------------------------------------------------------------
 * El herrero atiende en orden de llegada: el primero que entra es el primero
 * que sale (FIFO). Cada pedido es un NODO que apunta al siguiente:
 *
 *    head                              tail
 *     |                                 |
 *     v                                 v
 *   [Espada] -> [Escudo] -> [Casco] -> NULL
 *
 *   encolar  agrega por el tail (al final)
 *   atender  saca por el head  (al principio)
 *
 * Con DOS punteros, head y tail, las dos operaciones son O(1): no hay que
 * recorrer nada.
 *
 * Las firmas son EXACTAS: no las cambies, las pruebas las usan asi.
 * ========================================================================= */
#ifndef HERRERIA_H
#define HERRERIA_H

#define LARGO_PEDIDO 32

/* Un pedido: el nombre del objeto (copia propia) y el siguiente de la fila. */
typedef struct Pedido {
    char           item[LARGO_PEDIDO];
    struct Pedido *sig;
} Pedido;

/* La cola completa. Vacia: head == NULL, tail == NULL, cantidad == 0. */
typedef struct {
    Pedido *head;
    Pedido *tail;
    int     cantidad;
} Herreria;

/* DADA. Deja la cola vacia. Llamala antes de usarla. */
void herreria_iniciar(Herreria *h);

/* Agrega un pedido al FINAL. Devuelve 1 si lo agrego, 0 si no hubo memoria. */
int herreria_encolar(Herreria *h, const char *item);

/* Saca el pedido del PRINCIPIO y copia su nombre en destino (que tiene
 * espacio para LARGO_PEDIDO caracteres). Devuelve 1 si atendio uno, 0 si la
 * cola estaba vacia (y entonces no toca destino). */
int herreria_atender(Herreria *h, char *destino);

/* DADA. Muestra la fila, del primero al ultimo. */
void herreria_imprimir(const Herreria *h);

/* Libera todos los pedidos que queden y deja la cola vacia. */
void herreria_liberar(Herreria *h);

#endif /* HERRERIA_H */
