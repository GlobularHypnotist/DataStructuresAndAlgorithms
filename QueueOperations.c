//program to implement basic queue operations
#include<stdio.h>
#include<stdlib.h>
//global variable and function prototype declaration
#define max 5
void enqueue();
void dequeue();
void display();
int queue[max], rear = -1, front = -1;
int main(){
    int choice;
    //select queue operation to be performed
    while(1){   
    	printf("Queue operations: \n");
        printf("\t1. Enqueue\n\t2. Dequeue\n\t3. Display\n\t4. Exit\n");
        scanf("%d", &choice);  
        switch(choice){
            case 1:
                enqueue();
                break;       
            case 2:
                dequeue();
                break;                   
            case 3:
                display();
                break;                    
            case 4:
                exit(0);                    
            default:
                printf("Invalid Entry!\n");
                break;                     
        }
    }    
    return 0;
} 
//function to insert items in queue
void enqueue(){
    int insert_item;
    printf("Enter an element to be enqueued: ");
    scanf("%d", &insert_item);       
    if(rear == max - 1){
    	printf("Queue Overflow!\n");           
    }
    else if(rear == -1){
        front = 0;
        rear = 0;
        queue[rear] = insert_item;
        printf("Element inserted!\n");
    }else{
        rear++;
        queue[rear] = insert_item;
        printf("Element inserted!\n");
    }
}   
//function to delete items from queue
void dequeue(){
    if(front == -1){
        printf("Queue Underflow!\n");
    }  
    else if(front == rear){
        front = -1;
        rear = -1;
    }else{
        front++;
    }
}  
//function to display the items in queue
void display(){
    int i;   
    if(rear == -1){
        printf("Queue is Empty !!");
    }else{
        printf("The elements in queue are: \n");
        for(i = front; i <= rear; i++){
            printf("%d\t", queue[i]);
        }
        printf("\n");
    }        
}
