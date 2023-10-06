// Program for binary to gray code
#include<stdio.h>
#include<conio.h>
#include<math.h>
int binatogray(int);
void main ()
{
 int binary, gray;
 clrscr();
 printf("Enter a binary number: ");
 scanf("%d", &binary);
 gray = binatogray(binary);
 printf("The gray code of %d is %d\n", binary, gray);
 getch();
}
int binatogray(int binary)
{
 int a, b, result = 0, i = 0;
 while (binary != 0)
 {
 a = binary % 10;
 binary = binary / 10;
 b = binary % 10;
 if ((a && !b) || (!a && b))
{
 result = result + pow(10, i);
 }
 i++;
 }
 return result;
}