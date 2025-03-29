#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "csv.h"
#include "metricas/metricas.h"
// reconocer lo que me piden si si sirve con lo que usamos
typedef char* (*MetricFunc)(int*, order*);
typedef struct {
    char *name;
    MetricFunc func;
} MetricEntry;

MetricEntry metricMap[] = {
    {"pms", pms},
    {"pls", pls},
    {"dms", dms},
    {"dls", dls},
   // {"dmsp", dmsp},
    //{"dlsp", dlsp},
   // {"apo", apo},
    //{"apd", apd},
    //{"ims", ims},
    //{"hp", hp}
};

int numMetrics = sizeof(metricMap) / sizeof(MetricEntry);
//resive un parametro y busca la funcion que piden
MetricFunc findMetric(char *name) {
    for (int i = 0; i < numMetrics; i++) {
        if (strcmp(metricMap[i].name, name) == 0) {
            return metricMap[i].func;
        }
    }
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Uso: %s archivo.csv metrica1 metrica2 ...\n", argv[0]);
        return 1;
    }

    int size = 0;
    order *orders = read_csv(argv[1], &size);
    if (!orders) {
        printf("Error al leer el archivo.\n");
        return 1;
    }

    for (int i = 2; i < argc; i++) {
        MetricFunc func = findMetric(argv[i]);
        if (func) {
            char *resultado = func(&size, orders);
            printf("%s\n", resultado);
            free(resultado);
        } else {
            printf("Métrica no válida: %s\n", argv[i]);
        }
    }

    free(orders);
    return 0;
}