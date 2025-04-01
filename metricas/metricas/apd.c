#include "../../ordenes/ordenes.h"
#include "../metricas.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_DATES 100
#define DATE_LENGTH 16

// Promedio de pizzas por día
char* apd(int *size, order *orders) {
    if (size == NULL || orders == NULL || *size <= 0) {
        return NULL;
    }

    int unique = 0;
    char orderDates[MAX_DATES][DATE_LENGTH];  // Fechas únicas
    int pizzasPerDay[MAX_DATES] = {0};        // Pizzas vendidas por día
    // Contar pizzas por día
    for (int i = 0; i < *size; i++) {
        char *date = orders[i].order_date;
        int pizzas = orders[i].quantity;

        int found = 0;
        for (int j = 0; j < unique; j++) {
            if (strcmp(orderDates[j], date) == 0) {
                pizzasPerDay[j] += pizzas;
                found = 1;
                break;
            }
        }

        if (!found) {
            strncpy(orderDates[unique], date, DATE_LENGTH - 1);
            orderDates[unique][DATE_LENGTH - 1] = '\0'; // Asegura la terminación nula
            pizzasPerDay[unique] = pizzas;
            unique++;
        }
    }

    // Calcular el promedio de pizzas por día
    int totalPizzas = 0;
    for (int i = 0; i < unique; i++) {
        totalPizzas += pizzasPerDay[i];
    }

    double average = (unique > 0) ? (double)totalPizzas / unique : 0.0;

    // Preparar el resultado
    char *result = malloc(128);
    if (result == NULL) {
        perror("Error al asignar memoria");
        exit(EXIT_FAILURE);
    }
    snprintf(result, 128, "Promedio de pizzas por día: %.2f", average);
    return result;
}

    
