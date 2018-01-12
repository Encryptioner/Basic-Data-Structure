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

struct node* delete_node()
{

    struct node *curn,*tempn;
    int d,i;
    int target_data;
    curn=head;

    while(1)
    {
        printf("\nEnter the value after which u wanna delete? Enter 0 if u wanna stop deleting process.. \n");
        scanf("%d",&target_data);
        //target_data=5;
        if(target_data==0)
        {
            break;
        }
        while(target_data!=curn->data)
        {
            curn=curn->nxt;
        }

        tempn=curn;
        if(curn->nxt!=NULL)
        {
            printf("\nEnter how many node u wanna delete? \n");
            scanf("%d",&d);
            d=1;

            for(i=0;i<=d;i++)
            {
                if(tempn->nxt!=NULL)
                {
                    tempn=tempn->nxt;
                }

            }
            curn->nxt=tempn;
            tempn->pre=curn;
        }
        else
        {
            printf("there is noyhing to delete as value is in last position..");
        }
        traverse_list();
    }
    return 0;;
}
int main()
{
    double num;
    int count;
    struct node *root;

    printf("Input a number : ");
    scanf("%lf",&num);

    get_set_node(num);
    traverse_list();

    delete_node();

    return 0;
}



