#include <stdio.h>
int main()
{
    int r1,r2,c1,c2,n,i,j;
    double a[10][10],b[10][10],c[10][10];
    printf("How many rows in a= ");
    scanf("%d",&r1);
    printf("How many columns in a= ");
    scanf("%d",&c1);
    printf("How many rows in b= ");
    scanf("%d",&r2);
    printf("How many rows in b= ");
    scanf("%d",&c2);
    if(r1==r2 & c1==c2)
    {
        printf("\nNow,Input a\n");
        for(i=0;i<r1;i++)
        {
            printf("row %d :\n",i+1);
            for(j=0;j<c1;j++)
                scanf("%lf",&a[i][j]);
        }
        printf("\nNow, Input b\n");
        for(i=0;i<r2;i++)
        {
            printf("row %d :\n",i+1);
            for(j=0;j<c2;j++)
                scanf("%lf",&b[i][j]);
        }
        printf("\nNow, Matrix a=\n");
        for(i=0;i<r1;i++)
        {
            for(j=0;j<c1;j++)
                printf("\t%.2lf\t",a[i][j]);
                printf("\n\n");
        }
        printf("\nNow, Matrix b=\n");
        for(i=0;i<r2;i++)
        {
            for(j=0;j<c2;j++)
                printf("\t%.2lf\t",b[i][j]);
                printf("\n\n");
        }

        /*for(i=0;i<r2;i++)
        {
            for(j=0;j<c2;j++)
                c[i][j]=a[i][j]+b[i][j];
        }*/
        printf("Now, Summation= \n\n");
        for(i=0;i<r1;i++)
        {
            for(j=0;j<c1;j++)
                printf("\t%.2lf\t",(a[i][j]+b[i][j]));/*uporer loop chalale sudhu c[i][j] use korte hobr*/
                printf("\n\n");
        }
    }
    else
    {
        printf("\nSyntax Error\n");
    }
    return 0;
}
