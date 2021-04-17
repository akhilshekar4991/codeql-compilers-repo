#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
	printf("hello world \n");
	int *num = (int *)malloc(sizeof(unsigned char));
	printf("Value pointed by num = %d \n", *num);
	return 1; 
}
