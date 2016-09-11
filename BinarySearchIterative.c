#include<stdio.h>

int binarySearch(int arr[], int low, int high, int target);

int main(){
  int arr[] = {4, 7, 9, 12, 20, 45};
  printf("Target at index: %d\n", binarySearch(arr, 0, 5, 45));
}

int binarySearch(int arr[], int low, int high, int target){
  int mid;
  while(low <= high){
    mid = (low +high) / 2;

    if(arr[mid] == target){
      return mid;
    }
    else if(arr[mid] < target){
      low = mid + 1;
    }
    else{
      high = mid - 1;
    }
  }

  return -1;
}
