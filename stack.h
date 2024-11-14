#ifndef STACK_H
#define STACK_H

#define MAX_SIZE 1000

typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

// Inicialización de la pila
void initializeStack(Stack* stack);
// Apilar un elemento
void push(Stack* stack, int value);
// Desapilar un elemento
int pop(Stack* stack) ;
// Obtener el elemento en la parte superior de la pila sin desapilarlo
int peek(Stack* stack);

#endif
