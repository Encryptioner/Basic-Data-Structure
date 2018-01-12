#include<stdio.h>
#include<malloc.h>

struct node
{
    double data;
    struct node* nxt;
};

struct node *head, *newn;
int count=0;

struct node* get_data(double d)
{
    struct node* curn;
    head=NULL;
    newn=(struct node*)malloc(sizeof(struct node));
    head=newn;
    printf("\nEnter '0' to terminate. Otherwise continue... \n\n");
    while(1)
    {
        newn->data=d;
        curn=newn;
        newn=(struct node*)malloc(sizeof(struct node));
        curn->nxt=newn;
        scanf("%lf",&d);
        if(d==0)
        {
            curn->nxt=NULL;
            break;
        }
    }
    return 0;
};

int traverse_list()
{
    struct node *rhead=head;
    count=0;
    printf("\nNo. Current node        Current node data      Next node link\n");
    while(rhead)
    {
        count++;
        printf("%d.  %d              \t%0.2lf           \t%d\n",count,rhead,rhead->data,rhead->nxt);
        rhead=rhead->nxt;

    }
    printf("\nNumber of node=%d\n",count);
    return 0;
};

struct node* delete_node()
{

    struct node *curn,*tempn;
    int d,i;
    int target_data;
    curn=head;

    while(1)
    {
        //printf("\nEnter the value after which u wanna delete? Enter 0 if u wanna stop deleting process.. \n");
        //scanf("%d",&target_data);
        target_data=5;
        if(target_data==0)
        {
            break;
        }
        while(target_data!=curn->data)
        {
            curn=curn->nxt;
        }

        tempn=curn;
        //printf("\nEnter how many node u wanna delete? \n");
        //scanf("%d",&d);
        d=1;

        for(i=0;i<=d;i++)
        {
            tempn=tempn->nxt;
        }
        curn->nxt=tempn;
        traverse_list();

    }
    return 0;;
}


int main()
{
    struct node* root;
    double n;
    int count;
    //freopen("4. insertion.txt","r",stdin);
    printf("Enter a number : ");
    scanf("%lf",&n);
    get_data(n);
    traverse_list();
    delete_node();

    return 0;
}




