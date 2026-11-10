

#include "inventario.h"

#include <stdio.h>
#include <stdlib.h>    
#include <string.h>    


static char *copiar_texto(const char *texto)
{
    char *copia = malloc(strlen(texto) + 1);     
    if (copia != NULL) {
        strcpy(copia, texto);
    }
    return copia;
}

int inventario_agregar(Item **inv, int *cantidad, int *capacidad,
                       const char *nombre, char tipo, float peso)
{
    if (*capacidad == 0) {
        *inv = malloc(2 * sizeof(Item));
        if (*inv == NULL) {
            return 0;
        }
        *capacidad = 2;
    }

    if (*cantidad >= *capacidad) {
        Item *nueva = realloc(*inv, (*capacidad) * 2 * sizeof(Item));
        if (nueva == NULL) {
            return 0; 
        }
        *inv = nueva;
        *capacidad *= 2;
    }


    (*inv)[*cantidad].nombre = copiar_texto(nombre);
    if ((*inv)[*cantidad].nombre == NULL) {
        return 0;
    }
    (*inv)[*cantidad].tipo = tipo;
    (*inv)[*cantidad].peso = peso;


    (*cantidad)++;
    return 1;
}

float inventario_peso(const Item *inv, int cantidad)
{
    float peso_total = 0.0f;
    for (int i = 0; i < cantidad; i++) {
        peso_total += inv[i].peso;
    }
    return peso_total;
}

void inventario_imprimir(const Item *inv, int cantidad)
{
    if (cantidad == 0) {
        printf("  La mochila esta vacia.\n");
        return;
    }

    for (int i = 0; i < cantidad; i++) {
        const char *tipo_str = "Varios";
        switch (inv[i].tipo) {
            case 'A':
            case 'a':
                tipo_str = "Arma";
                break;
            case 'R':
            case 'r':
                tipo_str = "Armadura";
                break;
            case 'P':
            case 'p':
                tipo_str = "Pocion";
                break;
            default:
                tipo_str = "Varios";
                break;
        }
        printf("  - [%s] %s (%.2f kg)\n", tipo_str, inv[i].nombre, inv[i].peso);
    }
    printf("  Peso total: %.2f kg\n", inventario_peso(inv, cantidad));
}

void inventario_liberar(Item *inv, int cantidad)
{
    if (inv == NULL) {
        return;
    }


    for (int i = 0; i < cantidad; i++) {
        free(inv[i].nombre);
    }


    free(inv);
}