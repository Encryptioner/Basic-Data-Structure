#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int a[100];
    int n,x,i,j,k,count=0;

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

    cout<<"\nWhich value u wanna insert after every 8 ? ";
    cin>>x;

    for(i=0;i<n;i++)
    {
        if(a[i]==8)
        {
            count++;

            for(k=n-1;k>=(i+1);k--)
            {
                a[k+1]=a[k];
            }
            //a[i+1]=x;//right
            //a[k]=x;//wrong
            a[k+1]=x;//right
            //cout<<k+1<<" "<<x<<" "<<a[k+1]<<endl;
            n++;
        }
    }
    if(count>0)
    {
        cout<<"\nNew array is : \n"<<endl;0
        cout<<"Number of inserted element = "<<count<<endl<<endl;
        //cout<<"Number of element = "<<n<<endl<<endl;
        for(i=0;i<n;i++)
        {
            cout<<a[i]<<" ";
        }
    }
    else
    {
        cout<<"Nothing to insert\n";
    }
    return 0;
}

