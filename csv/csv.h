#ifndef CSV_H //Comprueba si CSV_H no está definido
#define CSV_H //Si no esta definido, define CSV_H para evitar inclusiones multiples

#include "../ordenes/ordenes.h" //Define la estructura "order"

order* read_csv(const char *filename, int *size); //Declara la función para leer el CSV

#endif //Termina el If de la línea 1
