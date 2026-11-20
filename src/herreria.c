/* ===========================================================================
 * herreria.c  -  TU TRABAJO del Lab 09: la cola del herrero.
 * ---------------------------------------------------------------------------
 * Orden recomendado: encolar -> atender -> liberar. Despues de cada una:
 * probar.bat  (o make test).
 * ========================================================================= */

#include "herreria.h"

#include <stdio.h>
#include <stdlib.h>    /* malloc, free */
#include <string.h>    /* strncpy */

void herreria_iniciar(Herreria *h)
{
    h->head = NULL;
    h->tail = NULL;
    h->cantidad = 0;
}

int herreria_encolar(Herreria *h, const char *item)
{
    if (h == NULL || item == NULL) {
        return 0;
    }

    Pedido *nuevo = malloc(sizeof(Pedido));
    if (nuevo == NULL) {
        return 0;
    }

    strncpy(nuevo->item, item, LARGO_PEDIDO - 1);
    nuevo->item[LARGO_PEDIDO - 1] = '\0';
    nuevo->sig = NULL;

    if (h->tail == NULL) {
        h->head = nuevo;
        h->tail = nuevo;
    } else {
        h->tail->sig = nuevo;
        h->tail = nuevo;
    }

    h->cantidad++;
    return 1;
}

int herreria_atender(Herreria *h, char *destino)
{
    if (h == NULL || h->head == NULL) {
        return 0;
    }

    Pedido *viejo = h->head;

    if (destino != NULL) {
        strncpy(destino, viejo->item, LARGO_PEDIDO - 1);
        destino[LARGO_PEDIDO - 1] = '\0';
    }

    h->head = viejo->sig;
    if (h->head == NULL) {
        h->tail = NULL;
    }

    free(viejo);
    h->cantidad--;
    return 1;
}

void herreria_imprimir(const Herreria *h)
{
    if (h->head == NULL) {
        printf("  (no hay pedidos)\n");
        return;
    }
    int i = 1;
    for (const Pedido *p = h->head; p != NULL; p = p->sig) {
        printf("  %d. %s\n", i++, p->item);
    }
}

void herreria_liberar(Herreria *h)
{
    if (h == NULL) {
        return;
    }

    Pedido *p = h->head;
    while (p != NULL) {
        Pedido *sig = p->sig;
        free(p);
        p = sig;
    }

    herreria_iniciar(h);
}