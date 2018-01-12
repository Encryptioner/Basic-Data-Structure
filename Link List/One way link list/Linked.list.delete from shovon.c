#include<stdio.h>
#include<stdlib.h>
struct node
{
    char cdata;
    struct node *cadd;
};
int main()
{
struct node *head,*fnn,*bnn,*pnn,*tmp;
int choice,i,target;
fnn=(struct node*)malloc(sizeof(struct node));
fnn->cdata=getchar();
head=fnn;
while(1)
{
    bnn=fnn;
    fnn=(struct node*)malloc(sizeof(struct node));
    fnn->cdata=getchar();
    bnn->cadd=fnn;
    if(fnn->cdata=='\n')
    {
           bnn->cadd='\0';
           break;
       }
}
bnn= head;
tmp=head;
while(1)
{
    printf("\nDo you want to delete?? (1/0)\n");
    scanf("%d",&choice);
    if ( choice ==0)
        break;
    else
    {
        printf("\nIn which position do you want to delete??\n");
        scanf("%d",&target);
        if (target>1)
        {
            i=0;
            while (i!= target-2)
            {
            bnn=bnn->cadd;
            i++;
            }
            i=0;
            while (i!= target-1)
            {
            tmp=tmp->cadd;
            i++;
            }
            bnn->cadd=tmp->cadd;
        }
        else
        {
            bnn= bnn->cadd;
            head=bnn;
        }
    }
}
  pnn=head;
  while (1)
   {
       printf("%c",pnn->cdata);
       if(pnn->cadd =='\0')
       break;
       pnn=pnn->cadd;
   }
return 0;
}
