#include <stdio.h>//ekta pore matro ektai delete hoy
#include <malloc.h>
struct node
{
    struct node *parn;
    int data;
    struct node *nxtn;
};

struct node *head, *tb, *temnb, *cb;

struct node* get_node(int mdata)
{
    int tdata;
    head=NULL;
    //printf("\n(1) head in get_node = %d\n\n",head);
    temnb=(struct node*)malloc(sizeof(struct node));
    head=temnb;
    head->data=mdata;
    tb=head;
    tdata=mdata;
    tb->parn=NULL;
    //printf("\n(2) head in get_node = %d\n\n",head);
    printf("\nEnter '0' to terminate. Otherwise continue... \n\n");
    while(1)
    {
        tb=temnb;
        tb->data=tdata;
        scanf("%d",&tdata);
        temnb=(struct node*)malloc(sizeof(struct node));
        if(tdata==0)
        {
            tb->nxtn=NULL;
            break;
        }
        tb->nxtn=temnb;
        temnb->parn=tb;
    }
    return head;
};

int print_data(struct node *phead)
{
    int count;
    count=0;
    cb=phead;
    printf("\n\nC parent address \t C Nod Address \t     C Nod Data \t Nex Nod address\n\n");
    while(cb!=NULL)
    {
        printf("%8d\t\t     %d\t\t%5d\t\t %d\n",(cb->parn),cb,(cb->data),(cb->nxtn));
        cb=cb->nxtn;
        count++;
    }
    printf("\nNumber of node = %d\n\n",count);
    return 0;
}
struct node* delete_node(struct node* headech)
{
    int i,d,target_data;
    struct node *current, *targetn;
    current=headech;
    targetn=current;
    printf("\nEnter how many node u wanna delete? \n");
    scanf("%d",&d);
    printf("\nEnter the value after which u wanna delete? \n");
    scanf("%d",&target_data);
    while(target_data!=current->data)
    {
        current=current->nxtn;
    }
    targetn=current;

    for(i=1;i<=d;i++)
    {
        targetn=targetn->nxtn;
    }
    (targetn->parn)->nxtn=targetn->nxtn;
    (targetn->nxtn)->parn=targetn->parn;
    return headech;
};

int main()
{
    int m,num;
    char choice;
    struct node *n;
    printf("Enter a number: ");
    scanf("%d",&m);
    n=get_node(m);
    print_data(n);
    n=delete_node(n);
    print_data(n);
    return 0;
}

