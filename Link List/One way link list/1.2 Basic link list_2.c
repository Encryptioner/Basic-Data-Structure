#include<stdio.h>
#include<malloc.h>

struct node
{
    char cdata;
    struct node *nxtb;
};

int main()
{

    int *p;
    struct node *newb,*head,*tnb,*cb;
    printf("size of char = %d\n",sizeof(char));
    printf("size of int = %d\n",sizeof(int));
//printf("size of *nxtb = %d\n",sizeof(nxtb));
    printf("size of struct node = %d\n",sizeof(struct node));
    tnb=(struct node*) malloc(sizeof(struct node));
    scanf("%c",&tnb->cdata);
    printf("\nhow?\n");
    cb=(struct node*) malloc(sizeof(struct node));
    scanf("%c",&cb->cdata);
    printf("\nhow?\n");
    tnb->nxtb=cb;
    cb->nxtb='\0';
    return 0;
}
