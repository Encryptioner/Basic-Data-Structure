#include<bits/stdc++.h>

using namespace std;

int main()
{
    int i,j,L,count,com,temp;
    cin>>L;
    vector<int>array(L);
    for(i=0;i<L;i++)
    {
        cin>>array[i];
    }

    for(i=1;i<L;i++){//accepted
        for(j=L-1;j>=i;j--){
            if(array[j-1]<array[j])
                {
                count=count+1;
                temp=array[j-1];
                array[j-1]=array[j];
                array[j]=temp;
                }
                com++;
        }}
        printf("\n");
        for(i=0;i<L;i++)
        {
            cout<<array[i]<<endl;
        }
}
