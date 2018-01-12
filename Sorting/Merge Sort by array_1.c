#include<stdio.h>//okk
#include<conio.h>
#include<stdlib.h>

int A[50],n;

void merge(int low,int mid,int high);
void mergesort(int low,int high);

void main()
{

    int i,low=0,high;

    printf("Enter the number of elements: ");
    scanf("%d",&n);
    printf("\nEnter the element: \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }

    high=n-1;
    mergesort(low,high);//sending index 0 and n-1

    printf("\nThe sorted array:\n");
    for(i=0;i<n;i++)
        printf("Array[%d]=%d\n",i,A[i]);
}

void mergesort(int low,int high)
{
    //printf("\nInside Merge Sort\n");
    int mid;
    if(low<high)
    {
        mid=floor((low+high)/2);// takes smallest int number like 1.54454=1
        //printf("low = %d\n",low);
        //printf("mid = %d\n",mid);
        mergesort(low,mid);
        //printf("m2 mid+1 = %d\n",mid+1);
        //printf("m2 high = %d\n",high);
        mergesort(mid+1,high);
        /*printf("m3 low = %d\n",low);
        printf("m3 mid = %d\n",mid);
        printf("m3 high = %d\n",high);*/
        merge(low,mid,high);
    }
}

void merge(int low,int mid,int high)
{
    int h=low,i=low,j=mid+1,k,B[50];

    /*printf("high = %d\n",high);
    printf("mid = %d\n",mid);
    printf("h = i = low = %d\n",low);
    printf("j = mid+1 = %d\n",j);*/

    while(h<=mid && j<=high)
    {
        if(A[h]<A[j])//ascending factor
        {
            B[i]=A[h];
            h++;
        }
        else
        {
            B[i]=A[j];
            j++;
        }
        i=i+1;
        /*printf("\ni = %d\n",i);
        printf("j = %d\n",j);
        i=i+1;
        printf("\ni = %d\n",i);
        printf("high = %d\n",high);
        printf("mid = %d\n",mid);
        printf("h = %d\n",h);*/

    }
    if(h>mid)
    {
        for(k=j;k<=high;k++)
        {
            B[i]=A[k];
            i++;
        }
    }
    else{
            for(k=h;k<=mid;k++)
            {
                B[i]=A[k];
                i++;
            }

    }
    for(k=low;k<=high;k++)
        A[k]=B[k];
}

