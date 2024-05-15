#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{
    int data;
    struct node *next;
};

void Display();
bool IsEmpty();
void Push();
int Pop();
int Peek();
void freeStack(struct node *ptr);

struct node *top = NULL;

int main()
{
    int choice;

    while (true)
    {
        printf("\n1.Push Data\n2.Pop\n3.Display Stack\n4.Check Empty\n5.Peek\n6.Exit\n");
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
            printf("Top element is : %d\n\n", Peek());
            break;
        case 6:
            freeStack(top);
            exit(0);
            break;   
        default:
            printf("Invalid Operation\n\n");
            break;
        }
    }
    return 0;
}

void Display()
{
    struct node *ptr = top;
    while (ptr != NULL)
    {
        printf("|\t%d\t|\n", ptr->data);
        ptr = ptr->next;
    }
    printf("_________________\n\n");
}

bool IsEmpty()
{
    if (top == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Push()
{
    int data;
    printf("Enter data to add: ");
    scanf("%d", &data);

    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    if (IsEmpty())
    {
        temp->next = NULL;
        top = temp;
    }
    else
    {
        temp->next = top;
        top = temp;
    }
    printf("Data Pushed!\n\n");
}

int Pop()
{
    if (IsEmpty())
    {
        printf("Stack is empty! Nothing to delete!\n");
        return -1;
    }
    struct node *ptr = top;
    int data = top->data;
    top = top->next;
    free(ptr);
    printf("Popped!\n\n");
    return data;
}

int Peek()
{
    if (IsEmpty())
    {
        printf("Stack is empty!\n");
        return -1;
    }
    else
    {
        return top->data;
    }
}

void freeStack(struct node *ptr)
{
    if (ptr->next != NULL)
    {
        freeStack(ptr->next);
    }
    free(ptr);
}

