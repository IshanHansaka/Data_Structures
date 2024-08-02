#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node* next;
};

struct node* createNewNode(int data);
void InsertAtBegin(int data);
void InsertAtEnd(int data);
void InsertAtPosition(int data, int position);
void DeleteAtBegin();
void DeleteAtEnd();
void DeleteAtPosition(int position);
void Display();
void FreeList(struct node* ptr);

struct node* head = NULL;

struct node* createNewNode(int data)
{
    struct node* temp = (struct node*) malloc(sizeof(struct node));
    if(temp == NULL){
        printf("Memory allocation failed!\n");
        exit(1);
    }
    temp->data = data;
    temp->next = temp;
    return temp;   
}

void InsertAtBegin(int data)
{
  struct node* temp = createNewNode(data);
  if(head == NULL)
  {
    head = temp;
    return;
  }
  temp->next = head;
  struct node* ptr = head;
  while (ptr->next != head) {
    ptr = ptr->next;
  }
  ptr->next = temp;
  head = temp;
  printf("Node Added!\n\n");
}

void InsertAtEnd(int data) {
  struct node* temp = createNewNode(data);
  if (head == NULL) {
    head = temp;
    return;
  }
  struct node* ptr = head;
  while (ptr->next != head) {
    ptr = ptr->next;
  }
  ptr->next = temp;
  temp->next = head;
  printf("Node Added!\n\n");
}

void InsertAtPosition(int data, int position) {
  if (position == 0) {
    InsertAtBegin(data);
    return;
  }
  struct node* temp = createNewNode(data);
  if (head == NULL) {
    head = temp;
    return;
  }
  struct node* ptr = head;
  for (int i = 1; i < position; i++) {
    if (ptr == head) {
        printf("Invalid position! Enter a valid position!\n\n");
        return ;
    }
    ptr = ptr->next;
  }
  if (ptr->next == head) {
    InsertAtEnd(data);
    return;
  }
  temp->next = ptr->next;
  ptr->next = temp;
  printf("Node Added!\n\n");  
}

void DeleteAtBegin() {
  if (head == NULL) {
    printf("Linked List is empty! Nothing to delete!\n");
    return ;
  }
  struct node* ptr = head;
  if (head->next == head) {
    head = NULL;
    free(ptr);
    printf("Node Deleted!\n\n");
    return ;
  }
  while (ptr->next != head) {
    ptr = ptr->next;
  }
  ptr->next = head->next;
  ptr = head;
  head = head->next;
  free(ptr);
  printf("Node Deleted!\n\n");  
}

void DeleteAtEnd() {
  if (head == NULL) {
    printf("Linked List is empty! Nothing to delete!\n");
    return ;
  }
  struct node* ptr = head;
  if (head->next == head) {
    head = NULL;
    free(ptr);
    printf("Node Deleted!\n\n");
    return;
  }
  while (ptr->next->next != head) {
    ptr = ptr->next;
  }
  struct node* temp = ptr->next;
  ptr->next = head;
  free(temp);
  printf("Node Deleted!\n\n");
}

void DeleteAtPosition(int position) {
  if (head == NULL) {
    printf("Linked List is empty! Nothing to delete!\n");
    return ;
  }
  if (position == 0)
  {
    DeleteAtBegin();
    return;
  }
  struct node* ptr = head;
  if (head->next == head) {
    head = NULL;
    free(ptr);
    printf("Node Deleted!\n\n");
    return;
  }
  for (int i = 1; i < position; i++) {
    ptr = ptr->next;
    if (ptr == head) {
      printf("Invalid position! Enter a valid position!\n\n");
      return ;
    }
  }
  if (ptr->next == head) {
    DeleteAtEnd();
    return;
  }
  struct node* temp = ptr->next;
  ptr->next = temp->next;
  free(temp);
  printf("Node Deleted!\n\n");
}

void Display() {
  if (head == NULL) {
    printf("Linked List is empty!\n\n");
    return;
  }
  struct node* ptr = head;
  printf("\n");
  while (ptr->next != head) {
    printf("%d ", ptr->data);
    ptr = ptr->next;
  }
  printf("%d ", ptr->data);
  printf("\n\n");
}

void FreeList(struct node* ptr) {
  if (ptr->next != head) {
      FreeList(ptr->next);
  }
  free(ptr);
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
        //DisplayReverse();
        printf("\n\n");
        break;
    case 9:
        printf("Enter data to search: ");
        scanf("%d", &data);
        //Search(data);
        break;
    case 10:
        printf("Enter position to Update: ");
        scanf("%d", &position);
        printf("Enter data to add: ");
        scanf("%d", &data);
        //Update(data, position);
        break;
    case 11:
        FreeList(head);
        return 0;
    default:
        printf("Wrong input, try again!\n\n");
    }
  }
}