#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int N,i,x;
    cout<<"Enter Number of element in queue : ";
    cin>>N;

    vector<int>Q(N);
    //int Q[1000];
    int F=0,R=0;
    //cout<<Q[1]<<" ";

    while(1)
    {
        cout<<"Enter an element : ";
        cin>>x;

        if((F==1 && R==N)|| F==R+1)
        {
            cout<<"\ncaution : Overflow for last element..\n\n";
            break;
        }
        else
        {
            if(F==0)
            {
                F=1;
                R=1;
            }
            else
            {
                if(R==N)
                {
                    R=1;
                }
                else
                {
                    R=R+1;
                }
            }
            //cout<<x<<" ";
            Q[R]=x;
        }
    }

    for(i=F;i<=R;i++)
    {
        cout<<Q[i]<<" ";
    }
    cout<<"\n\n";

    return 0;
}
