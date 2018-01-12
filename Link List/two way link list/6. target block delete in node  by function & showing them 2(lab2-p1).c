#include <stdio.h>
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
    int i=1;
    head=NULL;
    printf("\n(1) head in get_node = %d\n\n",head);
    temnb=(struct node*)malloc(sizeof(struct node));
    head=temnb;
    //head->parn=NULL;
    printf("\n& head->parn(%d) = %d\n",i,&head->parn);
    printf("\n& head->nxtn(%d) = %d\n",i,&head->nxtn);
    printf("\n& head->data= %d\n",&head->data);
    head->data=mdata;
    tb=head;
    tdata=mdata;
    printf("\n& mdata(%d) = %d\n",i,&mdata);
    tb->parn=NULL;
    printf("\ntb->parn(%d) = %d\n",i,tb->parn);
    printf("\n& tb->parn(%d) = %d\n",i,&tb->parn);
    printf("\ntb->nxtn(%d) = %d\n",i,tb->nxtn);
    printf("\n& tb->nxtn(%d) = %d\n",i,&tb->nxtn);
    printf("\n(2) head in get_node = %d\n\n",head);
    printf("\n(2) tb in get_node = %d\n\n",tb);
    printf("\nEnter '0' to terminate. Otherwise continue... \n\n");
    //printf("(pb->parn) = %5d \n",(pb->parn));
    while(1)
    {
        //temnb=(struct node*)malloc(sizeof(struct node));
        //pb->parn=NULL;
        //printf("\n(pb->parn) = %5d \n",(pb->parn));
        //pb=tb;
        //printf("\n(3)tb in get_node = %d\n\n",tb);
        tb=temnb;
        temnb=(struct node*)malloc(sizeof(struct node));
        printf("\n(%d)tb in get_node = %d\n\n",i,tb);
        printf("\n(%d) temnb in get_node = %d\n\n",i,temnb);
        printf("\n& tb->data(%d) = %d\n",i,&tb->data);
        tb->data=tdata;
        printf("\n& tb->data(%d again) = %d\n",i,&tb->data);
        printf("\ntdata(%d) = %d\n",i,tdata);
        printf("\n& tdata(%d) = %d\n\n",i,&tdata);
        scanf("%d",&tdata);
        printf("\n\ntdata(%d) = %d\n",i+1,tdata);
        printf("\n& tdata(%d) = %d\n\n",i+1,&tdata);
        //printf("\ntb->data = %d\n\n",tb->data=tdata);
        //temnb=(struct node*)malloc(sizeof(struct node));
        if(tdata==0)
        {
            tb->nxtn=NULL;
            printf("\n& tb->nxtn(%d) = %d\n",i,&tb->nxtn);
            break;
        }
        tb->nxtn=(temnb);
        temnb->parn=(tb);
        /*tb->nxtn=&(temnb->parn); or tb->nxtn=(temnb);
        temnb->parn=&(tb->nxtn);*/
        printf("\ntb->parn(%d) = %d\n",i,tb->parn);
        printf("\ntb->nxtn(%d) = %d\n",i,tb->nxtn);
        printf("\n& tb->parn(%d) = %d\n",i,&(tb->parn));
        printf("\n& tb->nxtn(%d) = %d\n",i,&tb->nxtn);
        printf("\ntemnb->parn(%d) = %d\n",i+1,temnb->parn);
        printf("\ntemnb->data(%d) = %d\n",i+1,temnb->data);
        printf("\ntemnb->nxtn(%d) = %d\n",i+1,temnb->nxtn);
        printf("\n& temnb->parn(%d) = %d\n",i+1,&temnb->parn);
        printf("\n& temnb->data(%d) = %d\n",i+1,&temnb->data);
        printf("\n& temnb->nxtn(%d) = %d\n",i+1,&temnb->nxtn);
        /*if((tb->parn)==NULL)
        {
            pb->parn=tb;
        }*/
        //pb=tb;
        //break;
        i++;
    }
    return head;
};

int print_data(struct node *phead)
{
    int count=0;
    cb=phead;
    printf("\n\nC parent address \t C Nod Address \t     C Nod Data \t Nex Nod address\n\n");
    while(cb!=NULL)
    {
        printf("%8d\t\t     %d\t\t%5d\t\t %d\n",(cb->parn),cb,(cb->data),(cb->nxtn));
        cb=cb->nxtn;
        count++;
    }
    printf("\nNumber of node = %d\n\n",count);
    return count;
}
struct node* delete_node(struct node* headech, int count)
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

    for(i=0;i<d;i++)
    {
        /*printf("\nWhich node u wanna delete? Enter Serial Number: \n");
        printf("%d");*/
        targetn=targetn->nxtn;
    }
    (targetn->parn)->nxtn=targetn->nxtn;
    //(targetn->nxtn)->parn=targetn->parn;
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
    num=print_data(n);
    printf("\nDo u want to delete? Press 'Y' to continue. Any other input will terminate program...\n\n");
    scanf("%c",&choice);
    getchar();
    if(choice =='y' || choice =='Y')
    {
        n=delete_node(n,num);
        num=print_data(n);
        printf("\nDo u want to delete? Press 'Y' to continue. Any other input will terminate program...\n\n");
        scanf("%c",&choice);
        getchar();
    }
    return 0;
}
