    #include <stdio.h>
    #include <ctype.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include <string.h>
    #include "scanner.h"

    const int MAX_INPUT = 10000;
    const int MAX_GROUP = 10000;

    int main(int argc, char *argv[]) {

        int i = 0; 
        char c; 
        char input[MAX_INPUT] = "";
        int groupSizes[MAX_GROUP] = {0};
        char *groupTypes[MAX_GROUP] = {NULL};    

        if (argc != 2) {
            printf("Por favor, escriba el nombre del archivo a procesar\n");
            return 1;
        }

        FILE *file = fopen(argv[1], "r");
        if (!file) {
            printf("No se pudo abrir el archivo %s\n", argv[1]);
            return 1;
        }
        
        while((c = fgetc(file)) != EOF && c != '\n' && i < MAX_INPUT) {
           input[i++] = c;
        }

        scan(input, groupSizes, groupTypes);

        printf("Input: %s\n", input);
        printf("Resultados:\n");
        for (int i = 0; i < MAX_GROUP && groupSizes[i] != 0; i++) {
            if (groupSizes[i] != 0) {  // Solo imprimir los grupos que no son vacíos
                printf("Grupo %d: Tipo: %s, Tamaño: %d\n", i + 1, groupTypes[i], groupSizes[i]);
            }
        }

        fclose(file);
        return 0;
    }