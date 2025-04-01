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


