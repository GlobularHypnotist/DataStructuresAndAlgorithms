//program to find factorial of a number
#include<stdio.h>
//recursive function to find factorial
long factorial(int n){  
	if(n == 0){
		return 1;
	}else{
		return(n * factorial(n - 1));
	}
}  

int main(){
	int number;
	long fact;
	//input a number
	printf("Enter a number: ");
	scanf("%d", &number);
	//calling the function
	fact = factorial(number); 
	printf("Factorial: %ld", fact);
	return 0;
}  
