#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int a[100];
    int n,x,i,j,k,p,count=0;

    cout<<"Number of the element in the array = ";
    cin>>n;

    /*for(i=0;i<n;i++)
    {
        a[i]=rand()%10;
    }*/
    for(i=0;i<n;i++)
    {
        //cout<<a[i]<<" ";
        cin>>a[i];
    }

    cout<<"\nAfter which value u wanna insert ? ";
    cin>>p;

    for(i=0;i<n;i++)
    {
        if(a[i]==p)
        {
            count++;
,
            for(k=n-1;k>=(i+1);k--)
            {
                a[k+1]=a[k];
            }
            cout<<"\nEnter the number which u wanna insert after "<<p<<" of "<<(i+1)<<" position ? "<<endl;
            cin>>x;

            a[k+1]=x;//right
            n++;
        }
    }
    if(count>0)
    {
        cout<<"\nNew array is : \n"<<endl;
        cout<<"Number of inserted element = "<<count<<endl<<endl;

        for(i=0;i<n;i++)
        {
            cout<<a[i]<<" ";
        }
    }
    else
    {
        cout<<"Nothing to insert\n\n";
    }
    return 0;
}


