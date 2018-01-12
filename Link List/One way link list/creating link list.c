#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node
{
    struct node *preblk;
    double data;
    struct node *nxtblk;
};

struct node *head, *temn, *curn, *newn;

struct node* get_node(double mdata)
{
    double tdata;
    head=NULL;
    newn=(struct node*)malloc(sizeof(struct node));
    head=newn;
    head->data=mdata;
    temn=head;
    tdata=mdata;
    temn->preblk=NULL;
    printf("\nEnter '0' to terminate. Otherwise continue... \n\n");
    while(1)
    {
        temn=newn;
        temn->data=tdata;
        scanf("%lf",&tdata);
        newn=(struct node*)malloc(sizeof(struct node));

        if(tdata==0)
        {
            temn->nxtblk=NULL;
            break;
        }

        temn->nxtblk=newn;
        newn->preblk=temn;
    }
    return head;
};

int main()
{
    double m;
    struct node *n;
    printf("Enter a number : ");
    scanf("%lf",&m);
    n=get_node(m);

    return 0;
}
