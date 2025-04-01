#include "../../ordenes/ordenes.h"
#include "../metricas.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MAX_DATES 100
#define DATE_LENGTH 16

// Fecha con menos ventas en términos de cantidad de pizzas
char* dlsp(int *size, order *orders) {
    if (size == NULL || orders == NULL || *size <= 0) {
        return NULL;
    }
