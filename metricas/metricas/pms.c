#include "../../ordenes/ordenes.h"
#include "../metricas.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

 //tenemos 100 tipos de pizzas en vacio (rellenadas con 0)
char* pms(int *size, order *orders) {
    int unique = 0;
    int pizzaIds[100];               // IDs únicos
    int pizzaCounts[100] = {0};      // Total vendidos por ID
    char pizzaNames[100][64];        // Nombres asociados al ID

    // Contar pizzas por ID
    for (int i = 0; i < *size; i++) {
        int id = orders[i].pizza_id;
        int qty = orders[i].quantity;
//guarda la informacion de la pizza id y de la quantity, cada fila cada vez que va pasando
        int found = 0;
        for (int j = 0; j < unique; j++) {
            if (pizzaIds[j] == id) {
                pizzaCounts[j] += qty;
                found = 1;
                break;
            }
        }

        if (!found) {
            pizzaIds[unique] = id;
            pizzaCounts[unique] = qty;
            printf("Pizzaname: %s\n", orders[i].pizza_name);
            strcpy(pizzaNames[unique], orders[i].pizza_name);
            unique++;
        }
    }

    // Buscar el ID con más ventas
    //recorre la fila revisando que  numero es mas grande y el que sea mas grande... la posicion de este se guarda en Max index
    int maxIndex = 0;
    for (int i = 1; i < unique; i++) {
        if (pizzaCounts[i] > pizzaCounts[maxIndex]) {
            maxIndex = i;
        }
    }

    printf("El max es: %d\n", maxIndex);

    // Preparar el resultado
    char *result = malloc(128);
    sprintf(result, "Pizza más vendida: %s", pizzaNames[maxIndex]);
    return result;
}
