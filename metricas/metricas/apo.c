#include "../../ordenes/ordenes.h"
#include "../metricas.h"
#include <stdlib.h>
#include <stdio.h>

// Promedio de pizzas por orden
char* apo(int *size, order *orders) {
    if (size == NULL || orders == NULL || *size <= 0) {
        return NULL;
    }

    int totalPizzas = 0;
    int totalOrders = 0;

    for (int i = 0; i < *size; i++) {
        totalPizzas += orders[i].quantity;
        totalOrders++;
    }

    double average = (totalOrders > 0) ? (double)totalPizzas / totalOrders : 0.0;

    char *result = malloc(128);
    if (result == NULL) {
        perror("Error al asignar memoria");
        exit(EXIT_FAILURE);
    }
    snprintf(result, 128, "Promedio de pizzas por orden: %.2f", average);
    return result;
}

