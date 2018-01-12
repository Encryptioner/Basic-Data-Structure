#include <stdio.h>//all the 4no incomplete... delete hoy na
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
    d=0;
    struct node *current, *targetn;
    current=headech;
    targetn=current;
    /*printf("\nEnter how many node u wanna delete? \n");
    scanf("%d",&d);*/
    printf("\nEnter the value which u wanna delete? \n");
    scanf("%d",&target_data);
    //current=targetn;
    while(targetn->nxtn!=NULL)
    //while(1)
    {
        if((targetn->nxtn)->data==target_data)
        {
            (targetn->parn)->nxtn=targetn->nxtn;
            (targetn->nxtn)->parn=targetn->parn;
        }
        targetn=targetn->nxtn;

        /*if(targetn->nxtn==NULL)
        {
            break;
        }*/

        d++;
        printf("\n%d\n",d);
        break;
    }
    /*(targetn->parn)->nxtn=targetn->nxtn;
    (targetn->nxtn)->parn=targetn->parn;*/
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

