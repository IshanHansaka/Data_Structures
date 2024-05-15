#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* head = NULL; //create head node

struct node* CreateNewNode(int data);
void InsertAtBegin(int data);
void InsertAtEnd(int data);
void InsertAtPosition(int data, int position);
void Display();
void FreeList();

struct node* CreateNewNode(int data)
{
    struct node* temp = (struct node*) malloc(sizeof(struct node));
    temp->next = NULL;
    temp->data = data;
    return temp;
}

void InsertAtBegin(int data)
{
    struct node* ptr = CreateNewNode(data);
    if(head == NULL)
    {
        head = ptr;
        return;
    }
    ptr->next = head;
    head = ptr;
    printf("Node Added!\n\n");
}

void InsertAtEnd(int data)
{   
    struct node* temp = CreateNewNode(data);
    if(head == NULL)
    {
        head = temp;
        return;
    }
    struct node* ptr = head;
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
    printf("Node Added!\n\n");
}

void InsertAtPosition(int data, int position)
{
    struct node* temp = CreateNewNode(data);
    if(head == NULL)
    {
        head = temp;
        return;
    }
    if(position == 0)
    {
        InsertAtBegin(data);
        return;
    }
    struct node* ptr = head;
    for(int i = 1; i < position; i++)
    {
        ptr = ptr->next;
    }
    temp->next = ptr->next;
    ptr->next = temp;
    printf("Node Added!\n\n");
}

void Display()
{
    struct node* ptr = head;
    printf("\n");
    while(ptr != NULL)
    {
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
    printf("\n\n");
}

void FreeList()
{
    struct node* ptr = head;
    while(ptr != NULL)
    {
        struct node* temp = ptr;
        ptr = ptr->next;
        free(temp);
    }
    printf("Link List Deleted!\n\n");
}

int main()
{
    int num, data, position;
    while (1)
    {
        printf("1.Insert at Begin\n2.Insert at End\n3.Insert at Position\n4.Display\n5.Exit\n\nEnter your choice : ");
        scanf("%d",&num);
        switch (num)
        {
        case 1:
            printf("Enter data to add: ");
            scanf("%d", &data);
            InsertAtBegin(data);
            break;
        case 2:
            printf("Enter data to add: ");
            scanf("%d", &data);
            InsertAtEnd(data);
            break;
        case 3:
            printf("Enter data to add: ");
            scanf("%d", &data);
            printf("Enter position: ");
            scanf("%d", &position);
            InsertAtPosition(data, position);
            break;
        case 4:
            Display();
            break;
        case 5:
        default:
            FreeList();
            return 0;
        }
    }
}