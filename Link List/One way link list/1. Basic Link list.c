#include <stdio.h>
#include <malloc.h>
struct block
{
    char cdata;
    struct block *nxtb;
};
int main()
{
    struct block *newb,*head,*tnb,*curb;
    char tdata;
    printf("Enter character: ");
    scanf("%c",&tdata);
    tnb=(struct block*)malloc(sizeof(struct block));
    printf("\ntnb_1 = %d",tnb);
    printf("\n&tnb_1 = %d",&tnb);
    tnb->cdata=tdata;
    head=tnb;
    printf("\nhead = tnb_1 = %d\n",head);
    printf("\n&head = tnb_1 = %d\n",&head);
    printf("\nEnter character: ");
    scanf("%c",&tdata);
    tnb=(struct block*)malloc(sizeof(struct block));
    printf("\ntnb_2 = %d",tnb);
    printf("\n&tnb_2 = %d",&tnb);
    /*curb=(struct block*)malloc(sizeof(struct block));
    printf("\ntnb_2 = %d",curb);
    printf("\n&tnb_2 = %d",&curb);*/
    tnb->cdata=tdata;
    head=tnb;
    /*printf("Enter character: ");
    scanf("%c",&curb->cdata);
    tnb->nxtb=curb;
    printf("\n%d",curb);
    curb->nxtb='\0';*/
    printf("\nhead = %d",&head);
    return 0;
}

/*
#include<stdio.h>
struct node
{
      char data;
      struct node *nxt;
};
int main()
{
      struct node *head;
      struct node *tb; //temporary block
      struct node *tnb; //new block
      char tdata;
      scanf("%c",&tdata);
      getchar();
      tnb=(struct node*)malloc(sizeof(struct node));
      head=tnb;
      tb=tnb;
      tnb->data=tdata;
      scanf("%c",&tdata);
      getchar();
      tnb=(struct node*)malloc(sizeof(struct node));
      tnb->data=tdata;
      tb->nxt=tnb;
      tb=tnb;
      scanf("%c",&tdata);
      getchar();
      tnb=(struct node*)malloc(sizeof(struct node));
      tnb->data=tdata;
      tb->nxt=tnb;
      tb=tnb;
      scanf("%c",&tdata);
      getchar();
      tnb=(struct node*)malloc(sizeof(struct node));
      tnb->data=tdata;
      tb->nxt=tnb;
      tb=tnb;
      tb->nxt=NULL;

      tb=head;
      while(tb)
      {
            printf("%x\t%c\t%x\n",tb,tb->data,tb->nxt);
            tb=tb->nxt;
      }
}
*/
