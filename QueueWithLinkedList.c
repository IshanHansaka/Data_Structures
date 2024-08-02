#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node* next;
};

bool isEmpty();
struct node* createnewNode(int data);
void enqueue(int data);
int dequeue();
int peek();
void display();
void freeQueue(struct node* ptr);
struct node* front = NULL;

bool isEmpty() {
    return front == NULL;
}

struct node* createnewNode(int data) {
    struct node* temp = (struct node*) malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void enqueue(int data) {
    struct node* temp = createnewNode(data);
    if (isEmpty()) {
        front = temp;
        return;
    }
    struct node* ptr = front;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = temp;
}

int dequeue() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot dequeue\n\n");
        return -1;
    }
    struct node* ptr = front;
    front = front->next;
    int data = ptr->data;
    free(ptr);
    return data;
}

int peek() {
    if (isEmpty()) {
        printf("Queue is empty.\n\n");
        return -1;
    }
    return front->data;
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n\n");
        return;
    }
    struct node* ptr = front;
    while (ptr != NULL) {
        printf("|\t%d\t|\n", ptr->data);
        ptr = ptr->next;
    }
    printf("_________________\n\n");
}

void freeQueue(struct node* ptr) {
    if (ptr->next != NULL) {
        freeQueue(ptr->next);
    }
    free(ptr);
}

int main() {
    int choice, data;
    while (true) {
        printf("\n1. Enqueue Data\n2. Dequeue Data\n3. Display Queue\n4. Check Empty\n5. Peek Data\n6. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data to add: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                data = dequeue();
                if (data != -1)
                    printf("Dequeued: %d\n\n", data);
                break;
            case 3:
                display();
                break;
            case 4:
                if (isEmpty())
                    printf("Queue is empty.\n\n");
                else
                    printf("Queue is not empty.\n\n");
                break;
            case 5:
                data = peek();
                if (data != -1)
                    printf("Front element is: %d\n\n", data);
                break;
            case 6:
                freeQueue(front);
                return 0;
            default:
                printf("Invalid Operation\n\n");
                break;
        }
    }
}