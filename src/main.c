/* ===========================================================================
 * main.c  -  La Posada: el menu principal de Dungeon Quest.
 * ---------------------------------------------------------------------------
 * ESTE ARCHIVO CRECE CADA SEMANA.
 *
 * Cada laboratorio agrega un modulo nuevo (un .h en include/ y un .c en
 * src/) y una opcion a este menu. Al final del semestre, desde aqui se
 * juega todo el proyecto.
 *
 * Reglas de main.c:
 *   - aqui NO va la logica: solo el menu y las llamadas a los modulos
 *   - cada opcion termina con pausa() para que se alcance a leer
 *   - srand() se llama UNA vez, al principio
 * ========================================================================= */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "inventario.h"
#include "entrada.h"
#include "hechizos.h"
#include "cronometro.h"
#include "guardian.h"
#include "bestiario.h"
#include "combate.h"

/* Prototipos: C lee de arriba a abajo. Si main() llama a una funcion que
 * esta escrita mas abajo, hay que anunciarla aqui o el compilador dice
 * "implicit declaration of function". 'static' = solo se ve en este archivo. */
static void mostrar_menu(void);
static void ver_hechizos(void);
static void ver_inventario(void);
static void explorar_dungeon(void);

int main(void)
{
    srand((unsigned) time(NULL));

    int opcion;
    do {
        mostrar_menu();
        opcion = get_int("   Tu opcion: ");

        switch (opcion) {
            case 1:
                ver_hechizos();
                pausa();
                break;

            case 2:
                cronometro_tabla();
                pausa();
                break;

            case 3:
                guardian_jugar(7);
                pausa();
                break;

            case 4:
                ver_inventario();
                pausa();
                break;

            case 5:
                explorar_dungeon();
                pausa();
                break;

            case 0:
                printf("\n   Hasta la proxima, aventurero.\n\n");
                break;

            default:
                printf("   Opcion invalida.\n");
                break;
        }
    } while (opcion != 0);

    return EXIT_SUCCESS;
}

static void mostrar_menu(void)
{
    printf("\n   ==========================================\n");
    printf("      DUNGEON QUEST  -  La Posada\n");
    printf("   ==========================================\n");
    printf("    1) Los hechizos del Lab 01, en C\n");
    printf("    2) El cronometro: C contra Python\n");
    printf("    3) La puerta del guardian\n");
    printf("    4) El inventario del heroe\n");
    printf("    5) Explorar el dungeon\n");
    printf("    0) Salir\n\n");
}

static void ver_hechizos(void)
{
    printf("\n   --- Los cuatro hechizos ---\n\n");
    printf("   mcd(1071, 462)  = %ld\n",  mcd(1071, 462));
    printf("   fibonacci(10)   = %lld\n", fibonacci(10));
    printf("   simple_loop(7)  = %ld\n",  simple_loop(7));
    printf("   double_loop(4)  = %ld\n",  double_loop(4));

    printf("\n   --- Lo que Python te ocultaba ---\n\n");
    printf("   fibonacci(92)   = %lld\n", fibonacci(92));
    printf("   fibonacci(93)   = %lld\n", fibonacci(93));
    printf("\n   Si fibonacci(93) te sale negativo: explicalo en docs/informe_lab06.md\n");
}

static void ver_inventario(void)
{
    printf("\n   --- El inventario del heroe ---\n\n");
    Item *mochila = NULL;
    int cantidad = 0;
    int capacidad = 0;

    inventario_agregar(&mochila, &cantidad, &capacidad, "Espada de Acero", 'W', 4.5f);
    inventario_agregar(&mochila, &cantidad, &capacidad, "Pocion de Vida", 'P', 0.5f);
    inventario_agregar(&mochila, &cantidad, &capacidad, "Cota de Malla", 'R', 12.0f);

    inventario_imprimir(mochila, cantidad);
    inventario_liberar(mochila, cantidad);
}

static void explorar_dungeon(void)
{
    printf("\n   --- Explorar el dungeon ---\n\n");

    Luchador heroe = {"Aventurero", 60, 12};
    NodoEnemigo *bestiario = NULL;

    bestiario_agregar(&bestiario, "Goblin", 20, 4);
    bestiario_agregar(&bestiario, "Orco", 35, 8);
    bestiario_insertar(&bestiario, 1, "Esqueleto", 15, 5);
    bestiario_agregar(&bestiario, "Dragon", 100, 25);

    printf("   Enemigos en el dungeon:\n");
    bestiario_imprimir(bestiario);
    printf("\n   %s entra con %d de vida y %d de ataque.\n\n",
           heroe.nombre, heroe.vida, heroe.ataque);

    for (NodoEnemigo *e = bestiario; e != NULL && heroe.vida > 0; e = e->siguiente) {
        printf("   Combate contra %s (vida %d, ataque %d)... ",
               e->nombre, e->vida, e->ataque);
        if (combate_pelear(&heroe, e)) {
            printf("Victoria! (Vida restante del heroe: %d)\n", heroe.vida);
        } else {
            printf("Derrota! El heroe ha caido.\n");
        }
    }

    bestiario_purgar(&bestiario);

    printf("\n   Supervivientes en el dungeon tras purgar derrotados:\n");
    bestiario_imprimir(bestiario);

    bestiario_liberar(bestiario);
}