#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "stack.h"
#include "queue.h"

int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } 
    if (op == '*' || op == '/') {
        return 2;
    }
    return 0;
}

void shuntingYard(char* input, Queue* output, Stack* operators) {
    int i = 0;
    while (input[i] != '\0') {
        char token = input[i];

        if (isdigit(token)) {
            // Si es un número, se agrega a la cola de salida
            enqueue(output, token);
        } else if (token == '+' || token == '-' || token == '*' || token == '/') {
            // Si es un operador, mientras haya un oprador de precedencia mayor en la pila,
            //se saca de la pila y se encola
            while (peek(operators) != -1 && precedence(peek(operators)) >= precedence(token)) {
                enqueue(output, pop(operators));
            }
            push(operators, token); //Pushear operador en la pila
        } else if (token == ' ') {
            // Ignorar espacios
        } else {
            printf("Error: Caracter desconocido '%c'\n", token);
            return;
        }

        i++;
    }

    // Mientras queden operadores en la pila, se sacan y se encolan
    while (peek(operators) != -1) {
        enqueue(output, pop(operators));
    }
}

// Resuelve la expresión RPN
int resolveRPN(Queue* outputQueue) {
    Stack stack;
    initializeStack(&stack);

    while (outputQueue->front < outputQueue->rear) {
        char token = dequeue(outputQueue);

        if (isdigit(token)) {
            // Si es un número, lo convertimos a int y lo agregamos a la pila
            push(&stack, token - '0');
        } else {
            // Si es un operador, hacemos la operación
            int b = pop(&stack);
            int a = pop(&stack);
            int result;

            switch (token) {
                case '+': result = a + b; 
                    break;
                case '-': result = a - b; 
                    break;
                case '*': result = a * b; 
                    break;
                case '/': 
                    if (b == 0) {
                        printf("Error: División por cero\n");
                        return -1;
                    }
                    result = a / b; 
                    break;
                default:
                    printf("Operador no conocido'%c'\n", token);
                    return -1;
            }
            // se pushea en resultado en la pila
            push(&stack, result);
        }
    }

    return pop(&stack);  // Se devuelve el resultado final
}