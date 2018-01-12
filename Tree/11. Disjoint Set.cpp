#include<bits/stdc++.h>
#define MAX 100
using namespace std;

int Find(int r,int par[])
{
    if(par[r]==r)
    {
        return r;
    }
    else
    {
        par[r]=Find(par[r],par);
        return Find(par[r],par);
    }
}


int Union(int a, int b,int par[])
{
    int u=Find(a,par);
    int v=Find(b,par);

    if(u==v)
    {
        cout<<"They are already friends.\n";
    }
    else
    {
        par[u]=v;
    }
    return 0;
}

int main()
{
    int i,j,n,x,par[MAX],a,b;
    cout<<"Enter Number of Element : ";
    cin>>n;

    for(i=1;i<=n;i++)
    {
        par[i]=i;
    }
    cout<<"\nHow many new friends? ";
    cin>>x;
	for(i=1;i<=x;i++)
    {
        cout<<"Enter friend - friend  : ";
        cin>>a>>b;
        Union(a,b,par);
    }
    cout<<"\nHow many Question? ";
    cin>>x;
    while(x--)
    {
        cout<<"\nEnter friend - friend  : ";
        cin>>a>>b;
        if(Find(par[a],par)==Find(par[b],par))
        {
            cout<<"They are friends.\n";
        }
        else
        {
            cout<<"They are not friends.\n";
        }
    }
    return 0;
}
