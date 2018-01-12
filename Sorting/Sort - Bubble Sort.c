#include <stdio.h>///okk
#include <time.h>
#include <stdlib.h>
int main()
{
    int a[1000];
    int n,i,j,t;

    clock_t start,end;
    double z;
    start=clock();

    /*printf("How many number : ");
    scanf("%d",&n);
    printf("\nEnter number : ");


    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }*/
    n=100;
    for(i=0;i<n;i++){
            //printf("huhu\n");
            //a[i]=rand();
            scanf("%d",&a[i]);
    }

    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++)
    {

        if(a[i]<a[j])
        {
            //printf("bbddd\n");
            t=a[i];
            a[i]=a[j];
            a[j]=t;
        }
    }}

    end=clock();
    z=((double)(end-start)/CLOCKS_PER_SEC);
    printf("Time=%d\n",z);
    z=((double)(start-end)/CLOCKS_PER_SEC);
    printf("Time=%d\n",z);

    printf("\nSorted in ascending order...\n\n");
    for(i=0;i<n;i++)
    {
        //printf("ckuckl\n",a[i]);
        printf("%d\n",a[i]);
    }
    return 0;
}
