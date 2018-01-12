#include<stdio.h>
#include<stdlib.h>
struct node
{
    char cdata;
    struct node *cadd;
};
int delete(int d)
{
struct node *head,*fnn,*bnn,*pnn,*tnn;
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
tnn=head;
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
            tnn=tnn->cadd;
            i++;
            }
            bnn->cadd=tnn->cadd;
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
int main()
{
struct node *head,*fnn,*bnn,*pnn,*tnn;
int choice,i,target,d;
printf("Do you want to inset/delete:\n");
scanf("%d",&d);
if(d==1)
    delete(d);
else
{
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
while(1)
{
    printf("\nDo you want to insert?? (1/0)\n");
    scanf("%d",&choice);
    if ( choice ==0)
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
            bnn=bnn->cadd;
            i++;
        }
        tnn=(struct node *)malloc( sizeof ( struct node));
        scanf(" %c",&tnn->cdata);
        tnn->cadd=bnn->cadd;
        bnn->cadd=tnn;
        }
        else
        {
            tnn=(struct node *)malloc( sizeof ( struct node));
            scanf(" %c",&tnn->cdata);
            tnn->cadd= bnn;
            head=tnn;
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
}
}


