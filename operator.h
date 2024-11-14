#ifndef OPERATOR_H
#define OPERATOR_H
#include "stack.h"
#include "queue.h"

// Convierte input a notación RPN usando el algoritmo de Shunting Yard
void shuntingYard(char* expression, Queue* outputQueue, Stack* operatorStack);
// Resuelve la expresión RPN 
int resolveRPN(Queue* outputQueue);

#endif