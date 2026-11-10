/* ===========================================================================
 * prueba.h  -  Mini herramienta de pruebas.  NO LA MODIFIQUES.
 * ---------------------------------------------------------------------------
 * Es el `assert` del Lab 02, pero sin detener el programa al primer fallo:
 * cuenta cuantas pruebas pasan y cuantas fallan, y al final da el resumen.
 *
 * Cada laboratorio trae su archivo tests/test_labNN.c. Lo copias a tu
 * carpeta tests/ y corres  make test  (o probar.bat en Windows).
 * Tu meta de la semana: que todas pasen.
 * ========================================================================= */

#ifndef PRUEBA_H
#define PRUEBA_H

#include <stdio.h>

static int prueba_total  = 0;
static int prueba_fallas = 0;

/* VERIFICAR(condicion, "descripcion")
 * Si la condicion es verdadera imprime OK; si no, FALLA con el archivo y la
 * linea, y sigue con la proxima prueba. */
#define VERIFICAR(cond, desc)                                              \
    do {                                                                   \
        prueba_total++;                                                    \
        if (cond) {                                                        \
            printf("  OK     %s\n", (desc));                               \
        } else {                                                           \
            prueba_fallas++;                                               \
            printf("  FALLA  %s   (%s:%d)\n", (desc), __FILE__, __LINE__); \
        }                                                                  \
    } while (0)

/* RESUMEN("Lab NN") imprime el conteo y devuelve el numero de fallas,
 * para usarlo como  return RESUMEN("Lab 06");  al final del main.
 * Un programa que devuelve distinto de 0 le avisa a make que algo fallo. */
#define RESUMEN(nombre)                                                    \
    (printf("\n  %s: %d de %d pruebas pasan\n\n", (nombre),                \
            prueba_total - prueba_fallas, prueba_total),                   \
     prueba_fallas)

#endif /* PRUEBA_H */
