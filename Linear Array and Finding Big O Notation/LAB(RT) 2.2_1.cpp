#include<iostream>
using namespace std;

int main()
{
    int a[5]={4,5,6,7,8};
    int i,x;
    cout<<"Enter the value you want to delete:";
    cin>>x;
    for(i=0;i<5;i++)
    {
        if(a[i]==x)
        {
            i++;
        }
        cout<<a[i]<<endl;
    }
}
