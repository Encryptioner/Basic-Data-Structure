#include <stdio.h>
#include <malloc.h>
struct node
{
    char data;
    struct node *nxtn;
};

struct node *head, *temnb, *tb, *cb;

struct node* get_set_node(char cdata)
{
    char tdata;
    temnb=(struct node*)malloc(sizeof(struct node));
    head=temnb;
    head->data=cdata;
    tb=head;
    tdata=cdata;
    printf("\nEnter '0' to terminate. Otherwise continue... \n\n");
    while(1)
    {
        tb=temnb;
        tb->data=tdata;
        scanf("\n%c",&tdata);
        getchar();
        temnb=(struct node*)malloc(sizeof(struct node));
        if(tdata=='0')
        {
            tb->nxtn='\0';
            break;
        }
        else
        {
            tb->nxtn=temnb;
        }
    }
    //printf("%d",head);
    return head;
}

int traverse_list(struct node *phead)
{
    cb=phead;
    printf("\n\n Current Node Address \t Current Node Data \t Next Node address\n\n");
    while(cb!=NULL)
    {
        printf("%10d\t\t%12c\t\t%10d\n",cb,(cb->data),(cb->nxtn));
        cb=cb->nxtn;
    }
    return 0;
}

int main()
{
    int n;
    char ch;
    printf("Enter a character: ");
    scanf("%c",&ch);
    getchar();
    n=get_set_node(ch);
    traverse_list(n);
    return 0;
}

