#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* top = NULL;

struct node* createNewNode(int data) {
    struct node* temp = (struct node*) malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    temp->data = data;
    temp->next = NULL;
    return temp;
}

bool isEmpty() {
    return top == NULL;
}

void push(int data) {
    struct  node* temp = createNewNode(data);
    if (isEmpty()) {
        top = temp;
        printf("Data Pushed!\n\n");
        return;
    }
    temp->next = top;
    top = temp;
    printf("Data Pushed!\n\n");
}

int pop() {
    if (isEmpty()) {
        printf("Stack is Empty! Can't pop.\n\n");
        return -1;
    }
    struct node* temp = top;
    top = top->next;
    int data = temp->data;
    free(temp);
    return data;
}

int peek() {
    if (isEmpty()) {
        printf("Stack is Empty!\n\n");
        return -1;
    }  
    return top->data;
}

void display() {
    if (isEmpty()) {
        printf("Stack is Empty!\n\n");
        return;
    } 
    struct node* ptr = top;
    while (ptr != NULL) {
        printf("|\t%d\t|\n", ptr->data);
        ptr = ptr->next;
    }
    printf("_________________\n\n");
}

void freeStack(struct node* ptr) {
    if(ptr->next != NULL) {
        freeStack(ptr->next);
    }
    free(ptr);
}

int main() {
    int choice, data;
    while (true) {
        printf("\n1. Push Data\n2. Pop Data\n3. Display Stack\n4. Check Empty\n5. Peek Data\n6. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter data to add: ");
            scanf("%d", &data);
            push(data);
            break;
        case 2:
            data = pop();
            if (data != -1)
                printf("Popped: %d\n\n", data);
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
            data = peek();
            if (data != -1)
                printf("Top element is: %d\n\n", data);
            break;
        case 6:
            if (!isEmpty()) {
                freeStack(top);
            }
            return 0;
        default:
            printf("Invalid Operation\n\n");
            break;
        }
    }
}