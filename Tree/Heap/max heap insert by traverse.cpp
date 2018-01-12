#include<bits/stdc++.h>
#define MAX 500
using namespace std;
int c1=0,c2=0,count1[MAX],count2[MAX];
void traverse_maxheap(int c[],int q,int y,int data[])
{
    int tmp,tmp1,a;

    tmp = c[q];
    tmp1= data[q];
    //cout<<"\ntmp= "<<tmp<<endl;
    a = 2*q;
    while(a<= y)
    {
        if(a < y && c[a+1] > c[a])
            a= a+1;
        if(tmp > c[a])
            break;
        else if(tmp <= c[a])
        {
            c[a/2] = c[a];
            c1++;
            data[a/2]=data[a];
            a = a*2;
        }
    }
    c[a/2] = tmp;
    data[a/2]=tmp1;
    return;
}

void insert_maxheap(int b[],int x,int data[])
{
    int p;
    for(p=x/2;p>=1;p--)
    {
        traverse_maxheap(b,p,x,data);
    }
}
void show(int a[],int m,int data[])
{
    int i;
    count1[m]=c1;
    c1=0;
    cout<<"\n\nIn Binary Heap :\n";
    for(i=1;i<=m;i++)
    {
        cout<<i<<". "<<a[i]<<"  "<<data[i]<<"  "<<count1[i]<<endl;
    }
}
int bubble_sort(int array[],int L,int data1[])
{
    int i,j,temp;
    for(i=1;i<L;i++)
    {
        for(j=L-1;j>=i;j--)
        {
            if(array[j-1]<array[j])
            {
                c2++;
                temp=array[j-1];
                array[j-1]=array[j];
                array[j]=temp;
                swap(data1[j-1],data1[j]);
            }

        }
    }
    count2[L]=c2;
    c2=0;
    cout<<"\nIn Sorted Array :\n";
    for(i=0;i<L;i++)
    {
        cout<<i+1<<". "<<array[i]<<"  "<<data1[i]<<"  "<<count1[i+1]<<endl;
    }
}
int main()
{
    ifstream in;
    ofstream out;
    int data[MAX],data1[MAX],a[MAX],array[MAX],i,j,k,num,n = 0,x;
    cout<<"Enter the total elements: ";
    cin>>x;
    for(i=1;i<=x;i++)
    {
        fprintf("%d",rand());
    }
    for(i=1;i<=x;i++)
    {
        data[i]=rand();
        a[i]=i;

        data1[i-1]=data[i];
        array[i-1]=i;

        n=i;
        cout<<"\ndata ["<<i<<"] = "<<data[i]<<endl<<endl;

        bubble_sort(array,n,data1);

        insert_maxheap(a,n,data);
        show(a,n,data);
    }
    return 0;
}

