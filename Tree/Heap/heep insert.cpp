#include<iostream>
using namespace std;

int a[100],b[100];
int n,i;
void display();
void insert(int data,int num);
int main()
{
    int p;
    n=1;
    while(1)
    {
    cout<<"Input values or 0 to terminate: ";
    cin>>p;
    if(p==0)
    {
        break;
    }
    else
    {
        insert(p,n);
        n=n+1;
    }

    }
     cout<<"\nDisplay Max Heep: \n\n";
     display();

     cout<<"\nAfter delete: "<<endl;
     for(i=2;i<n;i++)
         b[i-1]=a[i];
         n=n-1;
     for(i=1;i<n;i++)
     insert(b[i],i);
    display();



}


void insert(int data,int num)
{
   int par;
   while (num>1)
   {
       par=num/2;
       if(data<=a[par])
       {
           a[num]=data;
           return;
       }
        a[num]=a[par];
        num=par;

   }

    a[1]=data;

}

void display()
{
    int i;
    if(n==1)
    {
        cout<<"Heap is empty ";
        return;
    }
   else
    {
   for(i=1;i<n;i++)
    {
        cout<<"a("<<i<<") = "<<a[i]<<endl;
    }
   }
}
