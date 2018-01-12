#include<iostream>

using namespace std;

int main()
{
    int i,j,n,a[50][3];
    cout<<"Enter Number of the element : ";
    cin>>n;
    cout<<"\n";
    for(i=1;i<=n;i++)
    {
            cout<<"Enter Element "<<i<<" : ";
            cin>>a[i][1];
            cout<<"Enter it's priority : ";
            cin>>a[i][2];
            a[i][3]=i;
            cout<<"\n";
    }
    cout<<"\nThe inserted queue is : \n\n";
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=3;j++)
        {

            cout<<a[i][j]<<" ";
        }
        cout<<"\n\n";
    }
    for(i=1;i<=n-1;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            if(a[i][2]>a[j][2])
            {
                cout<<a[i][1]<<" "<<a[i][2]<<" "<<a[i][3]<<endl;
                swap(a[i],a[j]);
                cout<<a[i][1]<<" "<<a[i][2]<<" "<<a[i][3]<<endl;
            }
        }
    }
    cout<<"\nThe sorted queue is : \n\n";
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=3;j++)
        {

            cout<<a[i][j]<<" ";
        }
        cout<<"\n\n";
    }

    return 0;
}
