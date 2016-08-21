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

void interchangeNodes(struct node **firstNode, int key1, int key2){
  if(key1 == key2){
    return;
  }

  struct node *prev1 = NULL, *prev2 = NULL;
  struct node *cursor1 = *firstNode, *cursor2 = *firstNode;

  while(cursor1 != NULL && cursor1->data != key1){
    prev1 = cursor1;
    cursor1 = cursor1->link;
  }

  while(cursor2 != NULL && cursor2->data != key2){
    prev2 = cursor2;
    cursor2 = cursor2->link;
  }

  if(cursor1 == NULL || cursor2 == NULL){
    return;
  }

  if(prev1 == NULL){
    *firstNode = cursor2;
  }
  else{
    prev1->link = cursor2;
  }

  if(prev2 == NULL){
    *firstNode = cursor1;
  }
  else{
    prev2->link = cursor1;
  }

  struct node *temp = cursor1->link;
  cursor1->link = cursor2->link;
  cursor2->link = temp;
}


void traverseLinkedList(struct node *linkedList){
  struct node *cursor = linkedList;

  while(cursor != NULL){
    printf("Element value= %d \n", cursor->data);
    cursor = cursor->link;
  }
  printf("%s \n", "End of Linked List");
}
