#include <stdio.h>
int fibonacci(int n)
{
    if(n==0)
    {
        return 0;
    }
    else if(n==1)
    {
        return 1;
    }
    else
    {
        printf("jhkhk\n");
        return(fibonacci(n-1)+fibonacci(n-2));

    }
}
int main()
{
    int x,f;
    printf("The n numbers of fibonacci series u want to know= ");
    scanf("%d",&x);
    /*for(f=1;f<=x;f++)
    {
        printf("%d\t",fibonacci(f));
    }*/
     printf("\n%d\t",fibonacci(x));
    return 0;
}
