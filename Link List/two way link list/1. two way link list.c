#include<stdio.h>
#include<malloc.h>

struct node
{
    double data;
    struct node *nxt,*pre;
};

struct node *head,*newn;

struct node* get_set_node(double num)
{
    struct node *curn;
    head=NULL;
    newn=(struct node*)malloc(sizeof(struct node));
    head=newn;
    head->pre=NULL;

    printf("Enter 0 to terminate...\n");
    while(1)
    {
            newn->data=num;
            curn=newn;
            newn=(struct node*)malloc(sizeof(struct node));
            newn->pre=curn;////
            curn->nxt=newn;
            scanf("%lf",&num);

        if(num==0)
        {
            curn->nxt=NULL;
            break;
        }
    }

    return head;
}

int traverse_list()
{
    int count=0;
    struct node *curn;
    curn=head;

    printf("\nNo. Current node  Current node data   Previous node link     Next node link\n");
    while(curn)
    {
        printf("%d.  %d      \t%0.2lf           \t%d         \t%d\n",++count,curn,curn->data,curn->pre,curn->nxt);
        curn=curn->nxt;

    }
    printf("\nNumber of node=%d\n",count);
    return 0;
}


int main()
{
    double num;
    int count;
    struct node *root;

    printf("Input a number : ");
    scanf("%lf",&num);

    root=get_set_node(num);
    count=traverse_list();

    return 0;
}


