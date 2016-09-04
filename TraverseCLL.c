#include<stdio.h>
#include <stdlib.h>

struct node{
  int data;
  struct node *next;
};

void traverse(struct node* head);

int main(){
  struct node *head;
  struct node *second;
  struct node *tail;

  head = (struct node *)malloc(sizeof(struct node));
  second = (struct node *)malloc(sizeof(struct node));
  tail = (struct node *)malloc(sizeof(struct node));

  head->data = 1;
  head->next = second;

  second->data = 2;
  second->next = tail;

  tail->data = 3;
  tail->next = head;

  traverse(second);
}

void traverse(struct node* head){
  struct node *current = head;

  if(current != NULL){
    do{
      printf("%d \n", current->data);
      current = current->next;
    }while(current != head);
  }
}
