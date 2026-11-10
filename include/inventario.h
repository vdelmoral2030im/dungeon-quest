/* ===========================================================================
 * inventario.h  -  La mochila del heroe: un arreglo que CRECE.        [Lab 07]
 * ---------------------------------------------------------------------------
 * En Python una lista crece sola:  mochila.append(item)
 * En C un arreglo tiene tamano FIJO. Para que crezca hay que pedir memoria
 * nueva al sistema (malloc / realloc) y devolverla al terminar (free).
 *
 * Las firmas son EXACTAS: no las cambies, las pruebas las usan asi.
 * ========================================================================= */

#ifndef INVENTARIO_H
#define INVENTARIO_H

/* Un objeto de la mochila.
 *
 *   nombre  es un PUNTERO a texto, no un arreglo: cada item guarda su
 *           propia COPIA del nombre, pedida con malloc (via copiar_texto).
 *           Por eso, al liberar, hay que liberar primero cada nombre.
 *   tipo    'W' arma, 'A' armadura, 'P' pocion, otro = varios
 */
typedef struct {
    char  *nombre;
    char   tipo;
    float  peso;
} Item;

/* Agrega un item al final de la mochila. Si esta llena, la AGRANDA.
 *
 *   inv        DIRECCION del puntero a la mochila  (Item **, ver abajo)
 *   cantidad   DIRECCION de cuantos items hay       (se incrementa)
 *   capacidad  DIRECCION de cuantos caben           (se duplica si hace falta)
 *
 * La mochila empieza vacia:   Item *mochila = NULL;  int n = 0, cap = 0;
 * y se usa asi:               inventario_agregar(&mochila, &n, &cap, "Espada", 'W', 3.5f);
 *
 * POR QUE  Item **inv  Y NO  Item *inv:
 * cuando la mochila crece, realloc puede MUDARLA a otra direccion. La
 * funcion tiene que poder cambiar el puntero `mochila` de quien la llama,
 * y para cambiar una variable de otro hay que recibir su direccion.
 * Es lo mismo que el  &r  de medir(simple_loop, n, &r), un nivel mas arriba.
 *
 * Devuelve 1 si lo agrego, 0 si no hubo memoria (la mochila queda intacta). */
int inventario_agregar(Item **inv, int *cantidad, int *capacidad,
                       const char *nombre, char tipo, float peso);

/* Suma de los pesos de todos los items. */
float inventario_peso(const Item *inv, int cantidad);

/* Imprime la mochila, un item por linea. */
void inventario_imprimir(const Item *inv, int cantidad);

/* Devuelve TODA la memoria: cada nombre y despues el arreglo.
 * Regla del curso: un free por cada malloc. */
void inventario_liberar(Item *inv, int cantidad);

#endif /* INVENTARIO_H */
