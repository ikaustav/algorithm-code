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

struct node* mergeSortedLinkedList(struct node *list1, struct node *list2){
  if(list1 == NULL){
    return list2;
  }
  if(list2 == NULL){
    return list1;
  }

  if(list1->data < list2->data){
    list1->link = mergeSortedLinkedList(list1->link, list2);
    return list1;
  }
  else{
    list2->link = mergeSortedLinkedList(list2->link, list1);
    return list2;
  }
}

void traverseLinkedList(struct node *linkedList){
  struct node *cursor = linkedList;

  while(cursor != NULL){
    printf("Element value= %d \n", cursor->data);
    cursor = cursor->link;
  }
  printf("%s \n", "End of Linked List");
}
