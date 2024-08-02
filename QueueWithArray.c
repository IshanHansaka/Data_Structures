#include<stdio.h>
#include<stdbool.h>
#define Max_size 100

int queue[Max_size];
int front = 0;
int rear = -1;
int size = 0;

bool isEmpty() {
    return size == 0;
}

bool isFull() {
    return size == Max_size;
}

void enqueue(int data) {
    if (isFull()) {
        printf("Queue is full. Can not enqueue\n\n");
        return;
    }
    rear = (rear+1) % Max_size;
    queue[rear] = data;
    size++;
}

int dequeue() {
    if(isEmpty()) {
        printf("Queue is empty. Can not dequeue\n\n");
        return -1;
    }
    int data = queue[front];
    front = (front+1) % Max_size;
    size--;
    return data;
}

int peek() {
    if(isEmpty()) {
        printf("Queue is empty.\n\n");
        return -1;
    }
    return queue[front];
}

void display() {
    if(isEmpty()) {
        printf("Queue is empty.\n\n");
        return;
    }
    for (int i = front; i <= rear; i++) {
        printf("|\t%d\t|\n", queue[i]);
    }
    printf("_________________\n\n");
}

int main() {
int choice, data;
    while (true) {
        printf("\n1. Enqueue Data\n2. Dequeue Data\n3. Display Queue\n4. Check Empty\n5. Check Full\n6. Peek Data\n7. Exit\n");
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
                printf("Popped: %d\n\n", data);
            break;
        case 3:
            display();
            break;
        case 4:
            if (isEmpty())
                printf("Queue is empty.\n\n");
            else
                printf("Queuek is not empty.\n\n");
            break;
        case 5:
            if (isFull())
                printf("Queue is full.\n\n");
            else
                printf("Queue is not full.\n\n");
            break;
        case 6:
            data = peek();
            if (data != -1)
                printf("Top element is: %d\n\n", data);
            break;
        case 7:
            return 0;
        default:
            printf("Invalid Operation\n\n");
            break;
        }
    }
}