#ifndef CSV_H
#define CSV_H

#include "../ordenes/ordenes.h"

order* read_csv(const char *filename, int *size);

#endif