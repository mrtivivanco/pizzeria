#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../ordenes/ordenes.h"

#define MAX_LINE 512

order* read_csv(const char *filename, int *size) {
    FILE *file = fopen(filename, "r");
    if (!file) return NULL;

    char line[MAX_LINE];
    fgets(line, MAX_LINE, file); // Saltar encabezado

    int capacity = 100;
    order *orders = malloc(capacity * sizeof(order));
    *size = 0;

    while (fgets(line, MAX_LINE, file)) {
        if (*size >= capacity) {
            capacity *= 2;
            orders = realloc(orders, capacity * sizeof(order));
        }

        order o;
        char *token;

        // Leer los campos separados por coma
        token = strtok(line, ","); o.pizza_id = atoi(token);
        token = strtok(NULL, ","); o.order_id = atoi(token);
        token = strtok(NULL, ","); strcpy(o.pizza_name_id, token);
        token = strtok(NULL, ","); o.quantity = atoi(token);
        token = strtok(NULL, ","); strcpy(o.order_date, token);
        token = strtok(NULL, ","); strcpy(o.order_time, token);
        token = strtok(NULL, ","); o.unit_price = atof(token);
        token = strtok(NULL, ","); o.total_price = atof(token);
        token = strtok(NULL, ","); strcpy(o.pizza_size, token);
        token = strtok(NULL, ","); strcpy(o.pizza_category, token);

        // Leer pizza_ingredients (puede contener comas y está entre comillas)
        token = strtok(NULL, "\""); 
        if (token) strcpy(o.pizza_ingredients, token);

        // Leer el último campo pizza_name (puede contener espacios)
        token = strtok(NULL, "\n");
        if (token) strcpy(o.pizza_name, token);

        orders[*size] = o;
        (*size)++;
    }

    fclose(file);
    return orders;
}
