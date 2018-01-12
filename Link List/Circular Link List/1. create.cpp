#include <iostream>
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

int main()
{
    get_data();
    return 0;
}
