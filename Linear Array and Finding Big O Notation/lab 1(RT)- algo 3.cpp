#include <iostream>
#include <cstdio>
#include <time.h>
#include <malloc.h>
using namespace std;

int findIndex(int *arr,int n,int target)
{
    int j,i=-1;
    for(j=0;j<n;j++)
    {
        if(*(arr+j)==target)
        {
            i=j;
            return i;
        }
    }
    if(i==-1)
    {
        //printf("No value of array matches with target..\n");
        return -1;
    }

}


int main()
{
    clock_t start,end;
    double z;
    start=clock();

    int i, n,target, *arr,index;
	printf("\nHow many numbers will be entered?");
	scanf("%d", &n);
	printf("\n");

	arr = (int*)malloc(n * sizeof(int));

	for(i = 0; i < n; ++i)
	{
		scanf("%d", arr+i);
	}

    printf("Enter the target : ");
    scanf("%d",&target);
    printf("\n");


	index=findIndex(arr,n,target);

	printf("returned %d\n",index);

	end=clock();
    z=((double)(end-start)/CLOCKS_PER_SEC);
    printf("Time=  %d",z);

	return 0;
}

