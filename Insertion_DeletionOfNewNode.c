//program to insert a new node in the beginning and the end of singly linked list
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void insertAtBeginning(struct node** head_ref, int new_data) {
    //allocate new node
    struct node* new_node = (struct node*)malloc(sizeof(struct node));

    //put in the data
    new_node->data = new_data;

    //make next of new node as head
    new_node->next = (*head_ref);

    //move the head to point to the new node
    (*head_ref) = new_node;
}

void insertAtEnd(struct node** head_ref, int new_data) {
    //allocate new node and initialization to NULL Pointer
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    struct node* last = *head_ref;

    //put in the data
    new_node->data = new_data;
    new_node->next = NULL;

    //if the Linked List is empty, then make the new node as head
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    //traverse till the last node
    while (last->next != NULL)
        last = last->next;

    //change the next of the last node
    last->next = new_node;
    return;
}

int main() {
    struct node* head = NULL;
    int choice, data;

    //ask user for choice of insertion until they decide to exit
    while (1) {
        printf("1. Insert new node at the beginning\n2. Insert new node at the end\n3. Exit\n");
        scanf("%d", &choice);

        if (choice == 3)
            break;

        printf("Enter data: ");
        scanf("%d", &data);

        if (choice == 1)
            insertAtBeginning(&head, data);
        else if (choice == 2)
            insertAtEnd(&head, data);
        else
            printf("Invalid choice!\n");
    }

    //print the linked list
    printf("Elements in linked list: \n");
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    return 0;
}
