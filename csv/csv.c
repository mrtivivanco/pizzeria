//Descarga de bibliotecas para el manejo de archivos y funciones a necesitar
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../ordenes/ordenes.h"

#define MAX_LINE 512 //Define el tamaño máximo de caracteres en cada linea del archivo en 512

order* read_csv(const char *filename, int *size) { //define los parámeros 
    FILE *file = fopen(filename, "r"); //abre el archivo para leerlo el "r" y de no poder leerlo retorna NULL
    if (!file) return NULL;

    char line[MAX_LINE];
    fgets(line, MAX_LINE, file); // Saltar encabezado

    int capacity = 100; //Se guarda memoria para hasta 100 pedidos inicialmente
    order *orders = malloc(capacity * sizeof(order));
    *size = 0; //inicia el contador de pedidos en 

    while (fgets(line, MAX_LINE, file)) { //Ciclo While para que mientras hayan lineas en el archivo se vayan leyendo una por una
        if (*size >= capacity) { //Si el número de pedidos supera la capacidad actual, ésta se duplicará
            capacity *= 2;
            orders = realloc(orders, capacity * sizeof(order));
        }

        order o; //Declara la estructura "o" para almacenar temporalmente un pedido
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

        orders[*size] = o; //Se guarda la estructura "o" eb la posici+on "*size" del arreglo
        (*size)++; //Se incrementa "*size" para el siguiente pedido
    }

    fclose(file); //Se cierra el archivo 
    return orders; //Y retorna el puntero con los pedidos almacenados
}
