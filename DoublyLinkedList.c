#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
    struct node* prev;
};

struct node* head = NULL; //create head node
struct node* tail = NULL; //create tail node

struct node* createNewNode(int data);
void InsertAtBegin(int data);
void InsertAtEnd(int data);
void InsertAtPosition(int data, int position);
void DeleteAtBegin();
void DeleteAtEnd();
void DeleteAtPosition(int position);
void Display();
void DisplayReverse();
void Search(int data);
void Update(int data ,int position);
void FreeList();

struct node* createNewNode(int data)
{
    struct node* temp = (struct node*) malloc(sizeof(struct node));
    if(temp == NULL){
        printf("Memory allocation failed!\n");
        exit(1);
    }
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

void InsertAtBegin(int data)
{
    struct node* temp = createNewNode(data);
    if(head == NULL){
        head = temp;
        tail = temp;
        return;
    }
    temp->next = head;
    head->prev = temp;
    head = temp;
    printf("Node Added!\n\n");
}

void InsertAtEnd(int data)
{
    struct node* temp = createNewNode(data);
    if(head == NULL){
        head = temp;
        tail = temp;
        return;
    }
    temp->prev = tail;
    tail->next = temp;
    tail = temp;
    printf("Node Added!\n\n");
}

void InsertAtPosition(int data, int position)
{
    struct node* temp = createNewNode(data);
    if(head == NULL){
        head = temp;
        tail = temp;
        return;
    }
    if(position == 0){
        InsertAtBegin(data);
        return;
    }
    struct node* ptr = head;
    for(int i = 0; i < position-1; i++){
        ptr = ptr->next;
        if (ptr->next == NULL)
        {
            printf("Invalid position! Enter a valid position!\n\n");
            return;
        }
    }
    temp->next = ptr->next;
    ptr->next->prev = temp;
    ptr->next = temp;
    temp->prev = ptr;
    printf("Node Added!\n\n");
}

void DeleteAtBegin()
{
    if(head == NULL)
    {
        printf("Linked List is empty! Node can't delete!\n\n");
        return;
    }
    struct node* ptr = head;
    head = head->next;
    head->prev = NULL;
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
    struct node* ptr = tail;
    tail = tail->prev;
    tail->next = NULL;
    free(ptr);
    printf("Node deleted!\n\n");
}

void DeleteAtPosition(int position)
{
    if(head == NULL)
    {
        printf("Linked List is empty! Node can't delete!\n\n");
        return;
    }
    if(position == 0)
    {
        DeleteAtBegin();
        return;
    }
    struct node* ptr = head;
    for (int i = 0; i < position; i++)
    {
        ptr = ptr->next;
        if (ptr->next == NULL)
        {
            printf("Invalid position! Enter a valid position!\n\n");
            return;
        }
    }
    ptr->prev->next = ptr->next;
    ptr->next->prev = ptr->prev;
    free(ptr);
    printf("Node deleted!\n\n");
}

void Display()
{
    if(head == NULL)
    {
        printf("Linked List is empty! Node can't delete!\n\n");
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

void DisplayReverse()
{
    if(head == NULL)
    {
        printf("Linked List is empty! Node can't delete!\n\n");
        return;
    }
    struct node* ptr = tail;
    printf("\n");
    while(ptr != NULL)
    {
        printf("%d ",ptr->data);
        ptr = ptr->prev;
    }
    printf("\n\n");
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

int main(){
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
