#include "../../ordenes/ordenes.h"
#include "../metricas.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MAX_DATES 100
#define DATE_LENGTH 16

// Fecha con más ventas en términos de cantidad de pizzas
char* dmsp(int *size, order *orders) {
    int unique = 0;
    char orderDates[MAX_DATES][DATE_LENGTH];  // Fechas únicas
    int pizzasPerDay[MAX_DATES] = {0};        // Cantidad de pizzas por cada fecha

    // Contar pizzas vendidas por día
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
            strcpy(orderDates[unique], date);
            pizzasPerDay[unique] = pizzas;
            unique++;
        }
    }

    
