#include <stdio.h>
#include <malloc.h>
//#include <conio.h> /* If i use this header file and getch() at next then return 0 will show nxt */
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
    printf("\nEnter '0' to terminate. Otherwise input character to continue ... \n\n");
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
    int count=0;
    cb=phead;
    printf("\n\n Current Node Address \t Current Node Data \t Next Node address\n\n");
    while(cb!=NULL)
    {
        printf("%10d\t\t%12c\t\t%10d\n",cb,(cb->data),(cb->nxtn));
        cb=cb->nxtn;
        count++;
    }
    printf("\nNumber of node = %d\n\n",count);
    return count;
}

struct node* delete_node(struct node *headech, int count)
{
    printf("\nNumber of node = %d\n\n",count);
    struct node *current, *tmpblock;
    //tmpblock=NULL;
    int d,i;
    char target_data;
    current=headech;
    printf("\nEnter how many node u wanna delete? \n");
    scanf("%d",&d);
    printf("\nEnter the value after which u wanna delete? \n");
    scanf(" %c",&target_data); /* why program doesn't work for using getchar() or getc(target_data) */
    //getchar();
    //getc(target_data);
    while(target_data!=current->data)
    {
        current=current->nxtn;
    }
    tmpblock=current;
    for(i=0;i<=d;i++)
    {
        tmpblock=tmpblock->nxtn;
    }
    current->nxtn=tmpblock;
    return headech;
}

int main()
{
    int num;
    char ch,choice;
    struct node *n;
    printf("Enter a character: ");
    scanf("%c",&ch);
    getchar();
    n=get_set_node(ch);
    num=traverse_list(n);
    printf("\nDo u want to delete? Press 'Y' to continue. Except inputting 'Y' program will terminate...\n\n");
    scanf("%c",&choice);
    getchar();
    if(choice =='y' || choice =='Y')
    {
        n=delete_node(n,num);
        num=traverse_list(n);
        printf("\nDo u want to delete? Press 'Y' to continue. Except inputting 'Y' program will terminate...\n\n");
        scanf("%c",&choice);
        getchar();
    }
    //getch();
    return 0;
}
