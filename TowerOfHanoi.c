//program to solve tower of hanoi
#include<stdio.h>
//recursive function for tower of hanoi
void towerOfHanoi(int n, char rodA, char rodC, char rodB){
	if(n == 1){
		printf("\nMove disk 1 from rod %c to rod %c", rodA, rodC);
		return;
	}
	towerOfHanoi(n-1, rodA, rodB, rodC);
	printf("\nMove disk %d from rod %c to rod %c", n, rodA, rodC);
	towerOfHanoi(n-1, rodB, rodC,rodA);
}
void main(){
	int no_of_disks;
	//input the number of disks
	printf("Enter the number of disks: ");
	scanf("%d", &no_of_disks);
	//calling the function
	towerOfHanoi(no_of_disks, 'A','C','B');
}
