#include<stdio.h>//complete binary tree
#include<stdlib.h>
#include<malloc.h>

struct node
{
    int tdata;
    struct node *left;
    struct node *right;
};

struct node* insert(struct node *par, int data)
{
    struct node *NN;
    if(par==NULL)
    {
        NN=(struct node*) malloc(sizeof(struct node));
        NN->tdata=data;
        NN->left=NULL;
        NN->right=NULL;
        par=NN;
    }
    else if(data<par->tdata)
    {
        if(par->left==NULL)
        {
            NN=(struct node*) malloc(sizeof(struct node));
            NN->tdata=data;
            NN->left=NULL;
            NN->right=NULL;
            par->left=NN;
        }
        else
        {
            insert(par->left,data);
        }
    }

    else if(data>=par->tdata)
    {
        if(par->right==NULL)
        {
            NN=(struct node*) malloc(sizeof(struct node));
            NN->tdata=data;
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
}

struct node *preorder(struct node *par)
{
    if(par==NULL)
        return par;//

    printf(" %d      \t%d           \t%d         \t%d\n",par,par->tdata,par->left,par->right);
    preorder(par->left);
    preorder(par->right);
}

struct node *inorder(struct node *par)
{
    if(par==NULL)
        return par;
    inorder(par->left);
    printf(" %d      \t%d           \t%d         \t%d\n",par,par->tdata,par->left,par->right);
    inorder(par->right);
}

struct node *postorder(struct node *par)
{
    if(par==NULL)
        return par;
    postorder(par->left);
    postorder(par->right);
    printf(" %d      \t%d           \t%d         \t%d\n",par,par->tdata,par->left,par->right);
}

struct node* delete_n(struct node *par, int data)
{
    if(par==NULL)
        return par;
    else if(data<par->tdata)
        par->left=delete_n(par->left,data);
    else if(data>par->tdata)
        par->right=delete_n(par->right,data);
    else
    {
        if(par->left==NULL && par->right==NULL)
        {
            printf("\nDeleting this value : \n");
            printf(" %d      \t%d           \t%d         \t%d\n",par,par->tdata,par->left,par->right);
            free(par);
            par=NULL;
        }

        else if(par->left==NULL)
        {
            struct node *temp;
            temp=par;
            printf("\nDeleting this value : \n");
            printf(" %d      \t%d           \t%d         \t%d\n",par,par->tdata,par->left,par->right);
            par=par->right;
            free(temp);
            temp=NULL;
        }

        else if(par->right==NULL)
        {
            struct node *temp;
            temp=par;
            printf("\nDeleting this value : \n");
            printf(" %d      \t%d           \t%d         \t%d\n",par,par->tdata,par->left,par->right);
            par=par->left;
            free(temp);
            temp=NULL;
        }
        else
        {
            printf("\nEither the data not in tree or it have two child..\n");
        }
    }

    return par;

}

int main()
{
    struct node *parn, *nblk;
    int data, choice;
    parn=NULL;
    nblk=NULL;
    printf("Enter parn data: \n");
    scanf("%d",&data);
    parn=insert(nblk,data);
    printf("Enter element of EOF (ctrl+z) to terminate:\n");
    while(scanf("%d",&data)==1)
    {
        insert(parn,data);
    }

    printf("\nEnter your choice:\n1. Preorder\n2. Inorder\n3. Postorder\n4. Delete \n5. New Insertion\n\n");
    while(scanf("%d",&choice)==1)
    {

        if(choice==1)
        {
            printf("\nPreorder node traversing:\n");
            printf("\nNo. Current node  Current node data   Previous node link     Next node link\n");
            preorder(parn);
        }
        else if(choice==2)
        {
            printf("\nInorder node traversing:\n");
            printf("\nNo. Current node  Current node data   Previous node link     Next node link\n");
            inorder(parn);
        }
        else if(choice==3)
        {
            printf("\nPostorder node traversing:\n");
            printf("\nNo. Current node  Current node data   Previous node link     Next node link\n");
            postorder(parn);
        }

        else if(choice==4)
        {
            printf("\nEnter node data: ");
            scanf("%d",&data);
            delete_n(parn,data);
            printf("\ndeleted.. Value with two child can't be deleted\n\n");

        }
        else if(choice==5)
        {
            printf("\nEnter element.. EOF (ctrl+z) to terminate:\n");
            while(scanf("%d",&data)==1)
            {
                insert(parn,data);
            }
        }
        else
            printf("\nInvalid\n");
        printf("\nEnter your choice:\n1. Preorder\n2. Inorder\n3. Postorder\n4. Delete \n5. New Insertion\n\n");

    }
    return 0;
}


