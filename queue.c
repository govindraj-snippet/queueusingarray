#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

struct Queue {
    int data[MAX_SIZE];
    int frontIndex;
    int rearIndex;
};

void initializeQueue(struct Queue *queue) {
    queue->frontIndex = -1;
    queue->rearIndex = -1;
}

int isQueueFull(struct Queue *queue) {
    return queue->rearIndex == MAX_SIZE - 1;
}

int isQueueEmpty(struct Queue *queue) {
    return queue->frontIndex == -1;
}

void enqueue(struct Queue *queue, int element) {
    if (isQueueFull(queue)) {
        printf("Queue is full. Cannot enqueue %d\n", element);
        return;
    }
    if (queue->frontIndex == -1) {
        queue->frontIndex = 0;
    }
    queue->rearIndex++;
    queue->data[queue->rearIndex] = element;
    printf("Enqueued %d to the queue\n", element);
}

void dequeue(struct Queue *queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue\n");
        return;
    }
    int removedElement = queue->data[queue->frontIndex];
    printf("Dequeued %d from the queue\n", removedElement);
    queue->frontIndex++;
    if (queue->frontIndex > queue->rearIndex) {
        queue->frontIndex = queue->rearIndex = -1;
    }
}

void printQueue(struct Queue *queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue contents: ");
    for (int i = queue->frontIndex; i <= queue->rearIndex; i++) {
        printf("%d ", queue->data[i]);
    }
    printf("\n");
}

void displayMenu() {
    struct Queue queue;
    initializeQueue(&queue);
    int userChoice, inputValue;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add (Enqueue)\n");
        printf("2. Delete (Dequeue)\n");
        printf("3. Print Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &userChoice);

        switch (userChoice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &inputValue);
                enqueue(&queue, inputValue);
                break;
            case 2:
                dequeue(&queue);
                break;
            case 3:
                printQueue(&queue);
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }
}

int main() {
    displayMenu();
    return 0;
}
