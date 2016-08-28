#include<stdio.h>
#include <stdlib.h>

struct node{
  int data;
  struct node *link;
};

void traverseLinkedList(struct node *linkedList);
void interchangeNodes(struct node **firstNode, int key1, int key2);
void reverseLinkedList3(struct node **head, struct node *firstPart, struct node *secondPart);
void startReverse(struct node **head);

int main(){
  struct node *head;
  struct node *second;
  struct node *third;
  struct node *tail;

  head = (struct node *)malloc(sizeof(struct node));
  second = (struct node *)malloc(sizeof(struct node));
  third = (struct node *)malloc(sizeof(struct node));
  tail = (struct node *)malloc(sizeof(struct node));

  head->data = 1;
  head->link = NULL;

  second->data = 2;
  second->link = third;

  third->data = 3;
  third->link = tail;

  tail->data = 4;
  tail->link = NULL;

  traverseLinkedList(head);
  startReverse(&head);
  traverseLinkedList(head);

  return 0;
}

void startReverse(struct node **head){
  if(*head == NULL){
    return;
  }

  reverseLinkedList3(head, NULL, *head);
}

void reverseLinkedList3(struct node **head, struct node *firstPart, struct node *secondPart){
  if(secondPart == NULL){
    *head = firstPart;
    return;
  }

  reverseLinkedList3(head, secondPart, secondPart->link);
  secondPart->link = firstPart;
}


void traverseLinkedList(struct node *linkedList){
  struct node *cursor = linkedList;

  while(cursor != NULL){
    printf("Element value= %d \n", cursor->data);
    cursor = cursor->link;
  }
  printf("%s \n", "End of Linked List");
}
