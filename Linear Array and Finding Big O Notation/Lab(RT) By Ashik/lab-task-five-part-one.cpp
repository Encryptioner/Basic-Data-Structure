#include<iostream>
using namespace std;
int main()
{
    int a[5]={4,5,10,7,8};
    int i,b,t;
    cout<<"Enter the value to search:";
    cin>>b;
    for(i=0;i<5;i++)
    {
        if(a[i]==b)
        {
          t=i;
        }
    }
    if(t>=0&&t<=4)
    {
        cout<<"Match found"<<endl;
    }
    else
    {
        cout<<"Match not found"<<endl;
    }
    return 0;
}
