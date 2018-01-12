#include<stdio.h>
struct node
{
  int x;
  struct node *next;
};
int main()
{
    int c;
    struct node *root,*head;
    root = (struct node *) malloc (sizeof (struct node));
    scanf("%d",&c);
    root -> x =c;
    head= root;
    printf("%d\n",head);
    scanf("%d",&c);
    root = (struct node *) malloc (sizeof (struct node));
    root-> x =c;
    printf("%d\n",root);
    root -> x= c;
    head -> next =root;
    printf("%d\n",head->next);

}
