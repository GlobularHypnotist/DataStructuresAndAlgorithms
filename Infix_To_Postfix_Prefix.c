//program to convert infix expression to postfix and prefix notation
#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

char stack[MAX];
int top=-1;
//push an element onto the stack
void push(char x){
    stack[++top]=x;
}
//pop an element from the stack
char pop(){
    if(top==-1)
        return -1;
    else
        return stack[top--];
}
//return precedence of an operator
int priority(char x){
    if (x == '(')
        return 0;
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    if (x == '^' || x == '$')
        return 3;
    return -1;
}
//function to convert infix expression to postfix notation
void infix_to_postfix(char infix[],char postfix[]){
    int i=0,j=0;
    char x;
    strcpy(postfix,"");
    while(infix[i]!='\0'){
        if(isalnum(infix[i]))
            postfix[j++]=infix[i];
        else if(infix[i]=='(')
            push(infix[i]);
        else if(infix[i]==')'){
            while((x=pop())!='(')
                postfix[j++]=x;
        }else{
            while(priority(stack[top])>=priority(infix[i]))
                postfix[j++]=pop();
            push(infix[i]);
        }
        i++;
    }
    while(top!=-1){
        postfix[j++]=pop();
    }
    postfix[j]='\0';
}
//function to convert infix expression to prefix notation
void infix_to_prefix(char infix[], char prefix[]){
    int i, j = 0;
    char x;
    strcpy(prefix, "");
    int len = strlen(infix);
	//reverse the infix expression
    for (i = len - 1; i >= 0; i--){
        if (isalnum(infix[i]))
            prefix[j++] = infix[i];
        else if (infix[i] == ')')
            push(infix[i]);
        else if (infix[i] == '('){
            while ((x = pop()) != ')')
                prefix[j++] = x;
        }else{
            while (priority(stack[top]) > priority(infix[i]))
                prefix[j++] = pop();
            push(infix[i]);
        }
    }

    while (top != -1){
        prefix[j++] = pop();
    }
    prefix[j] = '\0';

    //reverse the prefix notation to get the correct order
    for (i = 0; i < j / 2; i++){
        char temp = prefix[i];
        prefix[i] = prefix[j - 1 - i];
        prefix[j - 1 - i] = temp;
    }
}

int main(){
    char infix[MAX],postfix[MAX],prefix[MAX];
    int choice;
    do{
        printf("Menu:\n1. Infix to Postfix\n2. Infix to Prefix\n3. Exit\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("\nEnter the infix expression: ");
                scanf("%s",infix);
                infix_to_postfix(infix,postfix);
                printf("Postfix expression: %s\n\n",postfix);
                break;
            case 2:
                printf("\nEnter the infix expression: ");
                scanf("%s",infix);
                infix_to_prefix(infix,prefix);
                printf("Prefix expression: %s\n\n",prefix);
                break;
            case 3:
                return 0;
            default:
                printf("\nInvalid choice. Please try again.\n\n");
                break;
        }
    }while(choice != 3);
}

