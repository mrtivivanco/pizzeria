#include "../../ordenes/ordenes.h"
#include "../metricas.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_INGREDIENTS 100
#define INGREDIENT_LENGTH 50

// Ingrediente más vendido
char* ims(int *size, order *orders) {
    if (size == NULL || orders == NULL || *size <= 0) {
        return NULL;
    }

    int unique = 0;
    char ingredients[MAX_INGREDIENTS][INGREDIENT_LENGTH];  // Ingredientes únicos
    int ingredientCount[MAX_INGREDIENTS] = {0};            // Cantidad de cada ingrediente vendido

    // Contar ingredientes vendidos
    for (int i = 0; i < *size; i++) {
        char *ingredientList = orders[i].pizza_ingredients;
        int quantity = orders[i].quantity;
        
        char *token = strtok(ingredientList, ",");
        while (token != NULL) {
            int found = 0;
            for (int j = 0; j < unique; j++) {
                if (strcmp(ingredients[j], token) == 0) {
                    ingredientCount[j] += quantity;
                    found = 1;
                    break;
                }
            }

            if (!found) {
                strncpy(ingredients[unique], token, INGREDIENT_LENGTH - 1);
                ingredients[unique][INGREDIENT_LENGTH - 1] = '\0'; // Asegura la terminación nula
                ingredientCount[unique] = quantity;
                unique++;
            }
            
            token = strtok(NULL, ",");
        }
    }
