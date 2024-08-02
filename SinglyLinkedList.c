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
void DisplayReverse(struct node* temp);
void Search(int data);
void Update(int data ,int position);

struct node* CreateNewNode(int data)
{
    struct node* temp = (struct node*) malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
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
        if (ptr == NULL)
        {
            printf("Invalid position! Enter a valid position!\n\n");
            return;
        }
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
    if (ptr->next == NULL) // if there is one node and user enter delete at end
    {
        DeleteAtBegin();
        return;
    }    
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
    for(int i = 1; i < possition; i++)
    {
        if (ptr == NULL)
        {
            printf("Invalid position! Enter a valid position!\n\n");
            return;
        }
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

void DisplayReverse(struct node* temp)
{
    if(temp->next != NULL)
    {
        DisplayReverse(temp->next);
    }
    printf("%d ",temp->data);
}

void Search(int data)
{
    if (head == NULL)
    {
        printf("Linked List is empty!");
        return;
    }
    struct node* ptr = head;
    while(ptr != NULL)
    {
        if(ptr->data == data)
        {
            printf("\nData in the list\n\n");
            return;
        }
        ptr = ptr->next;
    }
    printf("\nData is not in the list\n\n");
}

void Update(int data ,int position)
{
    if (head == NULL)
    {
        printf("Linked List is empty!");
        return;
    }
    struct node* ptr = head;
    for(int i = 0; i < position; i++)
    {
        if (ptr == NULL)
        {
            printf("Invalid position! Enter a valid position!\n\n");
            return;
        }
        ptr = ptr->next;
    }
    ptr->data = data;
    printf("Node Updated!\n\n");
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
        printf("1. Insert at Begin\n2. Insert at End\n3. Insert at Position\n4. Delete at Begin\n5. Delete at End\n6. Delete at Position\n7. Display\n8. Display Reverse\n9. Search\n10. Update\n11. Exit\n\nEnter your choice : ");
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
            printf("\n");
            DisplayReverse(head);
            printf("\n\n");
            break;
        case 9:
            printf("Enter data to search: ");
            scanf("%d", &data);
            Search(data);
            break;
        case 10:
            printf("Enter position to Update: ");
            scanf("%d", &position);
            printf("Enter data to add: ");
            scanf("%d", &data);
            Update(data, position);
            break;
        case 11:
            FreeList();
            return 0;
        default:
            printf("Wrong input, try again!\n\n");
        }
    }
}
