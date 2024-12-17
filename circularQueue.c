#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int size;
    int front;
    int rear;
    int* arr;
};

// Function to create a queue
struct Queue* createQueue(int size) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->size = size;
    queue->front = -1;
    queue->rear = -1;
    queue->arr = (int*)malloc(size * sizeof(int));
    return queue;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return queue->front == -1;
}

// Function to check if the queue is full
int isFull(struct Queue* queue) {
    return (queue->rear + 1) % queue->size == queue->front;
}

// Function to enqueue an element
void enqueue(struct Queue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue %d\n", value);
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % queue->size;
    queue->arr[queue->rear] = value;
    printf("Enqueued %d\n", value);
}

// Function to dequeue an element
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    int value = queue->arr[queue->front];
    if (queue->front == queue->rear) { // Queue becomes empty after this operation
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % queue->size;
    }
    printf("Dequeued %d\n", value);
    return value;
}

// Function to get the front element of the queue
int front(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. No front element.\n");
        return -1;
    }
    return queue->arr[queue->front];
}

// Function to get the rear element of the queue
int rear(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. No rear element.\n");
        return -1;
    }
    return queue->arr[queue->rear];
}

// Main function to demonstrate the queue operations
int main() {
    int size;
    printf("Enter the size of the queue: ");
    scanf("%d", &size);

    struct Queue* queue = createQueue(size);

    // Demonstrating operations
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40); // Should display full if size is 3

    printf("Front element: %d\n", front(queue));
    printf("Rear element: %d\n", rear(queue));

    dequeue(queue);
    dequeue(queue);

    printf("Front element after dequeuing: %d\n", front(queue));
    printf("Rear element after dequeuing: %d\n", rear(queue));

    enqueue(queue, 50);

    printf("Queue is full? %s\n", isFull(queue) ? "Yes" : "No");
    printf("Queue is empty? %s\n", isEmpty(queue) ? "Yes" : "No");

    return 0;
}
