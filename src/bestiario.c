/* ===========================================================================
 * bestiario.c  -  TU TRABAJO del Lab 08: la lista enlazada.
 * ---------------------------------------------------------------------------
 * Orden recomendado: agregar -> liberar -> insertar -> purgar.
 * Despues de cada una: probar.bat  (o make test).
 * ========================================================================= */

#include "bestiario.h"

#include <stdio.h>
#include <stdlib.h>    /* malloc, free */
#include <string.h>    /* strlen, strcpy */

/* DADA. Una COPIA nueva del texto, pedida con malloc (o NULL si no hubo
 * memoria). Es la misma de la mochila. Se libera con free. */
static char *copiar_texto(const char *texto)
{
    char *copia = malloc(strlen(texto) + 1);      /* +1 para el '\0' final */
    if (copia != NULL) {
        strcpy(copia, texto);
    }
    return copia;
}

/* DADA. Pide un nodo con su nombre copiado y siguiente en NULL.
 * Devuelve NULL si no hubo memoria (y no deja nada a medias). */
static NodoEnemigo *nuevo_enemigo(const char *nombre, int vida, int ataque)
{
    NodoEnemigo *e = malloc(sizeof(NodoEnemigo));
    if (e == NULL) {
        return NULL;
    }
    e->nombre = copiar_texto(nombre);
    if (e->nombre == NULL) {
        free(e);
        return NULL;
    }
    e->vida = vida;
    e->ataque = ataque;
    e->siguiente = NULL;
    return e;
}

int bestiario_agregar(NodoEnemigo **cabeza, const char *nombre, int vida, int ataque)
{
    if (cabeza == NULL) {
        return 0;
    }

    NodoEnemigo *nuevo = nuevo_enemigo(nombre, vida, ataque);
    if (nuevo == NULL) {
        return 0;
    }

    if (*cabeza == NULL) {
        *cabeza = nuevo;
    } else {
        NodoEnemigo *p = *cabeza;
        while (p->siguiente != NULL) {
            p = p->siguiente;
        }
        p->siguiente = nuevo;
    }

    return 1;
}

int bestiario_insertar(NodoEnemigo **cabeza, int pos, const char *nombre, int vida, int ataque)
{
    if (cabeza == NULL) {
        return 0;
    }

    NodoEnemigo *nuevo = nuevo_enemigo(nombre, vida, ataque);
    if (nuevo == NULL) {
        return 0;
    }

    if (pos <= 0 || *cabeza == NULL) {
        nuevo->siguiente = *cabeza;
        *cabeza = nuevo;
    } else {
        NodoEnemigo *anterior = *cabeza;
        int paso = 0;
        while (paso < pos - 1 && anterior->siguiente != NULL) {
            anterior = anterior->siguiente;
            paso++;
        }
        nuevo->siguiente = anterior->siguiente;
        anterior->siguiente = nuevo;
    }

    return 1;
}

void bestiario_purgar(NodoEnemigo **cabeza)
{
    if (cabeza == NULL) {
        return;
    }

    /* 1. Eliminar nodos derrotados al inicio de la lista */
    while (*cabeza != NULL && (*cabeza)->vida <= 0) {
        NodoEnemigo *muerto = *cabeza;
        *cabeza = muerto->siguiente;
        free(muerto->nombre);
        free(muerto);
    }

    /* 2. Eliminar nodos derrotados en el resto de la lista */
    NodoEnemigo *p = *cabeza;
    while (p != NULL && p->siguiente != NULL) {
        if (p->siguiente->vida <= 0) {
            NodoEnemigo *muerto = p->siguiente;
            p->siguiente = muerto->siguiente;
            free(muerto->nombre);
            free(muerto);
        } else {
            p = p->siguiente;
        }
    }
}

void bestiario_imprimir(const NodoEnemigo *cabeza)
{
    if (cabeza == NULL) {
        printf("  (el bestiario esta vacio)\n");
        return;
    }
    for (const NodoEnemigo *e = cabeza; e != NULL; e = e->siguiente) {
        printf("  %-14s vida %4d   ataque %3d\n", e->nombre, e->vida, e->ataque);
    }
}

void bestiario_liberar(NodoEnemigo *cabeza)
{
    while (cabeza != NULL) {
        NodoEnemigo *sig = cabeza->siguiente;
        free(cabeza->nombre);
        free(cabeza);
        cabeza = sig;
    }
}