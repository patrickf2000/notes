#include <stdio.h>

#pragma test
int blowUp(int x) 
{
	return x*x;
}

#pragma test
int add(int x, int y)
{
	return x + y;
}

int sub(int x, int y)
{
	return x - y;
}

void main()
{
	int x = blowUp(20);
	int sum = add(10, 5);
	
	printf("X: %d\n", x);
	printf("Sum: %d\n", sum);
}
