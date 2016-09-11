#include<stdio.h>

void bubbleSort(int arr[], int size);
void swap(int *firstVal, int *secondVal);

int main(){
  int arr[] = {4, 1, 7, 99, 45, 12, 9};
  //int arr[] = {1,2,3,4,5,6,7,8};
  int size = sizeof(arr)/sizeof(arr[0]);
  bubbleSort(arr, size);

  int i;
  for(i=0; i<size; i++){
    printf("%d\n", arr[i]);
  }
}

void bubbleSort(int arr[], int size){
  int i, j;
  int swapped;
  for(i=0; i<size-1; i++){
    swapped = 0;
    for(j=0; j<size-i-1; j++){
      if(arr[j] > arr[j+1]){
        swap(&arr[j], &arr[j+1]);
        swapped = 1;
      }
    }

    if(swapped == 0){
      break;
    }
  }
}

void swap( int *firstVal, int *secondVal){
  int temp = *firstVal;
  *firstVal = *secondVal;
  *secondVal = temp;
}
