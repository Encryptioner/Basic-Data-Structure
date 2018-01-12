#include <iostream>
#include <cstdio>
#include <time.h>
#include <malloc.h>
using namespace std;

int findIndex(int *arr,int n,int c)
{
    int j,max,loc;
    max=*(arr+0);

    for(j=0;j<n;j++)
    {
        if(*(arr+j)>max)
        {
            loc=j;
            max=*(arr+j);
            c++;
        }
    }
    cout<<"MAX = "<<max<<endl;
    cout<<"Location of MAX = "<<loc<<endl;

    return c;
}


int main()
{
    clock_t start,end;
    double z;
    start=clock();

    int i, n,count=0,*arr;
	printf("\nHow many numbers will be entered?  ");
	scanf("%d", &n);
	printf("\n");

	arr = (int*)malloc(n * sizeof(int));

	for(i = 0; i < n; ++i)
	{
		scanf("%d", arr+i);
	}

	count=findIndex(arr,n,count);

	cout<<"\nNumber of loop to find max = "<<count<<endl<<endl;

	end=clock();
    z=((double)(start-end)/CLOCKS_PER_SEC);
    printf("Time=  %d\n",z);

	return 0;
}


