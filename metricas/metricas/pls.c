#include "../../ordenes/ordenes.h"
#include "../metricas.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>



char* pls(int *size, order *orders) {
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
            strcpy(pizzaNames[unique], orders[i].pizza_name);
            unique++;
        }
    }

    // Buscar el ID con menos ventas
    //recorre la fila revisando que  numero es mas grande y el que sea mas grande... la posicion de este se guarda en Max index
    int minIndex = 0;
    for (int i = 1; i < unique; i++) {
        if (pizzaCounts[i] < pizzaCounts[minIndex]) {  //si el dato es menor al que tengo guardado ahora lo remplazaos por ese
            minIndex = i;
        }
    }

    // Preparar el resultado
    char *result = malloc(128);
    sprintf(result, "Pizza menos vendida: %s", pizzaNames[minIndex]);
    return result;
}
//Dia con mas ingresos

