#include <stdio.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *nxt;
};

struct node *head,*newn;
int count;

struct node *get_node(int n)
{
    struct node *curn;
    head=NULL;
    newn=(struct Node*)malloc(sizeof(struct node));
    head=newn;
    printf("Enter 0 to terminate...\n");
    while(1)
    {
        newn->data=n;
        curn=newn;
        newn=(struct Node*)malloc(sizeof(struct node));
        curn->nxt=newn;
        scanf("%d",&n);
        if(n==0)
        {
            curn->nxt=NULL;
            break;
        }
    }
    return 0;
};

int traverse()
{
    struct node *curn;
    curn=head;
    count=0;
    printf("\nNo. Current node        Current node data      Next node link\n");
    while(curn)
    {
        count++;
        printf("%d.  %d              \t%0.2lf           \t%d\n",count,curn,curn->data,curn->nxt);
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
            printf("Search element not5 present..\n");
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
    int n;
    //struct node *middle;
    printf("Enter Number : ");
    scanf("%d",&n);
    get_node(n);
    traverse();
    //binary_search();
}
