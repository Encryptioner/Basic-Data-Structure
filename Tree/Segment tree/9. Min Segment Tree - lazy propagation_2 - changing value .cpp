#include <bits/stdc++.h>
using namespace std;

#define mx 100001
int arr[mx];
struct info
{
    int prop,sum;
}tree[mx*3];

void init(int node,int b,int e)
{
    cout<<node<<" "<<b<<" "<<e<<endl;
    if(b==e)
    {
        tree[node].sum=arr[b];
        cout<<node<<" "<<b<<" "<<e<<" "<<tree[node].sum<<" initialization"<<endl;
        return;
    }
    int Left=node*2;
    int Right=node*2+1;
    int mid=(b+e)/2;
    init(Left,b,mid);
    init(Right,mid+1,e);
    tree[node].sum=min(tree[Left].sum,tree[Right].sum);
    cout<<node<<" "<<b<<" "<<e<<" "<<tree[node].sum<<" initial"<<endl;
}

int query_1(int node,int b,int e,int i,int j,int carry)
{
    cout<<node<<" "<<b<<" "<<e<<" "<<carry<<endl;
    if(i==b && j==e)
    {
        cout<<node<<" "<<b<<" "<<e<<" "<<carry<<" "<<tree[node].sum<<" "<<carry*(e-b+1)<<" initial"<<endl;
        if(carry!=0)
        {
            return carry*(e-b+1);
        }
        else
        {
            return tree[node].sum+carry*(e-b+1);
        }
    }
    int Left=node<<1;
    int Right=(node<<1)+1;
    int mid=(b+e)>>1;

    if(j<=mid)
    {
        return query_1(Left, b, mid, i, j, carry+tree[node].prop);
    }
    else if(i > mid)
    {
        return query_1(Right, mid+1, e, i, j, carry+tree[node].prop);
    }
    else
    {
        return min(query_1(Left, b, mid, i, mid, carry+tree[node].prop) , query_1(Right, mid+1, e, mid+1, j, carry+tree[node].prop));
    }
}

void update_1(int node,int b,int e,int i,int j,int x)
{
    cout<<node<<" "<<b<<" "<<e<<" "<<x<<endl;
    if (i > e || j < b)
    {
        cout<<node<<" "<<b<<" "<<e<<" "<<x<<endl;
        return;
    }
    if (b >= i && e <= j)
    {
        cout<<tree[node].sum<<" "<<tree[node].prop<<endl;
        tree[node].sum=(x);
        tree[node].prop=x;
        cout<<tree[node].sum<<" "<<tree[node].prop<<endl;
        return;
    }
    int Left=node*2;
    int Right=(node*2)+1;
    int mid=(b+e)/2;
    update_1(Left,b,mid,i,j,x);
    update_1(Right,mid+1,e,i,j,x);
    cout<<tree[node].sum<<endl;
    tree[node].sum=min((tree[Left].sum+tree[node].prop),(tree[Right].sum+tree[node].prop));
    //tree[node].sum=tree[Left].sum+tree[Right].sum+(e-b+1)*tree[node].prop;
    cout<<tree[node].sum<<endl;
}

int main()
{
    int n,I,J,s,New,pos;
    cout<<"How many number : ";
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    init(1,1,n);
    cout<<endl;
    for(int i=0;i<=3*n;i++)
    {
        cout<<tree[i].sum<<" "<<i<<endl;
    }
    cout<<"From which index to which index u wanna get min? \n";
    cin>>I>>J;
    s=query_1(1,1,n,I,J,0);
    cout<<"\nmin = "<<s<<endl;

    cout<<"Enter changed value u wanna replace: ";
    cin>>New;
    cout<<"Enter It's position : ";
    cin>>I>>J;
    update_1(1,1,n,I,J,New);
    cout<<endl;
    for(int i=0;i<=3*n;i++)
    {
        cout<<tree[i].sum<<" "<<i<<endl;
    }
    while(1){
    cout<<"From which index to which index u wanna get min? \n";
    cin>>I>>J;
    s=query_1(1,1,n,I,J,0);
    cout<<"\nnew min = "<<s<<endl;}
    return 0;
}



