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
void DeleteAtposition(int possition);



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
        if (ptr->next == NULL)
        {
            printf("Invalid position! Enter a valid position!\n\n");
            return;
        }
        ptr = ptr->next;
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

void DeleteAtposition(int possition)
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
    for (int i = 0; i < possition; i++)
    {
        if (ptr == NULL)
        {
            printf("Invalid position! Enter a valid position!\n\n");
            return;
        }
        ptr = ptr->next;
    }
    ptr->prev->next = ptr->next;
    ptr->next->prev = ptr->prev;
    free(ptr);
    printf("Node deleted!\n\n");
}

void Display()
{

}

int main(){

    return 0;
}
