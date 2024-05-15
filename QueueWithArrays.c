#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define QueueSize 5

void Display();
bool IsEmpty();
bool IsFull();
void Enqueue();
int Dequeue();
int Peek();

int front = 0;
int rear = -1;
int size = 0;
int Queue[QueueSize];

int main()
{
    int choice;

    while (true)
    {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display Queue\n4.Check Empty\n5.Check Full\n6.Peek\n7.Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            Enqueue();
            break;
        case 2:
            printf("Dequeued : %d\n\n", Dequeue());
            break;
        case 3:
            Display();
            break;
        case 4:
            if (IsEmpty())
                printf("Queue is empty.\n\n");
            else
                printf("Queue is not empty.\n\n");
            break;
        case 5:
            if (IsFull())
                printf("Queue is full.\n\n");
            else
                printf("Queue is not full.\n\n");
            break;
        case 6:
            printf("front element is : %d\n\n", Peek());
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
    if (IsEmpty())
    {
        printf("Queue is Empty!\n\n");
        return ;
    }  
    for (int i = 0; i < size; i++)
    {
        printf("%d ", Queue[(front + i) % QueueSize]);
    }
    printf("\n\n");
}

bool IsEmpty()
{
    if (size == 0)
        return true;
    else
        return false;
}

bool IsFull()
{
    if (size == QueueSize)
        return true;
    else
        return false;
}

void Enqueue()
{
    if (IsFull())
    {
        printf("Queue is Full! Can't enqueue.\n\n");
        return ;
    }    

    int data;
    printf("Enter Data: ");
    scanf("%d", &data);
    rear = (rear + 1) % QueueSize;  
    Queue[rear] = data; 
    size++;
    printf("Data Queued!\n\n");
}

int Dequeue()
{
    if (IsEmpty())
    {
        printf("Queue is Empty! Can't dequeue.\n\n");
        return -1;
    }    

    int data = Queue[front];
    front = (front + 1) % QueueSize;
    size --;
    return data;
}

int Peek()
{
    if (IsEmpty())
    {
        printf("Queue is Empty! Can't peek.\n\n");
        return -1;
    }    

    int data = Queue[front];
    return data;
}