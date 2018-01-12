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

    printf("\nAfter which value u wanna add..?  ");
    scanf("%d",&choice);

        printf("\nwhich value u wanna add after desired data ? ");
        scanf("%d",&x);

            tempn=head;
            while(tempn)
            {
                if(tempn->data==choice)
                {
                    newn=(struct node*)malloc(sizeof(struct node));
                    newn->data=x;
                    newn->nxtb=tempn->nxtb;
                    tempn->nxtb=newn;
                    traverse_list();
                }
                tempn=tempn->nxtb;
            }

    return 0;
};

int main()
{
    struct node* root;
    double n;
    int count;
    //freopen("4. insertion.txt","r",stdin);
    printf("Enter a number : ");
    scanf("%lf",&n);
    get_data(n);
    traverse_list();
    insertion();

    return 0;
}



