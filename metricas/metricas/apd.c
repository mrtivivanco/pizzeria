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

    
