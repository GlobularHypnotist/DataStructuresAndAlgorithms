//program to sort user input data in ascending order using bubble sort
#include<stdio.h>
//function to perform bubble sort on an array of integers
void bubble_sort(int arr[], int n){
    int i, j, temp;

    //iterate through the array n - 1 times
    for(i = 0; i < n - 1; i++){
        //iterate through the unsorted portion of the array
        for(j = 0; j < n - i - 1; j++){
            //if adjacent elements are out of order, swap them
            if(arr[j] > arr[j + 1]){
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main(){
    int n, i;

	//input the number of elements to sort
    printf("Enter the number of elements you want to sort: ");
    scanf("%d", &n);
    
    int arr[n];

	//input the elements to be sorted
    printf("Enter the elements you want to sort:\n");
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    //sort the array using the bubble_sort function
    bubble_sort(arr, n);

    //print out the sorted array in ascending order
    printf("Sorted array in ascending order:\n");
    for(i = 0; i < n; i++){
        printf("%d\t", arr[i]);
    }
    return 0;
}

