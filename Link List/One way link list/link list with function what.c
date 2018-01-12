#include<stdio.h>
#include<stdlib.h>
int  creat_list();
void print_list();

struct list
{
    char cdata;
    int *nextadd;
};

int main()
{
    struct list *list1,*nb,*tnb,*pnb;
    list1=creat_list();

    print_list(list1);
    return 0;
}

int  creat_list()
{
    struct list *nb,*list1,*tnb;
     tnb=(struct list*)malloc(sizeof(struct list));
    tnb->cdata=getche();/*getche() means*/
    list1=tnb;
    while(1)
    {
        nb=tnb;
        printf("\n%x\n",nb);
        tnb=(struct list*)malloc(sizeof(struct list));
        tnb->cdata=getche();
        nb->nextadd=tnb;
          if(tnb->cdata=='\r')
            {  nb->nextadd='\0';
                break;}

    }
    return list1;
}

void print_list(struct list *pnb)
{
    while(1)
    {
        printf("%c",pnb->cdata);
          if(pnb->nextadd=='\0')
            break;
        pnb=pnb->nextadd;

    }

}
