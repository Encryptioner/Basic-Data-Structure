#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct block
{
    char data;
    struct block *nxt;
};
int main()
{
    int i,choice,target;
    char ch;
   struct block *head, *tnb, *tb, *tnn, *pnn;
   printf("Enter char: ");
   scanf("%c",&ch);
   getchar();
   tnb=(struct block*)malloc(sizeof(struct block));
   tnb->data=ch;
   head=tnb;
   while(1)
   {
       tb=tnb;
       //printf("Enter char...");
       scanf("%c",&ch);
       getchar();
       tnb=(struct block*)malloc(sizeof(struct block));
       tnb->data=ch;
       tb->nxt=tnb;
       if(tnb->data == '\n')
       {
           tb->nxt='\0';
           break;
       }
   }
   tb=head;
   while(1)
   {
       printf("\nDo u want to insert? (1/0)..");
       scanf("%d",&choice);
       if(choice == 0)
        break;

       else
       {
           printf("\nWhich position u want to add??..\n");
           scanf("%d",&target);
           if(target>1){
            i=1;
            while(i!= target-1)
            {
               tb=tb->nxt;
               i++;
            }
           tnn=(struct block*)malloc(sizeof(struct block));
           scanf("%c",&tnn->data);
           getchar();
           //tnn->data=ch;
           tnn->nxt=tb->nxt;
           tb->nxt=tnn;

           }
           else{
           tnn=(struct block*)malloc(sizeof(struct block));
           scanf("%c",&tnn->data);
           getchar();
           //tnn->data=ch;
           tnn->nxt=tb;
           head=tnn;

           }
       }

   }
    pnn=head;
       while(1)
       {
           printf("%c",pnn->data);
           if(pnn->nxt=='\0');
           break;
           pnn=pnn->nxt;
       }
       //return 0;
return 0;

}
