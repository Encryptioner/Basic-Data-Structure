#include<stdio.h>//2.10
#include<math.h>

int main()
{
    int x,i,j,min;
    double sum,average;
    printf("Number of Student : ");
    scanf("%d",&x);
    const int n=x;
    int a[n][4], b[n];
    /*a[1][5]=6;
    printf("%d",a[1][5]);*/
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=4;j++)
        {
            printf("enter number of ct %d of roll %d : ",j,i);
            scanf("%d",&a[i][j]);
        }
    }
    for(i=1;i<=n;i++)
    {
        min=a[i][1];
        sum=0;
        average=0;
        for(j=1;j<=4;j++)
        {
            sum=sum+a[i][j];

            if(a[i][j]<min)
            {
                min=a[i][j];
            }
        }
        average=(sum-min)/3;
        b[i]=ceil(average);
    }
    for(i=1;i<=n;i++)
    {
        //cout<<"roll "<<i<<" gets "<<b[i]<<endl;
        printf("roll %d gets %d\n",i,b[i]);
    }
    return 0;
}
