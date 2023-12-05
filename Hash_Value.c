//program to generate hash value for a string entered by the user
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//function to calculate hash value using folding method
int foldingHash(char* key, int tableSize) {
    int sum = 0;
    int len = strlen(key);
    int i;
    for (i = 0; i < len; i++) {
        sum += key[i];
    }
    int hashVal = sum % tableSize;
    return hashVal;
}
//function to calculate hash value using mid-square method
int midSquareHash(char* key, int tableSize) {
    long long int hashedKey = 0;
    int i;
    for (i = 0; i < strlen(key); i++) {
        hashedKey += key[i];
    }
    long long int squaredKey = hashedKey * hashedKey;
    int midDigits = tableSize / 2;
    int offset = strlen(key) / 2;
    squaredKey >>= (sizeof(long long int) * 8 - midDigits);
    squaredKey &= (1 << midDigits) - 1;
    squaredKey += offset;
    squaredKey %= tableSize;
    return squaredKey;
}
int main() {
    char key[100];
    int tableSize, n, m;
    //input string and hash table size
    printf("Enter a string: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0';
    printf("Enter hash table size: ");
    scanf("%d", &tableSize);
    int hashVal1, hashVal2;
	runCode:
	    //switch statement to let the user choose the method for finding the hash value
	    printf("\nChoose a hashing method:\n");
	    printf("1. Folding method\n");
	    printf("2. Mid-square method\n");
	    scanf("%d", &n);
	    switch (n) {
	        //case for using the folding method
	        case 1:
	            hashVal1 = foldingHash(key, tableSize);
	            printf("\nHash value using the Folding method: %d\n", hashVal1);
	            goto repeat;
	        //case for using the mid-square method
	        case 2:
	            hashVal2 = midSquareHash(key, tableSize);
	            printf("\nHash value using the Mid-square method: %d\n", hashVal2);
	            goto repeat;
	        default:
	            printf("\nInvalid choice!\n");
	            goto repeat;
	    }
	repeat:
	    //switch statement to continue or terminate the program
	    printf("\nPress:\n1. Continue calculation\n2. End program:\n");
	    scanf("%d", &m);
	    switch (m) {
	        case 1:
	            goto runCode;
	        case 2:
	            break;
	        default:
	            printf("\nInvalid choice!\n");
	            goto repeat;
	    }
    return 0;
}

