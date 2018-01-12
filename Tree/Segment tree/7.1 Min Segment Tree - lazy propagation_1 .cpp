#include <bits/stdc++.h>//ok for min but not for sum
#define lld long long int
using namespace std;

#define mx 100001
lld arr[mx];
struct info
{
    int prop,sum;
}tree[mx*3];

void init(lld node,lld b,lld e)
{
    if(b==e)
    {
        tree[node].sum=arr[b];
        return;
    }
    lld Left=node<<1;
    lld Right=Left+1;
    lld mid=(b+e)>>1;

    init(Left,b,mid);
    init(Right,mid+1,e);
    //tree[node].sum=min(tree[Left].sum,tree[Right].sum);//or max
    tree[node].sum=tree[Left].sum+tree[Right].sum;//to find sum
}

lld query(lld node,lld b,lld e,lld i,lld j,lld carry)
{
    if(i==b && j==e)
    {
        return tree[node].sum+carry*(e-b+1);
    }
    lld Left=node<<1;
    lld Right=Left+1;
    lld mid=(b+e)>>1;
    if(j<=mid)
    {
        return query(Left, b, mid, i, j, carry+tree[node].prop);
    }
    else if(i > mid)
    {
        return query(Right, mid+1, e, i, j, carry+tree[node].prop);
    }
    else
    {
        return min(query(Left, b, mid, i, mid, carry+tree[node].prop) , query(Right, mid+1, e, mid+1, j, carry+tree[node].prop));//or max
    }
}
lld query_1(lld node,lld b,lld e,lld i,lld j,lld carry)//for sum
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
            return tree[node].sum+carry*(e-b+1); //when carry is zero return previous sum, else add extra value to previous
        }
    }
    lld Left=node<<1;
    lld Right=Left+1;
    lld mid=(b+e)>>1;

    lld p1 = query_1(Left, b,mid, i, j, carry+tree[node].prop);
    lld p2 = query_1(Right, mid+1, e, i, j,carry+tree[node].prop);
    cout<<p1<<" "<<p2<<endl;
    return p1+p2;
}
void update(lld node,lld b,lld e,lld i,lld j,lld x)
{
    if (i > e || j < b)
    {
        return;
    }
    if (b >= i && e <= j)
    {
        //tree[node].sum+=(x);
        tree[node].prop+=x;
        tree[node].sum=((e-b+1)*x);//for sum there are ((e-b+1)) node below parent
        return;
    }
    lld Left=node<<1;
    lld Right=Left+1;
    lld mid=(b+e)>>1;
    update(Left,b,mid,i,j,x);
    update(Right,mid+1,e,i,j,x);
    //tree[node].sum=min((tree[Left].sum+tree[node].prop),(tree[Right].sum+tree[node].prop));//or max
    tree[node].sum=tree[Left].sum+tree[Right].sum+(e-b+1)*tree[node].prop;//update korar ager sum+ j position gulor value change kora hoyese
}

int main()
{
    lld t,N,q,i,j,x,y,v,task,c=0,minimum,val;

    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld",&N,&q);

        for(i=1;i<=N;i++)
        {
            scanf("%lld",&arr[i]);
        }
        init(1,1,N);
        printf("Case %lld:\n",++c);
        while(q--)
        {
            scanf("%lld",&task);
            if(task==1)
            {
                scanf("%lld %lld %lld",&i,&j,&v);//in i to j position add value
                update(1,1,N,i,j,v);
            }
            else if(task==2)//find minimum or maximum
            {
                scanf("%lld %lld",&i,&j);
                val=query(1,1,N,i,j,0);
                printf("Minimum =  %lld\n",val);
            }
            else if(task==3)//to find sum
            {
                scanf("%lld %lld",&i,&j);
                val=query_1(1,1,N,i,j,0);
                printf("Sum =  %lld\n",val);
            }
        }
        memset(arr,0,sizeof arr);
        memset(&tree,0,sizeof tree);
    }
    return 0;
}
