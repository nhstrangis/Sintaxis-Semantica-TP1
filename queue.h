#ifndef QUEUE_H
#define QUEUE_H

#define MAX_SIZE 1000

typedef struct {
    char data[MAX_SIZE];
    int front;
    int rear;
} Queue;

// Inicialización de la cola (output queue)
void initializeQueue(Queue* queue);
// Insertar un elemento en la cola
void enqueue(Queue* queue, char value);
// Desencolar un elemento
char dequeue(Queue* queue);

#endif
