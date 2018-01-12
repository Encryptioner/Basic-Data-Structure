 #include<iostream>
using namespace std;
int main()
{
    int a[5]={4,5,6,7,8};
    int i,p=0,v;
    cout<<"Enter the value you want to delete:";
    cin>>v;
    for(i=0;i<5;i++)
    {
        if(a[i]==v)
        {
            p=i;
            break;
        }
    }
    for(i=p;i<4;i++)
    {
        a[i]=a[i+1];

    }
    for(i=0;i<4;i++)
    {
        cout<<a[i]<<endl;
    }
    return 0;
}
