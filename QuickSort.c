//program to sort user input data in ascending order using quick sort
#include<stdio.h>
//function to partition a sub-array around a pivot element
int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low - 1, j, temp;

    for(j = low; j <= high - 1; j++){
        if (arr[j] <= pivot) {
            i++;
            //swap arr[i] with arr[j]
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    //swap arr[i + 1] with arr[high]
    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

//function to implement quick sort on the array
void quicksort(int arr[], int low, int high){
    if(low < high){
        int pi = partition(arr, low, high);

        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int main(){
    int n, i;
	//input the number of elements to sort
    printf("Enter the number of elements you want to sort: ");
    scanf("%d", &n);

    int arr[n];
	//input the elements to be sorted
    printf("Enter the elements you want to sort: \n");
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
	//sort the array using quicksort()
    quicksort(arr, 0, n - 1);
	//print out the sorted array
    printf("Sorted array in ascending order:\n");
    for(i = 0; i < n; i++){
        printf("%d\t", arr[i]);
    }
    return 0;
}

