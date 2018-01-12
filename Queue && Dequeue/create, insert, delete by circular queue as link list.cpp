#include <iostream>//insertion at last
#include <malloc.h>
#include <cstdio>
using namespace std;


struct node
{
    int data;
    struct node* nxt;
};

struct node *head, *newn, *curn;
int count=0,z=0;
int item[100];

int traverse_list();
struct node* get_data()
{
    int i,n,d;
    //struct node *curn;
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
    struct node *curn;
    curn=head;
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
    //struct node *curn;
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
    int i,choice,count=0;
    struct node *F,*R;
    F=head;
    R=curn;

    if(F==NULL)
    {
        printf ( "queue is empty" ) ;
    }
    else
    {
        if(F==R)
        {
            item[z++]==F->data;
            head=NULL;
            cout<<"Last element deleted.."<<endl;
            //F=NUll;
            //R=NULL;
            //delete(F);
        }
        else
        {
            item[z++]==F->data;
            F=F->nxt;
            R->nxt=F;
            head=F;
            cout<<"Deleting from Top"<<endl;
        }
    }
    cout<<"Wanna Delete more?  1 = Yes ...  any num = No\n";
    cin>>choice;
    if(choice==1)
    {
        deleteing();
    }
    else
    {
        cout<<"\nDeleted Item : "<<endl;
        for(i=0;i<choice;i++)
        {
            cout<<item[i]<<" ";
        }
        cout<<"\n\n";
    }

    traverse_list();
    return 0;
};

int main()
{
    get_data();
    //insertion_at_last();
    deleteing();

    return 0;
}


