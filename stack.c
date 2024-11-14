#include "stack.h"
#include <stdio.h>

void initializeStack(Stack* stack) {
    stack->top = -1;
}

void push(Stack* stack, int value) {
    if (stack->top < MAX_SIZE - 1) {
        stack->data[++(stack->top)] = value;
    }
}

int pop(Stack* stack) {
    if (stack->top == -1) return -1;  // Error si la pila está vacía
    return stack->data[(stack->top)--];
}

int peek(Stack* stack) {
    if (stack->top == -1) return -1;
    return stack->data[stack->top];
}  