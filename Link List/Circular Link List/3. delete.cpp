#include <iostream>//insertion at last
#include <malloc.h>
#include <cstdio>
using namespace std;


struct node
{
    int data;
    struct node* nxt;
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
        //newn=(struct node*)malloc(sizeof(struct node));
        newn->data=d;
        newn->nxt=NULL;

        if(head==NULL)
        {
            head=newn;
            newn->nxt=head;//for circular
            curn=newn;
        }
        else
        {
            curn->nxt=newn;
            newn->nxt=head;//for circular
            curn=newn;
        }
        traverse_list();
    }
};

int traverse_list()
{
    struct node *curn=head;
    count=0;
    printf("\nNo. Current node        Current node data      Next node link\n");
    do
    {
        count++;
        printf("%d.  %d              \t%d           \t%d\n",count,curn,curn->data,curn->nxt);
        curn=curn->nxt;
    }
    while(curn->nxt!=head->nxt);

    printf("\nNumber of node=%d\n",count);
    return 0;
};

struct node *insertion_at_last()
{
    int i,n,d;
    struct node *curn;
    curn=head;
    cout<<"How many node u wanna add? ";
    cin>>n;
    while(curn->nxt!=head)
    {
        curn=curn->nxt;
    }
    for(i=1;i<=n;i++)
    {
        cout<<"enter data of node "<<i<<" : ";
        cin>>d;
        newn=new(node);
        //newn=(struct node*)malloc(sizeof(struct node));
        newn->data=d;
        newn->nxt=curn->nxt;
        curn->nxt=newn;
        curn=curn->nxt;

        traverse_list();
    }
    return 0;
};

struct node *deleteing()
{
    int i,n,x;
    struct node *curn;
    curn=head;
    cout<<"Enter how many node u wanna delete from last? ";
    cin>>n;
    //for(i=1;i<=n;i++)
    {
        x=1;
        while(x!=count-n)
        {
            curn=curn->nxt;
            x++;
        }
        curn->nxt=head;
        traverse_list();
    }
};

int main()
{
    get_data();
    //insertion_at_last();
    deleteing();

    return 0;
}

