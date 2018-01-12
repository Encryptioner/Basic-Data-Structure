#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node
{
    int data;
    struct node *left;*right;
};

struct node* insert(struct node *par,int data)
{
    struct node *left,*right,*NN;
    if(par==NULL)
    {
        NN=(struct node*)malloc(sizeof(struct node));
        NN->data=data;
        NN->left=NULL;
        NN->right=NULL;
        par=NN;
    }
    else if(data<par->data)
    {
        if(par->left==NULL)
        {
             NN=(struct node*)malloc(sizeof(struct node));
             NN->data=data;
             NN->left=NULL;
             NN->right=NULL;
             par->left=NN;

        }
        else
        {
            insert(par->left,data);
        }
    }
    else if(data>=par->data)
    {
        if(par->right==NULL)
        {
             NN=(struct node*)malloc(sizeof(struct node));
             NN->data=data;
             NN->left=NULL;
             NN->right=NULL;
             par->right=NN;
        }
        else
        {
            insert(par->right,data);
        }
    }
    return par;
};



void print(struct node* parn,int choice)
{
      switch(choice)
    {
    case 1:
        {
              printf("\n\nPre order\n");
              pre_order(parn);
        }
       break;
    case 2:
        {
             printf("\n\In order\n");
              in_order(parn);
        }
          break;
    case 3:
        {
              printf("\n\Post order\n");
              post_order(parn);
              break;

        }

    }
}

int main()
{
    int parn,parn_item,choice,remain;
    /*printf("In which format ?\n");
    printf("Option:\n1.Pre order:\n2.In order:\n3.Post oder:\n");
    scanf("%d",&choice);*/
    printf("Enter parent:\n");
    scanf("%d",&parn_item);
    parn=insert(NULL,parn_item);
    printf("Enter children and insert EOF to stop\n");
    while(1==scanf("%d",&remain))
    {
            insert(parn,remain);
    }
    printf("\n\t\Your tree\n\n");
    print(parn,choice);

    while(1)
    {
        printf("Please enter which data you want to delete:\n");
        scanf("%d",&tdata);
        parn=del(parn,tdata);
        continue;
    }
return  0;
    }
}
