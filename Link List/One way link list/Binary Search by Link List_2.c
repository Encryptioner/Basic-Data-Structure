#include<stdio.h>//ok
#include<malloc.h>

struct node
{
    double data;
    struct node* nxt;
};

struct node *head, *newn;
int count=0;

struct node* get_data()
{
    struct node* curn;
    head=NULL;
    /*newn=(struct node*)malloc(sizeof(struct node));
    head=newn;*/
    printf("\nEnter '0' to terminate. Otherwise continue... \n\n");
    double d;
    printf("Enter number : ");
    scanf("%lf",&d);
    curn=head;

    while(1)
    {
        if(d==0)
        {
            curn->nxt=NULL;
            break;
        }
        newn=(struct node*)malloc(sizeof(struct node));
        newn->data=d;
        curn=newn;

        curn->nxt=newn;
        scanf("%lf",&d);

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

struct node *middle_node(struct node *low,struct node *high)
{
    if(low==NULL)
    {
        return NULL;
    }
    struct node *slow,*fast;
    slow=low;
    //fast=low->nxt;
    fast=low->nxt;
    /*if(fast->nxt!=high)
    {
        fast=fast->nxt;
    }*/
    while(fast->nxt!=high)
    {
        fast=fast->nxt;
        if(fast->nxt!=high)
        {
            slow=slow->nxt;
            fast=fast->nxt;
        }
    }
    return slow;
};

struct node *binary_search()
{
    double num;
    struct node *low,*middle,*high;
    low=head;
    high=NULL;
    printf("Enter which number u wanna search : ");
    scanf("%lf",&num);
    do
    {
        middle=middle_node(low,high);
        if(middle==NULL)
        {
            printf("Search element not present..\n");
            break;
        }
        else if(middle->data==num)
        {
            printf("search result :  %d              \t%0.2lf           \t%d\n",middle,middle->data,middle->nxt);
            break;
        }
        else if(middle->data<num)
        {
            high=middle->nxt;
        }
        else if(middle->data>num)
        {
            low=middle;
        }
    }
    while(high == NULL || high->nxt!=low);
    return 0;

};

int main()
{
    struct node* root;
    double n;
    int count;
    //freopen("4. insertion.txt","r",stdin);

    get_data();
    traverse_list();
    binary_search();
    traverse_list();

    return 0;
}





