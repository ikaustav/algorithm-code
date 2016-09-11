#include <stdio.h>
#include <stdlib.h>

void printNextGreaterElement(int arr[], int size);

int main(){
  int arr[] = {4,7,3,9,10,5};

  printNextGreaterElement(arr, 6);

  return 0;
}

void printNextGreaterElement(int arr[], int size){
  int i, j, next;
  for(i=0; i<size; i++){
    next = -1;
    for(j=i+1; j< size; j++){
      if(arr[j] > arr[i]){
        next = arr[j];
        break;
      }
    }
    printf("[+] Element: %d, Next greatest element: %d \n", arr[i], next);
  }
}
