#include <stdio.h>
#include <stdlib.h>

struct node{
  int data;
  struct node *link;
};

void traverseLinkedList(struct node *);
void addLastNode(struct node **, int);
void deleteNodeUsingKey(struct node **, int);

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

  //head = NULL;

  addLastNode(&head, 7);
  traverseLinkedList(head);
  deleteNodeUsingKey(&head, 3);
  traverseLinkedList(head);

  return 0;
}

/* Add a new node after the last node */
void addLastNode(struct node **firstNode, int data){
  struct node *nodePointer = *firstNode;

  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  newNode->data = data;
  newNode->link = NULL;

  if(nodePointer == NULL){
    printf("%s\n", "Linked List empty");
    *firstNode = newNode;

    return;
  }

  while(nodePointer->link != NULL){
    nodePointer = nodePointer->link;
  }

  nodePointer->link = newNode;
}

/* Delete a node from the linked list using a key */
void deleteNodeUsingKey(struct node **firstNode, int key){
  struct node *cursor = *firstNode;
  struct node *prev;

  if(cursor != NULL && cursor->data == key){
    printf("%s\n", "Key found at first node.");

    *firstNode = cursor->link;
    free(cursor);
    return;
  }

  while(cursor != NULL && cursor->data != key){
    prev = cursor;
    cursor = cursor->link;
  }

  if(cursor == NULL){
    printf("%s\n", "Key not found.");
    return;
  }

  printf("%s\n", "Key found.");
  prev->link = cursor->link;
  free(cursor);
}

/* Traverse the linked list */
void traverseLinkedList(struct node *linkedList){
  struct node *cursor = linkedList;

  while(cursor != NULL){
    printf("Element value= %d \n", cursor->data);
    cursor = cursor->link;
  }
  printf("%s \n", "End of Linked List");
}
