#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int N,i,x;
    cout<<"Enter Number of element in queue : ";
    cin>>N;

    vector<int>Q(N);
    vector<int>deleted_Q(N);
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
            Q[R]=x;
        }
    }
    cout<<"\nQueue is : \n";

    for(i=F;i<=R;i++)
    {
        cout<<Q[i]<<" ";
    }
    cout<<"\n\n";
    i=0;
    while(1)
    {
        if(F==0)
        {
            cout<<"\nAll the element deleted from queue..\n\n";
            break;
        }
        else
        {
            deleted_Q[++i]=Q[F];//start from i=1
            //deleted_Q[i++]=Q[F];// start from i=0

            if(F==R)
            {
                F=0;
                R=0;
            }
            else
            {
                if(F==N)
                {
                    F=1;
                }
                else
                {
                    F=F+1;
                }
            }

        }
    }

    cout<<"\nDeleted Queue is : \n";

    for(i=1;i<=N;i++)
    {
        cout<<deleted_Q[i]<<" ";
    }
    cout<<"\n\n";

    return 0;
}

