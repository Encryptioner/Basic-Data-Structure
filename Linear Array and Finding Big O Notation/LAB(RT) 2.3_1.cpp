
#include<iostream>
using namespace std;

int main()
{
    int a[5]={4,5,7,8};
    int i,x,v;
    cout<<"Enter the value you position you wanna insert:";
    cin>>x;
    cout<<"Enter the value you wanna insert:";
    cin>>v;
    for(i=0;i<5;i++)
    {
        cout<<a[i]<<endl;
    }
    for(i=4;i>=x;i--)
    {
        a[i]=a[i-1];
    }
    a[x-1]=v;
    for(i=0;i<5;i++)
    {

        cout<<a[i]<<endl;
    }

    cout<<sizeof(a);
}
