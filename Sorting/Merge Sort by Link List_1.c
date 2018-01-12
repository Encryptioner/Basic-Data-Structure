#include <stdio.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *nxt;
};

struct node *head,*newn;

struct node *get_node(int d)
{
    struct node *curn;
    head=NULL;
    newn=(struct node*)malloc(sizeof(struct node));
    head=newn;
    printf("Enter 0 to terminate...\n");
    while(1)
    {
        newn->data=d;
        curn=newn;
        //printf("curn = %d\n\n",curn);
        newn=(struct node*)malloc(sizeof(struct node));
        curn->nxt=newn;
        scanf("%d",&d);
        if(d==0)
        {
            curn->nxt=NULL;
            printf("newn = %d\n",newn);
            printf("curn->nxt = %d\n\n",curn->nxt);
            break;
        }

        //printf("curn->nxt = %d\n",curn->nxt);
    }
    printf("head = %d\n",head);
    printf("head->nxt = %d\n",head->nxt);
    printf("(head->nxt)->nxt = %d\n\n",(head->nxt)->nxt);
    return 0;
};

int traverse()
{
    struct node *curn;
    curn=head;
    printf("head = %d\n",head);
    printf("curn = %d\n",curn);
    printf("curn->nxt = %d\n",curn->nxt);
    printf("(head->nxt)->nxt = %d\n",(curn->nxt)->nxt);
    int count=0;
    /*while(1)
    {
        count=0;
    }*/
    printf("\nNo. Current node        Current node data      Next node link\n");
    while(curn)
    {
        count++;
        printf("%d.  %d              \t%d           \t%d\n",count,curn,curn->data,curn->nxt);
        curn=curn->nxt;

    }
    printf("\nNumber of node=%d\n",count);
    return 0;
};

int main()
{
    struct node *root;
    int d;
    int count;
    printf("Enter a number : ");
    scanf("%d",&d);
    get_node(d);
    traverse();
    return 0;
}
