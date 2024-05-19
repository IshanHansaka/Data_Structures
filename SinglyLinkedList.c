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
void DeleteAtBegin();
void DeleteAtEnd();
void DeleteAtPosition(int possition);

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

void DeleteAtBegin(){
    if(head == NULL)
    {
        printf("Linked List is empty! Node can't delete!\n\n");
        return;
    }
    struct node* ptr = head;
    head = head->next;
    free(ptr);
    printf("Node deleted!\n\n");
}

void DeleteAtEnd()
{
    if(head == NULL)
    {
        printf("Linked List is empty! Node can't delete!\n\n");
        return;
    }
    struct node* ptr = head;
    while(ptr->next->next != NULL) // ptr point to second last element
    {
        ptr = ptr->next;
    }
    struct node* temp = ptr->next;
    ptr->next = NULL;
    free(temp);
    printf("Node deleted!\n\n");
}

void DeleteAtPosition(int possition)
{
    if(head == NULL)
    {
        printf("Linked List is empty! Node can't delete!\n\n");
        return;
    }
    if(possition == 0)
    {
        DeleteAtBegin();
        return;
    }
    struct node* ptr = head;
    for(int i = 0; i < possition-2; i++)
    {
        ptr = ptr->next;
    }
    struct node* temp = ptr->next;
    ptr->next = temp->next;
    free(temp);
    printf("Node deleted!\n\n");
}

void Display()
{
    if(head == NULL)
    {
        printf("Linked List is empty!");
        return;
    }
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
        printf("1. Insert at Begin\n2. Insert at End\n3. Insert at Position\n4. Delete at Begin\n5. Delete at End\n6. Delete at Position\n7. Display\n8. Exit\n\nEnter your choice : ");
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
            DeleteAtBegin();
            break;
        case 5:
            DeleteAtEnd();
            break;
        case 6:
            printf("Enter position: ");
            scanf("%d", &position);
            DeleteAtPosition(position);
            break;
        case 7:
            Display();
            break;
        case 8:
        default:
            FreeList();
            return 0;
        }
    }
}
