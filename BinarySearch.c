//program to search the key using Binary Search
#include<stdio.h>
//function to perform binary search
int binarySearch(int arr[], int left, int right, int key){
    if(right >= left){
        int mid = left + (right - left) / 2;

        //if the key is present at the middle itself
        if (arr[mid] == key){
            return mid;
		}
        //if the key is smaller than the middle element, then it can only be present in the left sub-array
        if (arr[mid] > key){
            return binarySearch(arr, left, mid - 1, key);
		}else{
        	//else the key can only be present in the right sub-array
        	return binarySearch(arr, mid + 1, right, key);
    	}
    }
    //if the key is not present in the array
    return -1;
}
int main(){
    int n;
    //input the number of elements
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n], i;
    //input the elements in the array
    printf("Enter the elements in the array in sorted order:\n");
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
	//input the key to be searched
    int key;
    printf("Enter the key to be searched: ");
    scanf("%d", &key);

    int result = binarySearch(arr, 0, n - 1, key);
	//print out the index of the key if found
    if (result == -1){
        printf("Key not present in the array!");
    }else{
        printf("Key found at index: %d", result);
	}
    return 0;
}

