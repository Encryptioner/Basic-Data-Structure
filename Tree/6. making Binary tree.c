#include<stdio.h>
#include<malloc.h>

struct node
{
    int data;
    struct node *lc,*rc;
};

struct node *root,*parn,*nn,*cb;

struct node* insert(struct node *parn,int data)
{
    if(parn==NULL)
    {
        nn=(struct node*)malloc(sizeof(struct node));
        nn->data=data;
        nn->lc=nn->rc=NULL;
    }
    if(data<parn->data)
    {
        if(parn->lc==NULL)
        {
            nn=(struct node*)malloc(sizeof(struct node));
            nn->data=data;
            nn->lc=NULL;
        }
        else
        {
            nn=(struct node*)malloc(sizeof(struct node));
            nn->data=data;
            nn->rc=NULL;
        }
    }
    if(data>=parn->data)
    {
        if(parn->lc==NULL)
        {
            nn=(struct node*)malloc(sizeof(struct node));
            nn->data=data;
            nn->lc=NULL;
        }
        else
        {
            nn=(struct node*)malloc(sizeof(struct node));
            nn->data=data;
            nn->rc=NULL;
        }
    }
    return parn;
}

int print_data(struct node *phead)
{
    cb=phead;
    printf("\n\nLeft Nod address \t C Nod Address \t   C Nod Data \tRight Nod address\n\n");
    while(cb!=NULL)
    {
        printf("%8d\t\t    %d\t\t%5d\t\t %d\n",(cb->lc),cb,(cb->data),(cb->rc));
        cb=cb->rc;
    }
    return 0;
}

int main()
{
    struct node *n;
    root=(struct node*)malloc(sizeof(struct node));
    root->lc=NULL;
    root->rc=NULL;
    parn=root;
    n=insert(parn,30);
    insert(parn,10);
    insert(parn,35);
    insert(parn,5);
    insert(parn,15);
    print_data(n);
    return 0;
}



