#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *LC,*RC;
};
struct node* insert(struct node *par,int data)
{
    struct node *LC,*RC,*NN;
    if(par==NULL)
    {
        NN=(struct node*)malloc(sizeof(struct node));
        NN->data=data;
        NN->LC=NULL;
        NN->RC=NULL;
        par=NN;
    }
    else if(data<par->data)
    {
        if(par->LC==NULL)
        {
             NN=(struct node*)malloc(sizeof(struct node));
             NN->data=data;
             NN->LC=NULL;
             NN->RC=NULL;
             par->LC=NN;
}
        else
        {
            insert(par->LC,data);
        }
    }
    else if(data>=par->data)
    {
        if(par->RC==NULL)
        {
             NN=(struct node*)malloc(sizeof(struct node));
             NN->data=data;
             NN->LC=NULL;
             NN->RC=NULL;
             par->RC=NN;
        }
        else
        {
            insert(par->RC,data);
        }
    }
    return par;
};
struct node* pre_order(struct node *Node)
{
    struct node *LC,*RC;
    int data;
    if(Node==NULL)
        return Node ;
    printf("%d\n",Node->data);
    pre_order(Node->LC);
    pre_order(Node->RC);
};
struct node* in_order(struct node *Node)
{
    struct node *LC,*RC;
    int data;
    if(Node==NULL)
        return Node ;
    in_order(Node->LC);
    printf("%d\n",Node->data);
    in_order(Node->RC);
};
struct node* post_order(struct node* Node)
{
    if(Node==NULL)
        return Node ;
    post_order(Node->LC);
    post_order(Node->RC);
    printf("%d\n",Node->data);
};
void print(struct node* root,int choice)
{
	switch(choice)
    {
    case 1:
        {
              printf("\n\nBelow is shown in pre order\n");
              pre_order(root);
        }
       break;
    case 2:
        {
             printf("\n\nBelow is shown in in order\n");
              in_order(root);
        }
          break;
    case 3:
        {
              printf("\n\nBelow is shown in post order\n");
              post_order(root);
              break;
		}
	}
}
int find_min(struct node* root)
{
    while(root->LC!=NULL)
        root=root->LC;
    return root->data;
}
struct node* delete_element(struct node* root,int sdata2)
{
    if(root==NULL)
        return root;
    else if(sdata2<root->data)
        root->LC=delete_element(root->LC,sdata2);
    else if(sdata2>root->data)
        root->RC=delete_element(root->RC,sdata2);
    else
    {
        if(root->LC==NULL&&root->RC==NULL)
        {
            free(root);
            root=NULL;
        }
        else if(root->LC==NULL)
        {
            struct node *temp=root;
            root=root->RC;
            free(temp);
        }
          else if(root->RC==NULL)
        {
            struct node *temp=root;
            root=root->LC;
            free(temp);
        }
        else
        {
            int sdata2=find_min(root->RC);
            root->data=sdata2;
            root->RC=delete_element(root->RC,sdata2);
        }
    }
    return root;
};
int main()
{
    int root,root_item,remainings,choice1,choice,sdata;
    printf("print in which format?\n1.pre order\n2.in order\n3.post order\n");
    scanf("%d",&choice);
   printf("Please insert root items:\n");
    scanf("%d",&root_item);
	root=insert(NULL,root_item);
    printf("Please insert remainings and insert # to stop\n");
    while(1==scanf("%d",&remainings))
    {
            insert(root,remainings);
    }
    while(1)
    {
        printf("Please press 1.for print:\n2.for delete:\n3.for exit:\n");
        getchar();
        scanf("%d",&choice1);
        switch(choice1)
        {
        case 1:
            {
                printf("The printed BST is:\n");
                print(root,choice);
                continue;
            }
        case 2:
            {
                printf("Please enter which data you want to delete:\n");
                scanf("%d",&sdata);
                root=delete_element(root,sdata);
                continue;
            }
        case 3:break;
        }
    }
	return 0;
}

