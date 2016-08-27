#include<stdio.h>

#include <stdio.h>
#include <stdlib.h>

struct node{
  int data;
  struct node *link;
};

void traverseLinkedList(struct node *linkedList);
void interchangeNodes(struct node **firstNode, int key1, int key2);
void reverseLinkedList(struct node **head);
void swap(struct node **head, struct node *firstNodePrev, struct node *firstNode,
  struct node *secondNodePrev, struct node *secondNode);

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
  reverseLinkedList(&head);
  traverseLinkedList(head);

  return 0;
}


void reverseLinkedList(struct node **head){
  struct node *pointerNode = *head;
  struct node *prevNode = NULL;

  while((pointerNode->link) != NULL){
    prevNode = pointerNode;
    pointerNode = pointerNode->link;
  }

  printf("[+] swap %p, %p, %p, %p \n", NULL, *head, prevNode, pointerNode);
  swap(head, NULL, *head, prevNode, pointerNode);
}


void swap(struct node **head, struct node *firstNodePrev, struct node *firstNode,
  struct node *secondNodePrev, struct node *secondNode){

  if(firstNode == secondNode || secondNode->link == firstNode){
    printf("%s\n", "End of swapping.");
    return;
  }

  if(firstNodePrev == NULL){
    *head = secondNode;
  }
  else{
    firstNodePrev->link = secondNode;
  }
  secondNodePrev->link = firstNode;

  struct node *temp = secondNode->link;
  secondNode->link = firstNode->link;
  firstNode->link = temp;

  traverseLinkedList(*head);

  struct node *pointerNode = *head;

  while(pointerNode->link != firstNode){
    secondNodePrev = pointerNode;
    pointerNode = pointerNode->link;
  }

  printf("[+] swap %p, %p, %p, %p \n", secondNode, secondNode->link, secondNodePrev, pointerNode);
  swap(head, secondNode, secondNode->link, secondNodePrev, pointerNode);
}


void traverseLinkedList(struct node *linkedList){
  struct node *cursor = linkedList;

  while(cursor != NULL){
    printf("Element value= %d \n", cursor->data);
    cursor = cursor->link;
  }
  printf("%s \n", "End of Linked List");
}
