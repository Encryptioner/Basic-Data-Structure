#include<stdio.h>
#include<malloc.h>

struct node
{
    double data;
    struct node *nxt,*pre;
};

struct node *head,*newn;
int count;

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
            newn->pre=curn;
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
    count=0;
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

struct node* insertion()
{
    struct node *tempn;
    int x,j,i;
    double d;
    int choice;

    printf("\nEnter how many node u wanna add..?  ");
    scanf("%d",&choice);

    for(i=1;i<=choice;i++)
    {
        printf("\nEnter In which position u wanna add node_%d? ",i);
        scanf("%d",&x);
        if(x>0 && x<=count)
        {
            //while(ihead)
            {
                tempn=head;
                for(j=1;j<=x-2;j++)
                {
                    tempn=tempn->nxt;
                    //printf("jhhgjhgb");
                }

                printf("\nEnter data of inserted node : ");
                scanf("%lf",&d);
                newn=(struct node*)malloc(sizeof(struct node));
                newn->data=d;

                if(x==1)
                {
                    newn->pre=NULL;
                    newn->nxt=tempn;
                    tempn->pre=newn;
                    head=newn;
                }
                else
                {
                    newn->pre=tempn;
                    newn->nxt=tempn->nxt;
                    tempn->nxt=newn;
                    (newn->nxt)->pre=newn;
                }


                /*printf("newn = %d",newn );
                printf("newn->nxtb = %d",newn->nxtb );
                printf("tempn->nxtb = %d",tempn->nxtb );

                printf("newn->nxtb = %d",newn->nxtb );
                printf("tempn->nxtb = %d",tempn->nxtb );*/
                traverse_list();
            }
        }
        else
        {
            printf("\nInvalid input...\n");
        }
        //printf("\ni = %d\n",i);
    }

    return 0;
};

int main()
{
    double num;
    int count;
    struct node *root;

    printf("Input a number : ");
    scanf("%lf",&num);

    get_set_node(num);
    traverse_list();

    insertion();

    return 0;
}


