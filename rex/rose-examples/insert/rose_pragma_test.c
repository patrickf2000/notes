#include <stdio.h>
#include "debug.h" 
#pragma 

int blowUp(int x)
{
  debug();
  return x * x;
}
#pragma 

int add(int x,int y)
{
  debug();
  return x + y;
}

int sub(int x,int y)
{
  return x - y;
}

void main()
{
  int x = blowUp(20);
  int sum = add(10,5);
  printf("X: %d\n",x);
  printf("Sum: %d\n",sum);
}
