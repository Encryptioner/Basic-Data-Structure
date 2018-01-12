#include<bits/stdc++.h>//ok

using namespace std;

#define MX 100001
vector<int>arr(MX),tree(4*MX);

void insert_update(int node, int b, int e, int pos, int value)
{
    if(b == pos && pos == e)
    {
        tree[node] = value;
        return;
    }

    int l = node*2;
    int r = l + 1;
    int mid = (b+e)/2;

    if(pos <= mid)
    {
        insert_update(l, b, mid, pos, value);
    }
    else
    {
        insert_update(r, mid+1, e, pos, value);
    }

    tree[node] = max(tree[l] , tree[r]);
}


int query(int node, int b, int e, int i, int j)
{
    if(i==b && j==e)
    {
        return tree[node];
    }

    int l = node<<1;
    int r = l + 1;
    int mid = (b+e)>>1;


    if(j<=mid)
    {
        return query(l, b, mid, i, j);
    }
    else if(i > mid)
    {
        return query(r, mid+1, e, i, j);
    }
    else
    {
        return max(query(l, b, mid, i, mid) , query(r, mid+1, e, mid+1, j));
    }
}

int main()
{
    int t,N,q,i,x,y,c=0,minimum;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d %d",&N,&q);

        for(i=1;i<=N;i++)
        {
            scanf("%d",&arr[i]);
            insert_update(1, 1, N, i, arr[i]);
        }
        for(i=1;i<=4*N;i++)
        {
            cout<<i<<" "<<tree[i]<<endl;
        }
        printf("Case %d:\n",++c);
        while(q--)
        {
            scanf("%d %d",&x,&y);
            minimum=query(1,1,N,x,y);
            printf("%d\n",minimum);
        }
        arr.clear();
        tree.clear();
    }
    return 0;
}

