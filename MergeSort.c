//program to sort user input data in ascending order using merge sort
#include<stdio.h>
//merge two sorted sub-arrays into a single sorted array
void merge(int arr[], int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for(i = 0; i < n1; i++){
        L[i] = arr[l + i];
	}
    for(j = 0; j < n2; j++){
        R[j] = arr[m + 1 + j];
	}

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2){
        if (L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}
//recursively divide the array into smaller sub-arrays and sort them using merge()
void mergeSort(int arr[], int l, int r){
    if(l < r){
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
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
	//sort the array using mergeSort()
    mergeSort(arr, 0, n - 1);
	//print out the sorted array
    printf("Sorted array in ascending order:\n");
    for(i = 0; i < n; i++){
        printf("%d\t", arr[i]);
    }
    return 0;
}

