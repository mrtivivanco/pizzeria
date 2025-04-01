#include "../../ordenes/ordenes.h"
#include "../metricas.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MAX_DATES 100
#define DATE_LENGTH 16

// Fechas con más ventas en términos de cantidad de pizzas
char* dmsp(int *size, order *orders) {
    if (size == NULL || orders == NULL || *size <= 0) {
        return NULL;
    }

    int unique = 0;
    char orderDates[MAX_DATES][DATE_LENGTH];       // Fechas únicas
    int pizzasPerDay[MAX_DATES] = {0};    // Cantidad de pizzas por cada fecha

    // Recorre las órdenes y acumula las pizzas vendidas por día
    for (int i = 0; i < *size; i++) {
        char *date = orders[i].order_date;
        int pizzas = orders[i].quantity;  // Usamos quantity para contar las pizzas

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

    // Encontrar el día con más ventas de pizzas
    int maxIndex = 0;
    for (int i = 1; i < unique; i++) {
        if (pizzasPerDay[i] > pizzasPerDay[maxIndex]) {
            maxIndex = i;
        }
    }

    // Preparar el resultado
    char *result = malloc(128);
    if (result == NULL) {
        perror("Error al asignar memoria");
        exit(EXIT_FAILURE);
    }
    snprintf(result, 128, "Fecha con más ventas de pizzas: %s con un total de %d pizzas", orderDates[maxIndex], pizzasPerDay[maxIndex]);
    return result;
}
