#include <stdio.h>
#include <stdlib.h>

struct Stack{
  int top;
  unsigned capacity;
  int *array;
};

struct Stack* createStack(unsigned capacity){
  struct Stack *stack = (struct Stack*)malloc(sizeof(struct Stack));
  stack->top = -1;
  stack->capacity = capacity;
  stack->array = (int *)malloc(capacity * sizeof(int));

  return stack;
}

int isFull(struct Stack *stack){
  return ((stack->capacity - 1) - stack->top) == 0;
}

int isEmpty(struct Stack *stack){
  return stack->top == -1;
}

void push(struct Stack *stack, int data){
  if(isFull(stack)){
    return;
  }
  stack->array[++(stack->top)] = data;
}

int pop(struct Stack *stack){
  if(isEmpty(stack)){
    return -1;
  }
  return stack->array[(stack->top)--];
}

int peek(struct Stack *stack){
  if(isEmpty(stack)){
    return -1;
  }

  return stack->array[stack->top];
}

int main(){
  struct Stack *stack = createStack(100);
  printf("Is empty: %d\n", isEmpty(stack));

  push(stack, 4);
  push(stack, 7);
  push(stack, 9);

  printf("Top: %d\n", peek(stack));
  printf("Popped: %d\n", pop(stack));
  printf("Top: %d\n", peek(stack));
}
