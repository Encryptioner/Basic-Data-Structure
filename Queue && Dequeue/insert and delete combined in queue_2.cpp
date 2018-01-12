#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int N,i,x;
    cout<<"Enter Number of element in queue : ";
    cin>>N;

    vector<int>Q(N);
    //vector<int>deleted_Q(N);
    int F=0,R=0,k=0;

    int choice;

    while(1)
    {
        cout<<"\nEnter your choice. Insert = 1, Delete = 2, Display = 3, Exit = 0  :  ";
        cin>>choice;

        if(choice==0)
        {
            break;
        }

        switch(choice)
        {
        case 1:

            cout<<"\nEnter an element : ";
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
            break;
        case 2:

            if(F==0)
            {
                cout<<"\nAll the element deleted from queue..\n\n";
                break;
            }
            else
            {
                //deleted_Q[++k]=Q[F];
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
            break;
        case 3:

            cout<<"\nQueue is : \n";
            if(F==0)
            {
                cout<<"\nThere is no element in queue\n";
                break;
            }

            for(i=F;i<=R;i++)
            {
                cout<<Q[i]<<" ";
            }
            cout<<"\n\n";
            break;
        default:
            cout<<"\nWrong choice..\n\n";
            break;

        }

    }

    return 0;
}



