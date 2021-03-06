#include<stdio.h>
#include<malloc.h>

struct node
{
    double data;
    struct node* nxtb;
};

struct node *head, *newn;

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
    return head;
};

int traverse_list(struct node *rhead)
{
    int count=0;
    printf("\nNo. Current node        Current node data      Next node link\n");
    while(rhead)
    {
        count++;
        printf("%d.  %d              \t%0.2lf           \t%d\n",count,rhead,rhead->data,rhead->nxtb);
        rhead=rhead->nxtb;

    }
    printf("\nNumber of node=%d\n",count);
    return count;
};

struct node* insertion(struct node *phead,int count)
{
    struct node *tempn,*ihead,*tb;
    ihead=phead;
    int x,l=1,i;
    double d;
    int choice;

    printf("\nEnter how many node u wanna add..?  ");
    scanf("%d",&choice);

    for(i=0;i<choice;i++)
    {
        printf("\nEnter In which position u wanna add node_%d? ",i+1);
        scanf("%d",&x);
        if(x>0 && x<=count)
        {
            while(ihead)
            {
                if(l==x)
                {
                    tb=ihead->nxtb;
                    //tempn=ihead;
                    //printf("\ntemn_%d = %d \n",i+1,tempn);
                    newn=(struct node*)malloc(sizeof(struct node));
                    //newn->nxtb=tempn;
                    //printf("\ntemn_%d_2 = %d \n",i+1,tempn);
                    //printf("\nnewn_%d = %d \n",i+1,newn);
                    tempn=ihead;
                    tempn->nxtb=newn;

                    printf("\nEnter data of inserted node : ");
                    scanf("%lf",&d);
                    //newn->data=d;
                    //ihead=newn;
                    //printf("\nihead_%d = %d \n",i+1,ihead);
                    ihead->data=d;
                    ihead->nxtb=tb;
                    if(i<choice-1)
                    {
                        count=traverse_list(phead);
                        printf("\nCount = %d\n",count);
                    }
                    break;
                }
                ihead=ihead->nxtb;
                l++;
                printf("\nLine_%d = %d\n\n",i+1,l);
            }
        }
        else
        {
            printf("\nInvalid input...\n");
        }
        printf("\ni = %d\n",i);
    }

    return;
};

int main()
{
    struct node* root;
    double n;
    int count;
    //freopen("4. insertion.txt","r",stdin);
    printf("Enter a number : ");
    scanf("%lf",&n);
    root=get_data(n);
    count=traverse_list(root);
    insertion(root,count);
    count=traverse_list(root);
    //printf("\nNumber of node=%d\n",count);

    return 0;
}

