#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node
{
    char data;
    struct node *nxt;
};

char* get_set_node(char ch)
{
    struct node *head;
    struct node *tb;
    struct node *tnb;
    head=NULL;
    tb=(struct node*)malloc(sizeof(struct node));
    head=tb;
    printf("\n head = %x\n",head);
    while(1)
    {
        if(ch!='0')  //Enter 0 to terminate
        {
            tb->data=ch;
            tnb=tb;
            tb=(struct node*)malloc(sizeof(struct node));
            tnb->nxt=tb;
            printf("input a char or Enter 0 to terminate: ");
            scanf("%c",&ch);
            getchar();
        }
        else
            {
                tnb->nxt=NULL;
                break;
            }
    }

    return head;



}


void traverse_list(struct node *p)
{
    struct node *tb;

    tb=p;
    printf("tb node      tb node data       next node link\n");
    while(tb)
    {
        printf("%x         \t%c        \t%x\n",tb,tb->data,tb->nxt);
        tb=tb->nxt;
    }
    return ;

}

int main()
{

    char ch;
    struct node *p;
    printf("input a char or Enter 0 to terminate: ");
    scanf("%c",&ch);
    getchar();

    p=get_set_node(ch);
    traverse_list(p);
}
