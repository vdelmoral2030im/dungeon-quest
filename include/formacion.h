/* ===========================================================================
 * formacion.h  -  El orden de marcha: una LISTA DOBLE.               [Lab 09]
 * ---------------------------------------------------------------------------
 * Cada miembro conoce al de adelante (ant) y al de atras (sig), asi que la
 * fila se puede recorrer en los dos sentidos:
 *
 *   primero                                         ultimo
 *     |                                               |
 *     v                                               v
 *   [Ana] <-> [Beto] <-> [Caro]           ant del primero == NULL
 *                                         sig del ultimo  == NULL
 *
 * La regla de oro: cada vez que tocas un enlace, tocas su pareja. Si
 * x->sig == y, entonces y->ant == x. Siempre.
 *
 * Las firmas son EXACTAS: no las cambies, las pruebas las usan asi.
 * ========================================================================= */
#ifndef FORMACION_H
#define FORMACION_H

#define LARGO_NOMBRE 32

typedef struct Miembro {
    char            nombre[LARGO_NOMBRE];
    struct Miembro *ant;
    struct Miembro *sig;
} Miembro;

/* La fila completa. Vacia: primero == NULL, ultimo == NULL, cantidad == 0. */
typedef struct {
    Miembro *primero;
    Miembro *ultimo;
    int      cantidad;
} Formacion;

/* DADA. Deja la formacion vacia. */
void formacion_iniciar(Formacion *f);

/* DADA (es tu modelo). Agrega al PRINCIPIO. 1 si lo agrego, 0 sin memoria. */
int formacion_insertar_inicio(Formacion *f, const char *nombre);

/* Agrega al FINAL. 1 si lo agrego, 0 si no hubo memoria. */
int formacion_insertar_final(Formacion *f, const char *nombre);

/* 1 si hay un miembro con ese nombre, 0 si no. */
int formacion_contiene(const Formacion *f, const char *nombre);

/* Quita al primer miembro con ese nombre y lo libera, reenlazando a sus
 * vecinos. 1 si lo quito, 0 si no estaba (la formacion queda intacta). */
int formacion_eliminar(Formacion *f, const char *nombre);

/* DADAS. Muestran la fila de adelante hacia atras, y de atras hacia adelante. */
void formacion_imprimir(const Formacion *f);
void formacion_imprimir_reversa(const Formacion *f);

/* DADA. Libera todos los miembros y deja la formacion vacia. */
void formacion_liberar(Formacion *f);

#endif /* FORMACION_H */
