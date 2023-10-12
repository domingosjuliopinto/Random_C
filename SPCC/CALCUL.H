#include <math.h>

float add(int a, int b)
{
 return(a+b);
}

float sub(int a, int b)
{
 return(a-b);
}

float mul(int a, int b)
{
 return(a*b);
}

float div(int a, int b)
{
 return(a/b);
}

float sq(int a)
{
 return(a*a);
}

void square_root(float a)
{
 printf("The square root of %.2f is %.2f \n",a,sqrt(a));
}

void cube_root(float a)
{
  printf("The cube root of %.2f is %.2f \n",a,pow(a,1.0/3.0));
}