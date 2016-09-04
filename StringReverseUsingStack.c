#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

struct Stack{
  int top;
  unsigned capacity;
  char *array;
};

struct Stack* createStack(int capacity){
  struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
  if(!stack){
    return NULL;
  }

  stack->top = -1;
  stack->capacity = capacity;
  stack->array = (char *)malloc(capacity * sizeof(char));

  return stack;
}

int isFull(struct Stack *root){
  return (root->capacity - 1) == root->top;
}

int isEmpty(struct Stack *root){
  return root->top == -1;
}

void push(struct Stack *root, char data){
  if(isFull(root)){
    printf("%s\n", "Stack full.");
    return;
  }
  printf("%s: %c \n", "Pushed", data);
  root->array[++(root->top)] = data;
}

char pop(struct Stack *root){
  if(isEmpty(root)){
    printf("%s\n", "Stack empty.");
    return '0';
  }
  char data = root->array[(root->top)--];
  return data;
}

char peek(struct Stack *root){
  if(isEmpty(root)){
    printf("%s\n", "Stack empty.");
    return '0';
  }
  char data = root->array[(root->top)];
  return data;
}

int main(){
  struct Stack *root = createStack(100);

  char arr[] = "Hello world.";
  int n = strlen(arr);

  int i;
  for(i=0; i<n; i++){
    push(root, arr[i]);
  }

  for(i=0; i<n; i++){
    arr[i] = pop(root);
  }

  printf("%s\n", arr);
}
