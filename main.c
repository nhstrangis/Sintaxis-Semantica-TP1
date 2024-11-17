    #include <stdio.h>
    #include <ctype.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include <string.h>
    #include "scanner.h"
    #include "stack.h"
    #include "queue.h"
    #include "operator.h"
    #include "atoi.h"

    const int MAX_INPUT = 10000;
    const int MAX_GROUP = 10000;

    int main(int argc, char *argv[]) {    

    
    if (argc >= 2) {

        // Se ejecuta el punto 2    
        if(!strcmp(argv[1], "atoi")) {
            char str[MAX_INPUT]; 

            printf("Ingrese una cadena numérica: ");
            fgets(str, sizeof(str), stdin);  

            size_t len = strlen(str);    
            if (str[len - 1] == '\n') {
                str[len - 1] = '\0';
            }

            size_t num = stringToInt(str);
            
            if (num != -1) {
                printf("El número ingresado es: %zu\n", num);
            } else {
                printf("La cadena ingresada es inválida\n");
            } 
        
            return 0;
        }

        // Se ejecuta el punto 1    
        int i = 0; 
        char c; 
        char input[MAX_INPUT] = "";
        int groupSizes[MAX_GROUP] = {0};
        char *groupTypes[MAX_GROUP] = {NULL};

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
            if (groupSizes[i] != 0) {  // solo se imprinen los grupos que no son vacíos
                printf("Grupo %d: Tipo: %s, Tamaño: %d\n", i + 1, groupTypes[i], groupSizes[i]);
            }
        }

        fclose(file);

    // Se ejecuta el punto 3
    } else {

        char input[MAX_SIZE]; 

        printf("Ingrese una operacion: ");
        
        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("Error al leer la expresión.\n");
            return 1;
        }

        // se quita el salto de linea de la expresion
        size_t len = strlen(input);
        if (input[len - 1] == '\n') {
            input[len - 1] = '\0';
        }

        // Inicializaciones
        Queue outputQueue;
        Stack operatorStack;
        initializeQueue(&outputQueue);
        initializeStack(&operatorStack);

        // Convertir la expresión a RPN
        shuntingYard(input, &outputQueue, &operatorStack);

        // Resolver la expresión RPN
        int result = resolveRPN(&outputQueue);
        if (result != -1) {
            printf("Resultado: %d\n", result);
        } else {
            printf("Error al evaluar la expresión.\n");
        }
    }

    return 0;
}

