#include<iostream>

using namespace std;

void traverse_minheap(int c[],int q,int y)
{
    int tmp,a;

    tmp = c[q];
    //cout<<"\ntmp= "<<tmp<<endl;
    a = 2*q;
    while(a<= y)
    {
        if(a < y && c[a+1] < c[a])
            a= a+1;
        if(tmp < c[a])
            break;
        else if(tmp >= c[a])
        {
            c[a/2] = c[a];
            a = a*2;
        }
    }
    c[a/2] = tmp;
    return;
}

void insert_minheap(int b[],int x)
{
    int p;
    for(p=x/2;p>=1;p--)
    {
        traverse_minheap(b,p,x);
    }
}
void show(int a[],int m)
{
    int i;
    cout<<endl;
    for(i=1;i<=m;i++)
    {
        cout<<i<<". "<<a[i]<<endl;
    }
}

int main()
{
    int heap[20],i,num,n = 0,x;
    cout<<"Enter the total elements: ";
    cin>>x;
    for(i=1;i<=x;i++)
    {
        cout<<"\nEnter element: ";
        cin>>num;
        heap[i] = num;
        n = i;
        insert_minheap(heap,n);
        show(heap,n);
    }
    return 0;
}

