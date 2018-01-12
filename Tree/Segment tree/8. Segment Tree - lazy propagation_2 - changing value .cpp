#include <bits/stdc++.h>
using namespace std;

#define mx 100001
int arr[mx];
struct info
{
    int prop,sum;
}tree[mx*3]; //sum ছাড়াও নিচে অতিরিক্ত কত যোগ হচ্ছে সেটা রাখবো prop এ

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
    tree[node].sum=tree[Left].sum+tree[Right].sum;
    cout<<node<<" "<<b<<" "<<e<<" "<<tree[node].sum<<" initial"<<endl;
}

int query_1(int node,int b,int e,int i,int j,int carry)
{
    cout<<node<<" "<<b<<" "<<e<<" "<<carry<<endl;
    if (i > e || j < b)
    {
        cout<<node<<" "<<b<<" "<<e<<" "<<carry<<" "<<0<<endl;
        return 0;
    }

    if(b>=i and e<=j)
    {
        cout<<node<<" "<<b<<" "<<e<<" "<<carry<<" "<<tree[node].sum<<" "<<carry*(e-b+1)<<" initial"<<endl;
        if(carry!=0)//for changed value
        {
            return carry*(e-b+1);
        }
        else
        {
            return tree[node].sum+carry*(e-b+1); //when carry is zero return previous sum//সাম এর সাথে যোগ হবে সেই রেঞ্জের সাথে অতিরিক্ত যত যোগ করতে বলেছে সেটা
        }
    }

    int Left=node<<1;
    int Right=Left+1;
    int mid=(b+e)>>1;

    int p1 = query_1(Left, b,mid, i, j, carry+tree[node].prop); //প্রপাগেট ভ্যালু বয়ে নিয়ে যাচ্ছে carry ভ্যারিয়েবল
    int p2 = query_1(Right, mid+1, e, i, j,carry+tree[node].prop);
    cout<<p1<<" "<<p2<<endl;
    return p1+p2;
}

void update_1(int node,int b,int e,int i,int j,int x)
{
    cout<<node<<" "<<b<<" "<<e<<" "<<x<<endl;
    if (i > e || j < b)
    {
        cout<<node<<" "<<b<<" "<<e<<" "<<x<<endl;
        return;
    }
    if (b >= i && e <= j) //নোডের রেঞ্জ আপডেটের রেঞ্জের ভিতরে
    {
        cout<<tree[node].sum<<" "<<tree[node].prop<<endl;
        tree[node].sum=((e-b+1)*x); //নিচে নোড আছে e-b+1 টি, তাই e-b+1*x হবে এই রেঞ্জে
        tree[node].prop+=x; //নিচের নোডগুলোর সাথে x যোগ হবে
        cout<<tree[node].sum<<" "<<tree[node].prop<<endl;
        return;
    }
    int Left=node*2;
    int Right=(node*2)+1;
    int mid=(b+e)/2;
    update_1(Left,b,mid,i,j,x);
    update_1(Right,mid+1,e,i,j,x);
    cout<<tree[node].sum<<endl;
    tree[node].sum=tree[Left].sum+tree[Right].sum+(e-b+1)*tree[node].prop;//update korar ager sum+ j position gulor value change kora hoyese
    cout<<tree[node].sum<<endl;
    //উপরে উঠার সময় পথের নোডগুলো আপডেট হবে
    //বাম আর ডান পাশের সাম ছাড়াও যোগ হবে নিচে অতিরিক্ত যোগ হওয়া মান
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
    cout<<"From which index to which index u wanna get sum? \n";
    cin>>I>>J;
    s=query_1(1,1,n,I,J,0);
    cout<<"\nSUM = "<<s<<endl;

    cout<<"Enter new value u wanna add: ";
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
    cout<<"From which index to which index u wanna get sum? \n";
    cin>>I>>J;
    s=query_1(1,1,n,I,J,0);
    cout<<"\nnew SUM = "<<s<<endl;}
    return 0;
}


