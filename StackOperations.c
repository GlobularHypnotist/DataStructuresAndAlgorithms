//program to implement basic stack operations
#include<stdio.h>
#include<stdlib.h>
#define maxSize 50
int top = -1, stack[maxSize];
//function to insert items in stack
void push(){
    int data;
    if(top == maxSize - 1){
        printf("Stack Overflow!\n");
    }else{
        top += 1;
        printf("Enter an item: ");
        scanf("%d", &data);
        stack[top] = data;
    }
}
//function to delete items from stack
void pop(){
    if(top == -1){
        printf("Stack Underflow!\n");
    }else{
        top -= 1;
    }
}
//function to display the items in stack
void display(){
    int i;
    if(top == -1){
        printf("\nStack is Empty!\n\n");
    }else{
        printf("Items in stack: \n");
        for(i = 0; i <= top; i++){
            printf("%d\n", stack[i]);
        }
    }
}
void main(){
    int n;
    start:
        //select stack operation to be performed
        printf("Stack Operations:\n1. push()\n2. pop()\n3. display()\n4. Exit\n");
        scanf("%d", &n);
            switch(n){
            case 1:
                push();
                goto start;
            case 2:
                pop();
                goto start;
            case 3:
                display();
                goto start;
            case 4:
                exit(0);
            default:
                printf("Invalid Entry!\n");
                goto start;
            }
}
