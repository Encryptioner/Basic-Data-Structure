#include <stdio.h>//all ok

int main()
{
    int LOC=1;
    int n,i,k,temp,j,swap=0,com=0;
    int a[20];
    printf("How many number : ");
    scanf("%d",&n);

    for(i=1;i<=n;i++)
    {
        //a[i]=rand();
        scanf("%d",&a[i]);
    }
    printf("\nNumber : \n");
    for(i=1;i<=n;i++)
    {
        printf("%d\n",a[i]);
    }

    for(k=1;k<=n-1;k++)
    {
        LOC=k;
        for(j=k+1;j<=n;j++)
        {
            if(a[LOC]>a[j])
            {
                LOC=j;
                com++;
            }
        }
        if(LOC!=k)
        {
            temp=a[k];
            a[k]=a[LOC];
            a[LOC]=temp;
            com++;
            swap++;
        }
    }

    printf("\nSorted in ascending order : \n");
    for(i=1;i<=n;i++)
    {
        printf("%d\n",a[i]);
    }
    printf("\nComparasion = %d  swap = %d \n",com,swap);
    return 0;
}

