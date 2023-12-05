//program to find the sum of integers in dynamically allocated memory
#include<stdio.h>
#include<stdlib.h>
void main(){
    int i, n, m, *ptr, sum = 0;
    //dynamic memory allocation using malloc
    printf("Enter the number of memory to be allocated: ");
    scanf("%d", &n);
    ptr = (int*)malloc(n * sizeof(int));
    if(ptr == NULL){
        printf("Memory allocation failed!");
        exit(1);
    }
    //enter integers in allocated memory and find sum of the integers
    printf("Enter integers in allocated memory: \n");
    for(i = 0; i < n; i++){
        scanf("%d", ptr + i);
        sum += *(ptr + i);
    }
    printf("\nSum of the integers entered: %d\n", sum);
    //reallocation of memory using realloc
    printf("Enter the number of memory to be re-allocated: ");
    scanf("%d", &m);
    ptr = (int*)realloc(ptr, m * sizeof(int));
    if(ptr == NULL){
        printf("Memory re-allocation failed!");
        exit(1);
    }
    //enter integers in re-allocated memory and find sum of the integers
    printf("Enter integers in re-allocated memory: \n");
    for(i = n; i < m; i++){
        scanf("%d", ptr + i);
        sum += *(ptr + i);
    }
    printf("\nSum of the integers entered: %d", sum);
    free(ptr);
}
