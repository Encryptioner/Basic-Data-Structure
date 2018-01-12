#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a[30];
    int n,k,j,min=0,loc=0;
    printf("How many number : ");
    scanf("%d",&n);
    /*printf("\nEnter number : ");
    for(k=0;k<n;k++)
    {
        scanf("%d",&a[k]);
    }*/
    for(k=0;k<n;k++)
    {
        //a[k]=rand();
        scanf("%d",&a[k]);
    }
    printf("\nNumber : ");
    for(k=0;k<n;k++)
    {
        printf("%d ",a[k]);
    }
    for(k=0;k<n;k++)
    {
        min=a[k];
        loc=k;
        for(j=k+1;j<n;j++)
        {
            if(a[j]<min)
            {
                min=a[j];
                loc=j;
            }
        }
        a[loc]=a[k];
        a[k]=min;
    }
    printf("\nSorted in ascending order...\n\n");
    for(k=0;k<n;k++)
    {
        printf("%d\n",a[k]);
    }
    return 0;
}

