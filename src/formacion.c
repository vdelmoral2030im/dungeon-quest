/* ===========================================================================
 * formacion.c  -  TU TRABAJO del Lab 09: la lista doble.
 * ---------------------------------------------------------------------------
 * formacion_insertar_inicio ya esta hecha: es tu MODELO. Leela con calma
 * antes de escribir insertar_final, que es su espejo.
 * ========================================================================= */

#include "formacion.h"

#include <stdio.h>
#include <stdlib.h>    /* malloc, free */
#include <string.h>    /* strncpy, strcmp */

/* DADA. Pide un miembro nuevo con su nombre y los dos enlaces en NULL. */
static Miembro *nuevo_miembro(const char *nombre)
{
    Miembro *m = malloc(sizeof(Miembro));
    if (m != NULL) {
        strncpy(m->nombre, nombre, LARGO_NOMBRE - 1);
        m->nombre[LARGO_NOMBRE - 1] = '\0';
        m->ant = NULL;
        m->sig = NULL;
    }
    return m;
}

void formacion_iniciar(Formacion *f)
{
    f->primero = NULL;
    f->ultimo = NULL;
    f->cantidad = 0;
}

int formacion_insertar_inicio(Formacion *f, const char *nombre)
{
    Miembro *m = nuevo_miembro(nombre);
    if (m == NULL) {
        return 0;
    }
    if (f->primero == NULL) {          /* formacion vacia: es primero Y ultimo */
        f->primero = m;
        f->ultimo = m;
    } else {                           /* va delante del primero actual */
        m->sig = f->primero;           /* enlace y...                  */
        f->primero->ant = m;           /* ...su pareja                 */
        f->primero = m;
    }
    f->cantidad++;
    return 1;
}

int formacion_insertar_final(Formacion *f, const char *nombre)
{
    if (f == NULL || nombre == NULL) {
        return 0;
    }

    Miembro *m = nuevo_miembro(nombre);
    if (m == NULL) {
        return 0;
    }

    if (f->ultimo == NULL) {           /* formacion vacia: es primero Y ultimo */
        f->primero = m;
        f->ultimo = m;
    } else {                           /* va detras del ultimo actual */
        m->ant = f->ultimo;            /* enlace y...                 */
        f->ultimo->sig = m;            /* ...su pareja                */
        f->ultimo = m;
    }

    f->cantidad++;
    return 1;
}

int formacion_contiene(const Formacion *f, const char *nombre)
{
    if (f == NULL || nombre == NULL) {
        return 0;
    }

    for (const Miembro *m = f->primero; m != NULL; m = m->sig) {
        if (strcmp(m->nombre, nombre) == 0) {
            return 1;
        }
    }
    return 0;
}

int formacion_eliminar(Formacion *f, const char *nombre)
{
    if (f == NULL || nombre == NULL) {
        return 0;
    }

    Miembro *m = f->primero;
    while (m != NULL && strcmp(m->nombre, nombre) != 0) {
        m = m->sig;
    }

    if (m == NULL) {
        return 0;
    }

    if (m->ant != NULL) {
        m->ant->sig = m->sig;
    } else {
        f->primero = m->sig;
    }

    if (m->sig != NULL) {
        m->sig->ant = m->ant;
    } else {
        f->ultimo = m->ant;
    }

    free(m);
    f->cantidad--;
    return 1;
}

void formacion_imprimir(const Formacion *f)
{
    printf("  Adelante -> atras: ");
    for (const Miembro *m = f->primero; m != NULL; m = m->sig) {
        printf("%s%s", m->nombre, m->sig ? " <-> " : "");
    }
    printf("%s\n", f->primero ? "" : "(vacia)");
}

void formacion_imprimir_reversa(const Formacion *f)
{
    printf("  Atras -> adelante: ");
    for (const Miembro *m = f->ultimo; m != NULL; m = m->ant) {
        printf("%s%s", m->nombre, m->ant ? " <-> " : "");
    }
    printf("%s\n", f->ultimo ? "" : "(vacia)");
}

static void imprimir_reversa_nodos(const Miembro *m, int es_ultimo)
{
    if (m == NULL) {
        return;
    }
    imprimir_reversa_nodos(m->sig, 0);
    printf("%s%s", m->nombre, es_ultimo ? "" : " <-> ");
}

/* Bono (+2): imprime la formacion al reves sin usar 'ant', solo con recursion. */
void formacion_imprimir_reversa_rec(const Formacion *f)
{
    printf("  Reversa recursiva: ");
    if (f == NULL || f->primero == NULL) {
        printf("(vacia)\n");
        return;
    }
    imprimir_reversa_nodos(f->primero, 1);
    printf("\n");
}

void formacion_liberar(Formacion *f)
{
    if (f == NULL) {
        return;
    }

    Miembro *m = f->primero;
    while (m != NULL) {
        Miembro *sig = m->sig;     /* se guarda ANTES del free */
        free(m);
        m = sig;
    }
    formacion_iniciar(f);
}