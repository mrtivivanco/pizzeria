#include "../../ordenes/ordenes.h"
#include "../metricas.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char* dms(int *size, order *orders) {
    int unique = 0;
    char orderDates[100][16];        // Fechas únicas
    float totalPerDay[100] = {0};    // Total de dinero por cada fecha

    // Contar ingresos por día
    for (int i = 0; i < *size; i++) {
        char *date = orders[i].order_date;
        float total = orders[i].total_price;

        int found = 0;
        for (int j = 0; j < unique; j++) {
            if (strcmp(orderDates[j], date) == 0) {  // Compara fechas
                totalPerDay[j] += total;             // Suma dinero al día correspondiente
                found = 1;
                break;
            }
        }

        if (!found) {
            strcpy(orderDates[unique], date);
            totalPerDay[unique] = total;
            unique++;
        }
    }

    // Encontrar el día con más ingresos
    int maxIndex = 0;
    for (int i = 1; i < unique; i++) {
        if (totalPerDay[i] > totalPerDay[maxIndex]) {
            maxIndex = i;
        }
    }

    // Preparar el resultado
    char *result = malloc(128);
    sprintf(result, "Día con más dinero: %s con un total de %.2f", orderDates[maxIndex], totalPerDay[maxIndex]);
    return result;
}
