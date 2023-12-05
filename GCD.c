//program to find gcd of two numbers
#include<stdio.h>
//recursive function to find gcd
int gcdFunction(int a, int b){
	if(b == 0){
		return a;
	}
	return gcdFunction(b, a % b);
}
int main(){
	int x, y, gcd;
	//input two integers
	printf("Enter two integers: \n");
	scanf("%d%d", &x, &y);
	//calling the function
	gcd = gcdFunction(x, y);
	//displaying the gcd of two integers
	printf("GCD(x, y) = %d", gcd);
	return 0;
}

