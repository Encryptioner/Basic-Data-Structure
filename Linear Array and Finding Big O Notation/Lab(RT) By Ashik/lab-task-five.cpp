#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int i,a[10],j,v,b;
    cout<<"enter the numbers:";
    cin>>b;
    for(i=0;i<b;i++)
    {
        cin>>a[i];
    }
    for(i=0;i<b;i++)
    {
        for(j=0;j<i;j++)
        {
            if(a[i]<a[j])
            {
                v=a[i];
                a[i]=a[j];
                a[j]=v;
            }
        }
    }
    for(i=0;i<b;i++)
    {
        cout<<a[i]<<endl;
    }
return 0;
}


