#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left,*right;
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

struct node* pre_order(struct node *Node)
{
    if(Node==NULL)
        return Node;
    printf("%d\n",Node->data);
    pre_order(Node->left);
    pre_order(Node->right);
};
struct node* in_order(struct node *Node)
{
    if(Node==NULL)
        return Node ;
    in_order(Node->left);
    printf("%d\n",Node->data);
    in_order(Node->right);

};
struct node* post_order(struct node* Node)
{
    if(Node==NULL)
        return Node ;
    post_order(Node->left);
    post_order(Node->right);
    printf("%d\n",Node->data);
};

void print(struct node* root,int choice)
{
      switch(choice)
    {
    case 1:
        {
              printf("\n\nPre order\n");
              pre_order(root);
        }
       break;
    case 2:
        {
             printf("\n\In order\n");
              in_order(root);
        }
          break;
    case 3:
        {
              printf("\n\Post order\n");
              post_order(root);
              break;

        }

    }
}
int find_min(struct node* root)
{
    while(root->left!=NULL)
        root=root->left;
    return root->data;
}

struct node* del(struct node* root,int data1)
{
    if(root==NULL)
        return root;
    else if(data1<root->data)
        {printf("\nParent:%d\n",root->data);
        root->left=del(root->left,data1);}
    else if(data1>root->data)
        {printf("\nParent:%d\n",root->data);
        root->right=del(root->right,data1);}
    else
    {
        if(root->left==NULL&&root->right==NULL)
        {
            printf("\nParent:%d\n",root->data);
            free(root);
            root=NULL;
        }
        else if(root->left==NULL)
        {
            struct node *temp=root;
            root=root->right;
            printf("\nParent:%d\n",root->data);
            free(temp);
        }
        else if(root->right==NULL)
        {
            struct node *temp=root;
            root=root->left;
            printf("\nParent:%d\n",root->data);
            free(temp);
        }
        else
        {
            int data1=find_min(root->right);
            root->data=data1;
            root->right=del(root->right,data1);
        }
    }
    return root;
};
int sdata;
int main()
{
    int root,root_item,remainings,choice1,choice;
    printf("print in which format?\n1.Pre order\n2.In order\n3.Post order\n");
    scanf("%d",&choice);
    printf("Enter parent:\n");
    scanf("%d",&root_item);
    root=insert(NULL,root_item);
    printf("Enter children and insert EOF to stop\n");
    while(1==scanf("%d",&remainings))
    {
            insert(root,remainings);
    }
    while(1)
    {
        printf("Option:\n1.Print:\n2.Delete:\n3.Exit:\n");
        scanf("%d",&choice1);
        switch(choice1)
        {
        case 1:
            {
                printf("\n\t\t\t\t\t\tYour tree\n");
                print(root,choice);
                continue;
            }
        case 2:
            {
                printf("Please enter which data you want to delete:\n");
                scanf("%d",&sdata);
                root=del(root,sdata);
                continue;
            }
        case 3:
            break;
        }

return  0;
    }
}



