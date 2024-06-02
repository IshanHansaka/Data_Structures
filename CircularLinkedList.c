#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node* next;
};

struct node* head = NULL;

struct node* createNewNode(int data)
{
    struct node* temp = (struct node*) malloc(sizeof(struct node));
    if(temp == NULL){
        printf("Memory allocation failed!\n");
        exit(1);
    }
    temp->data = data;
    temp->next = NULL;
    return temp;   
}

int main(){
  return 0;
}