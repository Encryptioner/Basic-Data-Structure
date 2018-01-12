#include<iostream>
using namespace std;
int binary_search(int a[ ],int tar)
{
    int first=1,mid,target;
    int last=10;
    while(first<=last)
    {
        mid=first+((first-last)/2);
        cout<<mid<<endl;
    }
    if(a[mid]==target)
        return mid;
    else if(a[mid]<target)
        first=mid+1;
    else
        last=mid-1;
}
int main()
{
    int a[10];
    int i,b,data;
    cout<<"How many numbers you want to insert:";
    cin>>b;
    cout<<"Enter the data for search:";
    cin>>data;
    for(i=0;i<b;i++)
    {
        cin>>a[i];
    }
    //binary_search( a[],data);

}
