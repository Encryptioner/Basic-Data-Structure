#include <iostream>//insertion at last
#include <malloc.h>
#include <cstdio>
using namespace std;


struct node
{
    int data;
    struct node* nxt, *pre;
};

struct node *head, *newn;
int count=0;

int traverse_list();
struct node* get_data()
{
    int i,n,d;
    struct node *curn;
    head=NULL;
    cout<<"How many node u wanna add? ";
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cout<<"enter data of node "<<i<<" : ";
        cin>>d;
        newn=new(node);
        newn->data=d;
        newn->pre=NULL;
        newn->nxt=NULL;

        if(head==NULL)
        {
            head=newn;
            //newn->nxt=head;//for circular
            curn=newn;
        }
        else
        {
            curn->nxt=newn;
            newn->pre=curn;
            //newn->nxt=head;//for circular
            curn=newn;
        }
        traverse_list();
    }
};

int traverse_list()
{
    count=0;
    struct node *curn;
    curn=head;

    printf("\nNo. Current node  Current node data   Previous node link     Next node link\n");
    while(curn)
    {
        printf("%d.  %d      \t%d           \t%d         \t%d\n",++count,curn,curn->data,curn->pre,curn->nxt);
        curn=curn->nxt;

    }
    printf("\nNumber of node=%d\n",count);
    return 0;
}

struct node *middle_node(struct node *low,struct node *high)
{
    if(low==NULL)
    {
        return NULL;
    }
    struct node *slow,*fast;
    slow=low;
    fast=low->nxt;
    while(fast!=high)
    {
        fast=fast->nxt;
        if(fast!=high)
        {
            slow=slow->nxt;
            fast=fast->nxt;
        }
    }
    return slow;
};

struct node *binary_search()
{
    int num;
    struct node *low,*middle,*high;
    low=head;
    high=NULL;
    printf("Enter which number u wanna search : ");
    scanf("%d",&num);
    do
    {
        middle=middle_node(low,high);
        if(middle==NULL)
        {
            printf("Search element not present..\n");
            break;
        }
        if(middle->data==num)
        {
            printf("search result :  %d      \t%d           \t%d         \t%d\n",middle,middle->data,middle->pre,middle->nxt);
            break;
        }
        else if(middle->data<num)
        {
            low=middle->nxt;
        }
        else
        {
            high=middle;
        }
    }
    while(high == NULL || high->nxt!=low);
    binary_search();
    return 0;

};

int main()
{
    get_data();
    //traverse_list();
    binary_search();
    return 0;
}
