#include<stdio.h>
#include<stdlib.h>

struct node
{
    char cdata;
    struct node *nxnd;
};
char* get_set_node(char ch)
{
    struct node *head,*current,*newblk;
    head=NULL;
    current=(struct node*)malloc(sizeof(struct node));
    head=current;
    while(1)
    {
        if(ch!='0')
        {
            current->cdata=ch;
            newblk=current;
            printf("newblk = %d\n\n",newblk);
            current=(struct node*)malloc(sizeof(struct node));
            newblk->nxnd=current;
            printf("Input a char or Enter 0 to terminate: ");
            scanf("%c",&ch);
            getchar();
        }
        else
        {
            newblk->nxnd=NULL;
            break;
        }
    }
     printf("head = %d\n",head);
    printf("head->nxt = %d\n",head->nxnd);
    printf("(head->nxt)->nxt = %d\n\n",(head->nxnd)->nxnd);
    return head;
}
void traverse_list(struct node *s)
{
    struct node *current;
    current=s;
    printf("Current node  Current node data     Next node link\n");
    while(current)
    {
        printf("%d              \t%c       \t%d\n",current,current->cdata,current->nxnd);
        current=current->nxnd;
    }
    return;
}
int main()
{
    char ch;
    struct node *s;
    printf("Input a char or Enter 0 to terminate: ");
    scanf("%c",&ch);
    getchar();
    s=get_set_node(ch);
    traverse_list(s);
}
