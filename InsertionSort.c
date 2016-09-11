#include<stdio.h>

void insertionSort(int arr[], int size);

int main(){
  int arr[] = {4, 1, 7, 99, 45, 12, 9};
  //int arr[] = {1,2,3,4,5,6,7,8};
  int size = sizeof(arr)/sizeof(arr[0]);
  insertionSort(arr, size);

  int i;
  for(i=0; i<size; i++){
    printf("%d\n", arr[i]);
  }
}

void insertionSort(int arr[], int size){
  int i, j, key;
  for(i=1; i<size; i++){
    key = arr[i];
    j = i-1;

    while(j>=0 && arr[j] > key){
      arr[j+1] = arr[j];
      j = j-1;
    }
    arr[j+1] = key;
  }
}
