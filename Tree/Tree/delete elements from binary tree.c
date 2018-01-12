#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *LC,*RC;
};
struct node* search(struct node* root,int sdata2,int* pfound2, int* prec_stop2)
{
	if(root==NULL)
		return ;
	 if(sdata2==root->data)
	{
		printf("FOund %d",sdata2);
		*pfound2=1;
		*prec_stop2=1;
		return;
	}
	else if(sdata2<root->data)
	{
		search(root->LC,sdata2,pfound2, prec_stop2);
	}

	else if(sdata2>root->data)
	{
		search(root->RC,sdata2,pfound2, prec_stop2);

	}
	if(*prec_stop2){
		printf("\nParent data %d\n",root->data);
		*prec_stop2=0;
	}
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

struct node* post_order(struct node *Node){
	struct node *LC,*RC;
    int data;
    if(Node==NULL)
        return Node ;
    post_order(Node->LC);
	post_order(Node->RC);
	printf("%d\n",Node->data);
};

int main()
{
    int root, root_item, remainings, choice,sdata,found=0, rec_stop=0;
    int *pfound=&found, *prec_stop=&rec_stop;
    printf("Print in which format?\n1. Pre-order\n2. In-order\n3. Post-order\n");
    scanf("%d",&choice);
    printf("Insert Root Item:\n");
    scanf("%d",&root_item);
    root=insert(NULL,root_item);
    printf("Insert The Remainings and  Insert # to stop\n");
    while(1==scanf("%d",&remainings)){
		insert(root,remainings);
    }
    switch(choice){
    	case 1:{
    		printf("\n\nBelow is shown in pre-order\n");
			pre_order(root);
    	}
    	break;
    	case 2:in_order(root);
    	break;
    	case 3: post_order(root);
    }
    printf("Enter an element to search:\n");
    getchar();
    scanf("%d",&sdata);
    search(root,sdata,pfound,prec_stop);
    if(!(*pfound))
		printf("Not found!");
    return 0;
}



