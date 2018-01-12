#include<iostream>

using namespace std;

double c[50];

int traverse_minheap( int q,int y)
{
    double tmp;
    int a;
    tmp=c[q];
    a=2*q;
    cout<<"\nmemory location = "<<c<<endl;
    while(a<=y)
    {
        if(a<y && c[a+1]<c[a])
        {
            a=a+1;
        }
        if(tmp<c[a])
        {
            break;
        }
        else if(tmp>=c[a])
        {
            c[a/2]=c[a];
            a=a*2;
        }
    }
    c[a/2]=tmp;
    return 0;
}

int insert_minheap(int x)
{
    int p;
    for(p=x/2;p>=1;p--)
    {
        traverse_minheap(p,x);
    }
    return 0;
}

int show(int m)
{
    int i;

    cout<<"\n\nMIN HEAP\n"<<endl;

    for(i=1;i<=m;i++)
    {
        cout<<i<<". "<<c[i]<<endl;
    }
    return (i-1);
}

int insert_in_heap(int x,int k,int z)
{
    static int i,n=0, s=0, t=0;
    //int ch,m=0;
    double heap[50],num;

    if(k==0)
    {
        t=x;
    }
    else
    {
        t=k;
    }

    //cout<<"\nt= "<<t<<endl;
    //cout<<1<<". "<<heap[1]<<endl;
    for(i=k+1;i<=t+z;i++)
    {
        cout<<"\nEnter element: ";
        cin>>num;
        c[i] = num;
        n = i;
        //cout<<"\nn= "<<n<<endl;
        //cout<<1<<". "<<heap[1]<<endl;
        insert_minheap(n);

        s=show(n);
    }
    return s;
}

int main()
{
    int x,ch,m=0,s=0;

    cout<<"Enter the total elements: ";
    cin>>x;

    s=insert_in_heap(x,0,0);

    while(1)
    {
    cout<<"\n Do You wanna insert more? Input... \n\n1 to continue..\n\n2 to exit...\n\nchoice = ";
    cin>>ch;

    switch(ch)
    {
    case 1:
        cout<<"\nHow many element u wanna add?  ";
        cin>>m;
        s=insert_in_heap(x,s,m);
        //cout<<"\ns= "<<s<<endl;
        break;
    case 2:
        ch=0;
        break;
    default:
        cout<<"\nInvalid Input...\n";
        break;
    }
    if(ch==0)
    {
        break;
    }
    }

    return 0;
}
