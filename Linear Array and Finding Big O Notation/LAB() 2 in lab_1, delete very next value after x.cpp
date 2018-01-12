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
        a[i]=rand()%5;
    }*/
    for(i=0;i<n;i++)
    {
        //cout<<a[i]<<" ";
        cin>>a[i];
    }

    cout<<"\nAfter which value u wanna delete ? ";
    cin>>x;

    for(i=0;i<n;i++)
    {
        if(a[i]==x && (i+1)<n)
        {
            count++;
            j=i+1;
            for(k=j;k<(n-1);k++)
            {
                a[k]=a[k+1];
            }
            n--;
            //i--;//if x's 2nd next is x and we wnt to delete it
        }
    }
    if(count>0)
    {
        cout<<"\nNew array is : \n"<<endl;
        cout<<"Number of deleted element = "<<count<<endl<<endl;
        cout<<"Number of element = "<<n<<endl<<endl;
        for(i=0;i<n;i++)
        {
            cout<<a[i]<<" ";
        }
    }
    else
    {
        cout<<"Nothing to delete\n";
    }
    return 0;
}
