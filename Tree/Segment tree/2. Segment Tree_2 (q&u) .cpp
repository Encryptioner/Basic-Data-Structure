#include <bits/stdc++.h>
using namespace std;

#define mx 100001
int arr[mx];
int tree[mx*3];

void init(int node,int b,int e)
{
    cout<<node<<" "<<b<<" "<<e<<endl;
    if(b==e)
    {
        tree[node]=arr[b];
        cout<<node<<" "<<b<<" "<<e<<" "<<tree[node]<<" initialization"<<endl;
        return;
    }
    int Left=node*2;
    int Right=node*2+1;
    int mid=(b+e)/2;
    init(Left,b,mid);
    init(Right,mid+1,e);
    tree[node]=tree[Left]+tree[Right];
    cout<<node<<" "<<b<<" "<<e<<" "<<tree[node]<<" initial"<<endl;
}

int query(int node,int b,int e,int i,int j)
{
    cout<<node<<" "<<b<<" "<<e<<endl;
    if (i > e || j < b)
    {
        cout<<node<<" "<<b<<" "<<e<<" "<<0<<endl;
        return 0; //বাইরে চলে গিয়েছে
    }
    if (b >= i && e <= j)
    {
        cout<<node<<" "<<b<<" "<<e<<" "<<tree[node]<<" initial"<<endl;
        return tree[node]; //রিলেভেন্ট সেগমেন্ট
    }
    int Left=node*2; //আরো ভাঙতে হবে
    int Right=node*2+1;
    int mid=(b+e)/2;
    int p1=query(Left,b,mid,i,j);
    int p2=query(Right,mid+1,e,i,j);
    cout<<p1<<" "<<p2<<endl;
    return p1+p2; //বাম এবং ডান পাশের যোগফল
}

void update(int node,int b,int e,int i,int newvalue)
{
    if (i > e || i < b)
    {
        return; //বাইরে চলে গিয়েছে
    }
    if (b >= i && e <= i)//রিলেভেন্ট সেগমেন্ট
    {
        tree[node]=newvalue; //নতুন মান বসিয়ে দিলাম
        return;
    }
    int Left=node*2; //আরো ভাঙতে হবে
    int Right=node*2+1;
    int mid=(b+e)/2;
    update(Left,b,mid,i,newvalue);
    update(Right,mid+1,e,i,newvalue);
    tree[node]=tree[Left]+tree[Right];
}

int main()
{
    int n,I,J,sum,New,pos;
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
        cout<<tree[i]<<" "<<i<<endl;
    }
    cout<<"From which index to which index u wanna get sum? \n";
    cin>>I>>J;
    sum=query(1,1,n,I,J);
    cout<<"\nSUM = "<<sum<<endl;
    /*cout<<"Enter new value u wanna insert: ";
    cin>>New;
    cout<<"Enter It's position : ";
    cin>>pos;
    //update(1,I,J,pos,New);//It doesn't update any index value out of I to J range
    update(1,1,n,pos,New);*/

    cout<<"From which index to which index u wanna get sum? \n";
    cin>>I>>J;
    sum=query(1,1,n,I,J);
    cout<<"\nnew SUM = "<<sum<<endl;
    return 0;
}
