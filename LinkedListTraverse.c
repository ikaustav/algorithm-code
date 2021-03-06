#include <stdio.h>
#include <stdlib.h>

struct node{
  int data;
  struct node *link;
};

void traverseLinkedList(struct node *linkedList);

int main(){
  struct node *head;
  struct node *second;
  struct node *tail;

  head = (struct node *)malloc(sizeof(struct node));
  second = (struct node *)malloc(sizeof(struct node));
  tail = (struct node *)malloc(sizeof(struct node));

  head->data = 1;
  head->link = second;

  second->data = 5;
  second->link = tail;

  tail->data = 3;
  tail->link = NULL;

  traverseLinkedList(head);

  free(head);
  free(second);
  free(tail);

  return 0;
}

void traverseLinkedList(struct node *linkedList){
  if(linkedList == NULL){
    return;
  }

  printf("Element value= %d \n", linkedList->data);
  traverseLinkedList(linkedList->link);
}
