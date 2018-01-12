#include <stdio.h>//wrong
#include <stdlib.h>

void insertion(int x[],int n)
{
    int i,k,y;
    for(k=1;k<n;k++)
    {
        y=x[k];
        for(i=k-1;i>=0 && y>x[i];i--)
        {

            //if(y>x[i])
            {
                x[i+1]=x[i];
                x[i]=y;
            }
        }
    }
}

int main()
{
    int a[30];
    int n,i;
    printf("How many number : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        a[i]=rand();
    }
    printf("\nNumber : \n");
    for(i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }
    insertion(a,n);
    printf("\nSorted in descending order : \n");
    for(i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }
    return 0;
}

