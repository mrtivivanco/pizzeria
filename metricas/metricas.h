#ifndef METRICS_H
#define METRICS_H
//Su propósito es declarar funciones que calculan diferentes métricas sobre los pedidos de pizza, en este caso todas devolveran cadena de texto
//.h son DEFINICIONES
#include "../ordenes/ordenes.h"

char* pms(int *size, order *orders);   // Pizza más vendida
char* pls(int *size, order *orders);   // Pizza menos vendida
char* dms(int *size, order *orders);   // Día con más dinero
char* dls(int *size, order *orders);   // Día con menos dinero
char* dmsp(int *size, order *orders);  // Día con más pizzas
char* dlsp(int *size, order *orders);  // Día con menos pizzas
char* apo(int *size, order *orders);   // Promedio por orden
char* apd(int *size, order *orders);   // Promedio por día
char* ims(int *size, order *orders);   // Ingrediente más vendido
// char* hp(int *size, order *orders);    // Pizzas por categoría

#endif


