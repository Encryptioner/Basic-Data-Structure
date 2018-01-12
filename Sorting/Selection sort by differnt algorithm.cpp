#include <iostream>
#include <cstdio>
using namespace std;

int minimum(int a[],int k,int n,int LOC)
{
    int j;
    int min=a[k];
    LOC=k;
    for(j=k+1;j<=n;j++)
    {
        if(min>a[j])
        {
            min=a[j];
            LOC=j;
        }
    }
    return 0;
}

int main()
{
    int LOC=1;
    int n,i,k;
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
        minimum(a,k,n,LOC);
        swap(a[k],a[LOC]);
    }

    printf("\nSorted in ascending order : \n");
    for(i=1;i<=n;i++)
    {
        printf("%d\n",a[i]);
    }
    return 0;
}
