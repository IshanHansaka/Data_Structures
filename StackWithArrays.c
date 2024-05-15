#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define StackSize 5

void Display();
bool IsEmpty();
bool IsFull();
void Push();
int Pop();
int Peek();

int top = -1;
int stack[StackSize];

int main()
{
    int choice;

    while (true)
    {
        printf("\n1.Push Data\n2.Pop\n3.Display Stack\n4.Check Empty\n5.Check Full\n6.Peek\n7.Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            Push();
            break;
        case 2:
            printf("Popped : %d\n\n", Pop());
            break;
        case 3:
            Display();
            break;
        case 4:
            if (IsEmpty())
                printf("Stack is empty.\n\n");
            else
                printf("Stack is not empty.\n\n");
            break;
        case 5:
            if (IsFull())
                printf("Stack is full.\n\n");
            else
                printf("Stack is not full.\n\n");
            break;
        case 6:
            printf("Top element is : %d\n\n", Peek());
            break;
        case 7:
            exit(0);
            break;   
        default:
            printf("Invalid Operation\n\n");
            break;
        }
    }
}

void Display()
{
    for (int i = top; i >= 0; i--)
    {
        printf("|\t%d\t|\n", stack[i]);
    }
    printf("_________________\n\n");
}

bool IsEmpty()
{
    if (top == -1)
        return true;
    else
        return false;
}

bool IsFull()
{
    if (top == StackSize - 1)
        return true;
    else
        return false;
}

void Push()
{
    if (IsFull())
    {
        printf("Stack is Full! Can't push.\n\n");
        return ;
    }    

    int data;
    printf("Enter Data: ");
    scanf("%d", &data);
    top++;
    stack[top] = data;
    printf("Data Pushed!\n\n");
}

int Pop()
{
    if (IsEmpty())
    {
        printf("Stack is Empty! Can't pop.\n\n");
        return -1;
    }    

    int data = stack[top];
    top--;
    return data;
}

int Peek()
{
    if (IsEmpty())
    {
        printf("Stack is Empty! Can't peek.\n\n");
        return -1;
    }    

    int data = stack[top];
    return data;
}