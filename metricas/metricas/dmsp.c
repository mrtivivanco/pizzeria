#include "../../ordenes/ordenes.h"
#include "../metricas.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//Fechas con mas ventas en términos de cantidad de pizzas
char* dmsp(int *size, order *orders) {
    int unique = 0;
    char orderDates[100][16];       // Fechas únicas
    int pizzasPerDay[100] = {0};    // Cantidad de pizzas por cada fecha
