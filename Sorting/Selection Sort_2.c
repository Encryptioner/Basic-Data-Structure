#include <stdio.h>
int main()
{
    int a[15];
    int n,k,j,max=0,loc=0;
    printf("How many number : ");
    scanf("%d",&n);
    printf("\nEnter number : ");
    for(k=0;k<n;k++)
    {
        scanf("%d",&a[k]);
    }
    for(k=0;k<n;k++)
    {
        max=a[k];
        loc=k;
        for(j=k+1;j<n;j++)
        {
            if(a[j]>max)
            {
                max=a[j];
                loc=j;
            }
        }
        a[loc]=a[k];
        a[k]=max;
    }
    printf("\nSorted in descending order...\n\n");
    for(k=0;k<n;k++)
    {
        printf("%d\n",a[k]);
    }
    return 0;
}


