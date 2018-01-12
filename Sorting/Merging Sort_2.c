#include <stdio.h>
#include <malloc.h>

int main()
{
    int A[15],B[15],C[30];
    int n,n1,n2,i,j,k,k1;

    printf("How many number in array_1 : ");
    scanf("%d",&n1);
    for(i=1;i<=n1;i++)
    {
        scanf("%d",&A[i]);
    }

    printf("How many number in array_2 : ");
    scanf("%d",&n2);
    for(j=1;j<=n2;j++)
    {
        scanf("%d",&B[j]);
    }
    printf("\nArray A : \n");
    for(i=1;i<=n1;i++)
    {
        printf("%d\n",A[i]);
    }
    printf("\nArray B : \n");
    for(j=1;j<=n2;j++)
    {
        printf("%d\n",B[j]);
    }
    n=n1+n2;

    for(k=1,i=1,j=1;k<=n;k++)
    {
        if(i>n1 || j>n2)
        {
            k1=k;
            if(i>n1)
            {
                for(k=k1;j<=n2;k++,j++)
                {
                    C[k]=B[j];
                }
            }
            else
            {
                for(k=k1;i<=n1;k++,i++)
                {
                    C[k]=A[i];
                }
            }
            break;
        }
        else
        {
            if(A[i]<B[j])//for descending
            {
                C[k]=B[j];
                j++;
            }
            else
            {
                C[k]=A[i];
                i++;
            }
        }
    }
    printf("\nSorted in descending order when Array A and B in descending order : \n");
    for(k=1;k<=n;k++)
    {
        printf("%d\n",C[k]);
    }
    return 0;
}

