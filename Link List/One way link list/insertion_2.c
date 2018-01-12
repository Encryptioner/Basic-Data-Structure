#include<stdio.h>
#include<stdlib.h>
struct node
{
    char cdata;
    struct node *nxt;
};
int main()
{
struct node *head,*tnb,*tb,*pnn,*tnn;
int choice,i,target;
tnb=(struct node*)malloc(sizeof(struct node));
tnb->cdata=getchar();
head=tnb;
while(1)
{
    tb=tnb;
    tnb=(struct node*)malloc(sizeof(struct node));
    tnb->cdata=getchar();
    tb->nxt=tnb;
    if(tnb->cdata=='\n')
    {
           tb->nxt='\0';
           break;
    }
}
tb= head;
while(1)
{
    printf("\nDo you want to insert?? (1/0)\n");
    scanf("%d",&choice);
    if ( choice == 0)
        break;
    else
    {
        printf("\nWhich position do you want to add??\n");
        scanf("%d",&target);
        if (target>1)
        {
        i=1;
        while (i!= target-1)
        {
            tb=tb->nxt;
            i++;
        }
        tnn=(struct node *)malloc( sizeof ( struct node));
        scanf(" %c",&tnn->cdata);
        tnn->nxt=tb->nxt;
        tb->nxt=tnn;
        }
        else
        {
            tnn=(struct node *)malloc( sizeof ( struct node));
            scanf(" %c",&tnn->cdata);
            tnn->nxt= tb;
            head=tnn;
        }

    }

}
pnn=head;
  while (1)
   {
       printf("%c",pnn->cdata);
       if(pnn->nxt =='\0')
       break;
       pnn=pnn->nxt;
   }
return 0;
}
