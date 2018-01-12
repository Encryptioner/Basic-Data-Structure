#include<stdio.h>//have problem doesn't show exact pre
#include<conio.h>

int arr[100],count;

void inorder(int pos)
{
        int i,j;
        i = 2*pos + 1;
        if(arr[i] != 0)
        inorder(i);

        printf("\t %d",arr[pos]);

        j = 2*pos +2;
        if(arr[j] != 0)
        inorder(j);

}
void preorder(int pos)
{
        printf("\t %d",arr[pos]);

        int i,j;
        i = 2*pos + 1;
        if(arr[i] != 0)
        inorder(i);

        j = 2*pos +2;
        if(arr[j] != 0)
        preorder(j);
}
void postorder(int pos)
{
        int i,j;
        i = 2*pos + 1;
        if(arr[i] != 0)
        inorder(i);

        j = 2*pos +2;
        if(arr[j] != 0)
        preorder(j);

        printf("\t %d",arr[pos]);
}

void main()
{
    int i,num,c;
    count = 0;
    for(i=0;i<100;i++)
    arr[i] = 0;
    printf("1.) Insert\n");
    printf("2.) Delete\n");
    printf("3.) Search\n");
    printf("4.) In order\n");
    printf("5.) Pre order\n");
    printf("6.) Post Order\n");
    printf("7.) Exit\n");


while(1)
{

    printf("\nEnter Choice=\n");
    scanf("%d",&c);

    switch(c)
    {

    case 1:
    printf("Enter Element=");
    scanf("%d",&num);
    arr[count] = num;
    count++;
    break;

    case 2:
    printf("\nEnter the element to be deleted=");
    scanf("%d",&num);
    for(i=0;i<count;i++)
    {
    if(arr[i]==num)
    {
    count--;
    arr[i]=arr[count];
    arr[count] = 0;
    break;
    }
    }
    if(i==count)
    printf("\nElement not Found");
    break;

    case 3:
    printf("\nEnter The Element To Be Searched=");
    scanf("%d",&num);
    for(i=0;i<count;i++)
    {
        if(arr[i]==num)
        {
        printf("\nElement Found");
        break;
        }
    }
        if(i==count)
        printf("\nElement not found");

        break;
        case 4:
        inorder(0);
        break;
        case 5:
        preorder(0);
        break;
        case 6:
        postorder(0);
        break;
        case 7:
        exit(0);
        break;

   }
}
}



