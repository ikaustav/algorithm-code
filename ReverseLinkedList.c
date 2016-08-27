#include<stdio.h>

#include <stdio.h>
#include <stdlib.h>

struct node{
  int data;
  struct node *link;
};

void traverseLinkedList(struct node *linkedList);
void interchangeNodes(struct node **firstNode, int key1, int key2);

int main(){
  struct node *head;
  struct node *second;
  struct node *tail;

  head = (struct node *)malloc(sizeof(struct node));
  second = (struct node *)malloc(sizeof(struct node));
  tail = (struct node *)malloc(sizeof(struct node));

  head->data = 1;
  head->link = second;

  second->data = 2;
  second->link = tail;

  tail->data = 3;
  tail->link = NULL;

  traverseLinkedList(head);
  interchangeNodes(&head, 3, 2);
  traverseLinkedList(head);

  return 0;
}

void reverseLinkedList(struct node **head){
  struct node *pointerNode = *head, *prevNode = NULL;

  while(pointerNode->link != NULL){
    prevNode = pointerNode;
    pointerNode = pointerNode->link;
  }

  swap(head, prevNode, *head, prevNode, pointerNode);
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

  struct node *pointerNode = *head;

  while(pointerNode->link != secondNode){
    secondNodePrev = pointerNode;
    pointerNode = pointerNode->link;
  }

  swap(head, firstNode, firstNode->link, secondNodePrev, pointerNode);
}


void traverseLinkedList(struct node *linkedList){
  struct node *cursor = linkedList;

  while(cursor != NULL){
    printf("Element value= %d \n", cursor->data);
    cursor = cursor->link;
  }
  printf("%s \n", "End of Linked List");
}
