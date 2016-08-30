#include <stdio.h>
#include <stdlib.h>

struct node{
  int data;
  struct node *link;
};

void traverseLinkedList(struct node *linkedList);
struct node* mergeSortedLinkedList(struct node *firstListHead, struct node *secondListHead);

int main(){
  struct node *head;
  struct node *second;
  struct node *tail;

  head = (struct node *)malloc(sizeof(struct node));
  second = (struct node *)malloc(sizeof(struct node));
  tail = (struct node *)malloc(sizeof(struct node));

  head->data = 2;
  head->link = second;

  second->data = 5;
  second->link = tail;

  tail->data = 9;
  tail->link = NULL;

  struct node *head2;
  struct node *second2;
  struct node *tail2;

  head2 = (struct node *)malloc(sizeof(struct node));
  second2 = (struct node *)malloc(sizeof(struct node));
  tail2 = (struct node *)malloc(sizeof(struct node));

  head2->data = 3;
  head2->link = second2;

  second2->data = 4;
  second2->link = tail2;

  tail2->data = 4;
  tail2->link = NULL;

  traverseLinkedList(head);
  traverseLinkedList(head2);
  traverseLinkedList(mergeSortedLinkedList(head, head2));

  return 0;
}

struct node* mergeSortedLinkedList(struct node *currentFirstPointer, struct node *currentSecondPointer){
  struct node *newListPointer;
  struct node **head;
  *head = NULL;

  if(currentFirstPointer != NULL && currentSecondPointer != NULL){
    if(currentFirstPointer->data <= currentSecondPointer->data){
      *head = newListPointer = currentFirstPointer;
      currentFirstPointer = currentFirstPointer->link;
    }
    else{
      *head = newListPointer = currentSecondPointer;
      currentSecondPointer = currentSecondPointer->link;
    }

    while(currentFirstPointer != NULL && currentSecondPointer != NULL){
      if(currentFirstPointer->data <= currentSecondPointer->data){
        newListPointer->link = currentFirstPointer;
        newListPointer = newListPointer->link;
        currentFirstPointer = currentFirstPointer->link;
      }
      else{
        newListPointer->link = currentSecondPointer;
        newListPointer = newListPointer->link;
        currentSecondPointer = currentSecondPointer->link;
      }
    }

    if(currentFirstPointer == NULL){
      newListPointer->link = currentSecondPointer;
    }
    else{
      newListPointer->link = currentFirstPointer;
    }
  }
  else if(currentFirstPointer == NULL && currentSecondPointer != NULL){
    *head = currentSecondPointer;
  }
  else if(currentFirstPointer != NULL && currentSecondPointer == NULL){
    *head = currentFirstPointer;
  }

  return *head;
}

void traverseLinkedList(struct node *linkedList){
  struct node *cursor = linkedList;

  while(cursor != NULL){
    printf("Element value= %d \n", cursor->data);
    cursor = cursor->link;
  }
  printf("%s \n", "End of Linked List");
}
