#include "queue.h"
#include <stdio.h>

void initializeQueue(Queue* queue) {
    queue->front = 0;
    queue->rear = 0;
}

void enqueue(Queue* queue, char value) {
    if (queue->rear < MAX_SIZE) {
        queue->data[queue->rear++] = value;
    }
}

char dequeue(Queue* queue) {
    if (queue->front == queue->rear) return '\0';  // Error si la cola está vacía
    return queue->data[queue->front++];
}