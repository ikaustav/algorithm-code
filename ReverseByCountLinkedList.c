#include <stdio.h>
#include <stdlib.h>

struct node{
  int data;
  struct node *link;
};

void traverseLinkedList(struct node *linkedList);
void addNewNodeFront(struct node **head, int data);
struct node* reverseByCount(struct node *head, int count);

int main(){
  struct node **head;
  *head = NULL;

  addNewNodeFront(head, 1);
  addNewNodeFront(head, 2);
  addNewNodeFront(head, 3);
  addNewNodeFront(head, 4);
  addNewNodeFront(head, 5);

  traverseLinkedList(*head);
  printf("\n%s\n\n", "After reverse operation.");
  traverseLinkedList(reverseByCount(*head, 3));

  return 0;
}

struct node* reverseByCount(struct node *head, int count){
  struct node *prev = NULL;
  struct node *current = head;
  struct node *next = NULL;

  int i;
  for(i=1; i<=count && current!=NULL; i++){
    next = current->link;
    current->link = prev;
    prev = current;
    current = next;
  }

  if(current != NULL){
    head->link = reverseByCount(next, count);
  }

  return prev;
}

void addNewNodeFront(struct node **head, int data){
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  newNode->data = data;
  newNode->link = *head;

  *head = newNode;
}

void traverseLinkedList(struct node *linkedList){
  if(linkedList == NULL){
    return;
  }

  printf("Element value= %d \n", linkedList->data);
  traverseLinkedList(linkedList->link);
}
