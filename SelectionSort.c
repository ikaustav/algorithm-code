#include<stdio.h>

void selectionSort(int arr[], int size);
void swap( int *firstVal, int *secondVal);

int main(){
  int arr[] = {4, 1, 7, 99, 45, 12, 9};
  int size = sizeof(arr)/sizeof(arr[0]);
  selectionSort(arr, size);

  int i;
  for(i=0; i<size; i++){
    printf("%d\n", arr[i]);
  }
}

void selectionSort(int arr[], int size){
  int i, j, minIndex;
  for(i=0; i<size-1; i++){
    minIndex = i;
    for(j=i+1; j<size; j++){
      if(arr[j] < arr[minIndex]){
        minIndex = j;
      }
    }

    swap(&arr[i], &arr[minIndex]);
  }
}

void swap( int *firstVal, int *secondVal){
  int temp = *firstVal;
  *firstVal = *secondVal;
  *secondVal = temp;
}
