#include<iostream>
#include<stdlib.h>
#include<malloc.h>
using  namespace std;

int number;
int count=0;

struct node
{
    int data;
    struct node *nxt;
};

void display();
int enqueue(int x);

struct node* front=NULL;
struct node* rear=NULL;

int enqueue(int x)
{
    struct node *curn;


    curn=(struct node*)malloc(sizeof(struct node));
    curn->data=x;
    curn->nxt=NULL;
    ++count;

    //cout<<"eq= "<<count<<"  "<<n<<endl;

    //if(curn==NULL)
    if(count>number)
        {cout<<"overflow\n\n";}

    else{

            if(front==NULL && rear==NULL)
            {
            front=rear=curn;
            return 1;
            }
            //cout<<"jjhkj"<<endl;
            rear->nxt=curn;
            rear=curn;
          }
}

int main()
{
    int option,x;
    cout<<"how many? ";
    cin>>number;
    //cout<<"eq= "<<count<<"  "<<n<<endl;

    while(option!=3)
    {
        cout<<"\n1.insert   2.display   3.exit  :";
        cin>>option;

        switch(option)
        {
        case 1:
            cout<<"\nEnter Element :\n";
            cin>>x;
            enqueue(x);
            break;

        case 2:
            cout<<"\n\nShow :"<<endl;
            display();
            break;

        case 3:
            break;

        }
    }


}

void display()
{
    struct node *t;
    if(front==NULL)
        {cout<<"Queue is Empty\n\n";}

    else
    {
        t=front;
        while(t)
        {
            cout<<t->data<<endl;
            t=t->nxt;
        }
    }
}
