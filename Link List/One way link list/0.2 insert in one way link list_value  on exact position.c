#include<stdio.h>
#include<malloc.h>

struct node
{
    double data;
    struct node* nxtb;
};

struct node *head, *newn;
int count=0;

struct node* get_data(double d)
{
    int x;
    scanf("%d",&x);
    newn=(struct node*)malloc(sizeof(struct node));
        newn->data=x;
        newn->nxtb=NULL;
        printf("%d.  %d              \t%d           \t%d\n",count,newn,newn->data,newn->nxtb);
    struct node* curn;
    head=NULL;
    newn=(struct node*)malloc(sizeof(struct node));
    head=newn;
    printf("\nEnter '0' to terminate. Otherwise continue... \n\n");
    while(1)
    {
        newn->data=d;
        curn=newn;
        newn=(struct node*)malloc(sizeof(struct node));
        curn->nxtb=newn;
        scanf("%lf",&d);
        if(d==0)
        {
            curn->nxtb=NULL;
            break;
        }
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
        printf("%d.  %d              \t%0.2lf           \t%d\n",count,rhead,rhead->data,rhead->nxtb);
        rhead=rhead->nxtb;

    }
    printf("\nNumber of node=%d\n",count);
    return 0;
};

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
                    tempn=tempn->nxtb;
                    //printf("jhhgjhgb");
                }

                printf("\nEnter data of inserted node : ");
                scanf("%lf",&d);
                newn=(struct node*)malloc(sizeof(struct node));
                newn->data=d;

                if(x==1)
                {
                    newn->nxtb=tempn;
                    head=newn;
                }
                else
                {
                    newn->nxtb=tempn->nxtb;
                    tempn->nxtb=newn;
                }


                printf("newn = %d",newn );
                printf("newn->nxtb = %d",newn->nxtb );
                printf("tempn->nxtb = %d",tempn->nxtb );

                /*printf("newn->nxtb = %d",newn->nxtb );
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

    /*int d;
    scanf("%d",&d);
    newn=(struct node*)malloc(sizeof(struct node));
        newn->data=d;
        newn->nxtb=NULL;
        printf("%d.  %d              \t%d           \t%d\n",count,newn,newn->data,newn->nxtb);*/

    struct node* root;
    double n;
    int count;
    //freopen("4. insertion.txt","r",stdin);
    printf("Enter a number : ");
    scanf("%lf",&n);
    get_data(n);
    traverse_list();
    insertion();
    //traverse_list();
    //printf("\nNumber of node=%d\n",count);

    return 0;
}


