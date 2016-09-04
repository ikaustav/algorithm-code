#include <stdio.h>
#include <stdlib.h>

struct Stack{
  int data;
  struct Stack *next;
};

void push(struct Stack **head, int data){
  struct Stack *newItem = (struct Stack *)malloc(sizeof(struct Stack));
  newItem->data = data;
  newItem->next = *head;

  *head = newItem;
}

int isEmpty(struct Stack *head)
{
    return !head;
}

void pop(struct Stack **head){
  if(isEmpty(*head)){
    return;
  }

  struct Stack *temp = *head;
  *head = temp->next;

  free(temp);
}

void peek(struct Stack *head){
  if(isEmpty(head)){
    printf("%s\n", "Empty stack.");
    return;
  }
  printf("%d\n", head->data);
}

int main(){
  struct Stack *stack = NULL;

  push(&stack, 4);
  push(&stack, 7);
  push(&stack, 9);

  peek(stack);
  pop(&stack);
  peek(stack);

  push(&stack, 1);
  pop(&stack);
  pop(&stack);
  pop(&stack);
  peek(stack);

}
