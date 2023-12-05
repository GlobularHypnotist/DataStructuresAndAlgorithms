//program to evaluate postfix and prefix expression
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define STACK_SIZE 100

//stack implementation
int stack[STACK_SIZE];
int top = -1;

void push (int value) {
  if (top >= STACK_SIZE-1) {
    printf("Stack overflow\n");
    exit(1);
  }
  stack[++top] = value;
}

int pop () {
  if (top < 0) {
    printf("Stack underflow\n");
    exit(1);
  }
  return stack[top--];
}

void clearStack () {
  top = -1;
}

//evaluate postfix expression
int evaluatePostfix (char* expression) {
  int i, x, y;
  clearStack();
  for (i=0; expression[i]!='\0'; i++) {
    if (isdigit(expression[i])) {
      push(expression[i]-'0'); //convert char to int
    }
    else {
      x = pop();
      y = pop();
      switch (expression[i]) {
        case '+': push(y+x); break;
        case '-': push(y-x); break;
        case '*': push(y*x); break;
        case '/': push(y/x); break;
        case '^': push(pow(y, x)); break;
        case '$': push(pow(y, x)); break;
        default: printf("Invalid operator: %c\n", expression[i]); exit(1);
      }
    }
  }
  return pop();
}

//evaluate prefix expression
int evaluatePrefix (char* expression) {
  int i, x, y;
  clearStack();
  for (i=strlen(expression)-1; i>=0; i--) {
    if (isdigit(expression[i])) {
      push(expression[i]-'0'); //convert char to int
    }
    else {
      x = pop();
      y = pop();
      switch (expression[i]) {
        case '+': push(x+y); break;
        case '-': push(x-y); break;
        case '*': push(x*y); break;
        case '/': push(x/y); break;
        case '^': push(pow(x, y)); break;
        case '$': push(pow(x, y)); break;
        default: printf("Invalid operator: %c\n", expression[i]); exit(1);
      }
    }
  }
  return pop();
}

int main () {
  char expression[100];
  int choice, result;
  do {
    printf("Select evaluation type:\n1. Postfix\n2. Prefix\n");
    scanf("%d", &choice);
    
    printf("\nEnter expression: ");
    scanf("%s", expression);

    switch (choice) {
      case 1:
        result = evaluatePostfix(expression);
        printf("Result: %d\n", result);
        break;
      
      case 2:
        result = evaluatePrefix(expression);
        printf("Result: %d\n", result);
        break;
      
      default:
        printf("Invalid choice\n");
    }

    printf("\nDo you want to evaluate another expression?(y/n): ");
    scanf(" %c", &choice);
  } while (choice == 'y');
  
  return 0;
}

