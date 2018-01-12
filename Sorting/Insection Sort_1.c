#include <stdio.h>//okkk
#include <stdlib.h>

void insertion(int x[],int n)
{
    int i,k,y;
    int com=0,shift=0;
    for(k=1;k<n;k++)
    {
        y=x[k];
        //i=k-1;
        //for(i=k-1;i>=0 && y<x[i];i--)
        for(i=k-1;i>=0;i--)
        {
            //while(x[i]>y)
            if(x[i]>y)
            {
                x[i+1]=x[i];
                com++;
                shift++;
                //i++;
            }
            //x[i+1]=x[i];
            //x[i]=y;
            else
            {
                break;
            }
        }
        i++;
        x[i]=y;
        shift++;
        /*i=k-1;
        //if(i>=0 && x[i]>y)
        if(i>=0)
        {
            if(x[i]>y){
            x[i+1]=x[i];}
        }*/

        //x[i+1]=y;
    }
    printf("\nCompartion = %d  shifting = %d\n",com,shift);
}

int main()
{
    int a[30];
    int n,i;
    printf("How many number : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        //a[i]=rand();
        scanf("%d",&a[i]);
    }
    printf("\nNumber : \n");
    for(i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }
    insertion(a,n);
    printf("\nSorted in ascending order : \n");
    for(i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }
    return 0;
}
