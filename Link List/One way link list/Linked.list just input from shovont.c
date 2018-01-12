#include<stdio.h>
#include<stdlib.h>
struct node
{
    char cdata;
    struct node *cadd;
};
int main()
{
struct node *head,*fnn,*bnn,*pnn;
fnn=(struct node*)malloc(sizeof(struct node));
fnn->cdata=getchar();
head=fnn;
while(1)
{
    bnn=fnn;
    fnn=(struct node*)malloc(sizeof(struct node));
    fnn->cdata=getchar();
    bnn->cadd=fnn;
    if(fnn->cdata=='0')
    {
           bnn->cadd='\0';
           break;
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
