#include<stdio.h>
#include<stdlib.h>

struct tree
{
    int idata;
    struct tree *LC;
    struct tree *RC;
};

struct tree* insert(struct tree *par, int data)
{
    struct tree *NN;
    if(par==NULL)
    {
        NN=(struct tree*) malloc(sizeof(struct tree));
        NN->idata=data;
        NN->LC=NULL;
        NN->RC=NULL;
        par=NN;
    }
    else if(data<par->idata)
    {
        if(par->LC==NULL)
        {
            NN=(struct tree*) malloc(sizeof(struct tree));
            NN->idata=data;
            NN->LC=NULL;
            NN->RC=NULL;
            par->LC=NN;
        }
        else
        {
            insert(par->LC,data);
        }
    }

    else if(data>par->idata)
    {
        if(par->RC==NULL)
        {
            NN=(struct tree*) malloc(sizeof(struct tree));
            NN->idata=data;
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
}

void preorder(struct tree *par)
{
    if(par==NULL)
        return par;
    printf("%d\n",par->idata);
    preorder(par->LC);
    preorder(par->RC);
}

void inorder(struct tree *par)
{
    if(par==NULL)
        return par;
    inorder(par->LC);
    printf("%d\n",par->idata);
    inorder(par->RC);
}

void postorder(struct tree *par)
{
    if(par==NULL)
        return par;
    postorder(par->LC);
    postorder(par->RC);
    printf("%d\n",par->idata);
}

struct tree* delete_n(struct tree *par, int data)
{
    if(par==NULL)
        return par;
    else if(data<par->idata)
        par->LC=delete_n(par->LC,data);
    else if(data>par->idata)
        par->RC=delete_n(par->RC,data);
    else
    {
        if(par->LC==NULL && par->RC==NULL)
        {
            free(par);
            par=NULL;
        }

        else if(par->LC==NULL)
        {
            struct tree *temp;
            temp=par;
            par=par->RC;
            free(temp);
            temp=NULL;
        }

        else if(par->RC==NULL)
        {
            struct tree *temp;
            temp=par;
            par=par->LC;
            free(temp);
            temp=NULL;
        }
    }

    return par;

}
int main()
{
    struct tree *root, *root1;
    int data, choice;
    root=NULL;
    root1=NULL;
    printf("Enter root data: \n");
    scanf("%d",&data);
    root=insert(root1,data);
    printf("Enter element of EOF to terminate:\n");
    while(scanf("%d",&data)==1)
    {
        insert(root,data);
    }

    printf("Enter your choice:\n1. Preorder\n2. Inorder\n3. Postorder\n4. Delete\n");
    while(scanf("%d",&choice)==1)
    {
        if(choice==1)
        {
            printf("Preorder tree traversing:\n");
            preorder(root);
        }
        else if(choice==2)
        {
            printf("Inorder tree traversing:\n");
            inorder(root);
        }
        else if(choice==3)
        {
            printf("Postorder tree traversing:\n");
            postorder(root);
        }

        else if(choice==4)
        {
            printf("Enter node data: ");
            scanf("%d",&data);
            delete_n(root,data);

        }
        else
            printf("Invalid\n");
        printf("Enter your choice:\n1. Preorder\n2. Inorder\n3. Postorder\n4. Delete\n");

    }



    return 0;
}


