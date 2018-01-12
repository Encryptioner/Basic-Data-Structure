#include <stdio.h>
#include <math.h>
#include <conio.h>
int factorial(int num)
{
    int f;
    if(num==1)
    {
        return 1;
    }
    else
    {
        f=num*factorial(num-1);
        return f;
    }
}

int main()
{
    int x;
    printf("Enter number= ");
    scanf("%d",&x);
    printf("Factorial of %d is %d ",x,factorial(x));
    return 0;
}

