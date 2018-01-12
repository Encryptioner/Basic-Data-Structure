#include<iostream>
#include<stdlib.h>
#include<malloc.h>
#include<cstdio>
using  namespace std;

struct node
{
    int data;
    struct node *nxt;
};

void display();
int enqueue(int x);
int dlete();

struct node* front=NULL;
struct node* rear=NULL;

int enqueue(int x)
{
    struct node *tmp;
    tmp=(struct node*)malloc(sizeof(struct node));
    tmp->data=x;
    tmp->nxt=NULL;

    if(tmp==NULL)
        {cout<<"overflow\n\n";}

    else{

            if(front==NULL && rear==NULL)
           {
            front=rear=tmp;
            return 1;
            }

            rear->nxt=tmp;
            rear=tmp;
          }
}

int main()
{
    int option,x, elem;
    while(option!=4)
    {
        cout<<"\n1.insert   2.display   3.delete  4.exit  :";
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
            dlete();
            //if(x!=-1)
            //cout<<"deleted :"<<x;
            break;

        case 4:
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

int dlete()
{
    struct node *tmp;
    tmp=front;
    if(front==NULL)
    {
        cout<<"underflow :"<<endl;
        return -1;
    }

    if(front==rear)
    {
        front=rear=NULL;
    }

    else
    {
        front=front->nxt;
    }

    delete(tmp);

   display();
}
