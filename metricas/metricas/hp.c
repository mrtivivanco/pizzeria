#include "../../ordenes/ordenes.h"
#include "../metricas.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_CATEGORIES 100
#define CATEGORY_LENGTH 50

// Cantidad de pizzas por categoría vendidas
char* hp(int *size, order *orders) {
    if (size == NULL || orders == NULL || *size <= 0) {
        return NULL;
    }

    int unique = 0;
    char categories[MAX_CATEGORIES][CATEGORY_LENGTH];  // Categorías únicas
    int categoryCount[MAX_CATEGORIES] = {0};           // Cantidad de pizzas por categoría

    // Contar pizzas por categoría
    for (int i = 0; i < *size; i++) {
        char *category = orders[i].pizza_category;
        int quantity = orders[i].quantity;
        
        int found = 0;
        for (int j = 0; j < unique; j++) {
            if (strcmp(categories[j], category) == 0) {
                categoryCount[j] += quantity;
                found = 1;
                break;
            }
        }
        if (!found) {
            strncpy(categories[unique], category, CATEGORY_LENGTH - 1);
            categories[unique][CATEGORY_LENGTH - 1] = '\0'; // Asegura la terminación nula
            categoryCount[unique] = quantity;
            unique++;
        }
    }

    // Preparar el resultado
    char *result = malloc(512);
    if (result == NULL) {
        perror("Error al asignar memoria");
        exit(EXIT_FAILURE);
    }
    
    snprintf(result, 512, "Cantidad de pizzas vendidas por categoría:\n");
    for (int i = 0; i < unique; i++) {
        char buffer[128];
        snprintf(buffer, 128, "%s: %d\n", categories[i], categoryCount[i]);
        strncat(result, buffer, 512 - strlen(result) - 1);
    }
    
    return result;
}

