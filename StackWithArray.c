#include <stdio.h>
#include <stdbool.h>
#define Max_size 100

int stack[Max_size];
int top = -1;

bool isFull() {
    return top == Max_size;
}

bool isEmpty() {
    return top == -1;
}

void push(int data) {
    if (isFull()) {
        printf("Stack is Full! Can't push.\n\n");
        return;
    }
    stack[++top] = data;
    printf("Data Pushed!\n\n");
}

int pop () {
    if (isEmpty()) {
        printf("Stack is Empty! Can't pop.\n\n");
        return -1;
    }
    int data = stack[top--];
    return data;
}

int peek() {
    if (isEmpty()) {
        printf("Stack is Empty!\n\n");
        return -1;
    }
    int data = stack[top];
    return data;
}

void display() {
    for (int i = top; i >= 0; i--) {
        printf("|\t%d\t|\n", stack[i]);
    }
    printf("_________________\n\n");
}

int main() {
    int choice, data;
    while (true) {
        printf("\n1.Push Data\n2.Pop Data\n3.Display Stack\n4.Check Empty\n5.Check Full\n6.Peek Data\n7.Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter data to add: ");
            scanf("%d", &data);
            push(data);
            break;
        case 2:
            printf("Popped : %d\n\n", pop());
            break;
        case 3:
            display();
            break;
        case 4:
            if (isEmpty())
                printf("Stack is empty.\n\n");
            else
                printf("Stack is not empty.\n\n");
            break;
        case 5:
            if (isFull())
                printf("Stack is full.\n\n");
            else
                printf("Stack is not full.\n\n");
            break;
        case 6:
            printf("Top element is : %d\n\n", peek());
            break;
        case 7:
            return 0;
            break;   
        default:
            printf("Invalid Operation\n\n");
            break;
        }
    }
}
