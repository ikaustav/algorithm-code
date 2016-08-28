#include<stdio.h>
#include <stdlib.h>

struct node{
  int data;
  struct node *link;
};

void traverseLinkedList(struct node *linkedList);
void interchangeNodes(struct node **firstNode, int key1, int key2);
void reverseLinkedList2(struct node **head);

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
  head->link = second;

  second->data = 2;
  second->link = NULL;

  third->data = 3;
  third->link = tail;

  tail->data = 4;
  tail->link = NULL;

  traverseLinkedList(head);
  reverseLinkedList2(&head);
  traverseLinkedList(head);

  return 0;
}


void reverseLinkedList2(struct node **head){
  struct node *prev = NULL;
  struct node *current = *head;
  struct node *next = NULL;

  while(current != NULL){
    next = current->link;
    current->link = prev;
    prev = current;
    current = next;
  }

  *head = prev;
}


void traverseLinkedList(struct node *linkedList){
  struct node *cursor = linkedList;

  while(cursor != NULL){
    printf("Element value= %d \n", cursor->data);
    cursor = cursor->link;
  }
  printf("%s \n", "End of Linked List");
}
