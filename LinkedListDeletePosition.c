#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *link;
};
void traverseLinkedList(struct node *);
void deleteNode(struct node **, int);

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
  deleteNode(&head, 0);
  traverseLinkedList(head);

  return 0;
}

void traverseLinkedList(struct node *linkedList){
  struct node *cursor = linkedList;

  while(cursor != NULL){
    printf("Element value= %d \n", cursor->data);
    cursor = cursor->link;
  }
  printf("%s \n", "End of Linked List");
}

void deleteNode(struct node **linkedList, int position){
  if(position < 0){
    printf("%s\n", "Please enter a correct position.");
    return;
  }

  if(*linkedList == NULL){
    printf("%s\n", "Linked List is empty.");
    return;
  }

  struct node *cursor = *linkedList, *prev;

  if(position == 0){
    *linkedList = cursor->link;
    free(cursor);
    return;
  }

  prev = cursor;
  cursor = cursor->link;

  for(int i = 1; i < position && cursor != NULL; i++){
    prev = cursor;
    cursor = cursor->link;
  }
  if(cursor == NULL){
    printf("%s\n", "Empty at to be deleted position.");
    return;
  }

  prev->link = cursor->link;
  free(cursor);
}
