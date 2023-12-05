//program to display fibonacci sequence
#include<stdio.h>
//recursive function for fibonacci sequence
int fibonacci(int n){
	if(n <= 1){
		return n;
	}else{
		return fibonacci(n - 1) + fibonacci(n - 2);
	}
}
int main(){
	int i, term;
	//input the term
	printf("Enter the term: ");
	scanf("%d", &term);
	//displaying fibonacci sequence
	for(i = 0; i <= term; i++){
		printf("%d\t", fibonacci(i));
	}
	return 0;
}

