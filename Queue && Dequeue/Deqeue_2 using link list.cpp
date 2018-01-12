
#include<iostream>
#include<stdlib.h>
#include<malloc.h>
#include<cstdio>

using  namespace std;

struct node
{
    int data;
    struct node *nxt,*pre;
};

void display();
int enqueue(int x);
int dlete();

int number;
int count=0;

struct node* front=NULL;
struct node* rear=NULL;

int enqueue(int x)
{
    int choice;
    struct node *tmp;
    tmp=(struct node*)malloc(sizeof(struct node));
    tmp->data=x;
    tmp->nxt=NULL;
    tmp->pre=NULL;

    if(++count>number)
        {cout<<"overflow\n\n";}

    else{

            if(front==NULL && rear==NULL)
            {
            front=rear=tmp;
            return 1;
            }
            else
            {
                cout<<"\nFrom which way ? 1. In TOP   2. In Tail  :  ";
                cin>>choice;
                if(choice ==1)
                {
                    front->pre=tmp;
                    tmp->nxt=front;

                    front=tmp;
                }
                else if(choice==2)
                {
                    rear->nxt=tmp;
                    tmp->pre=rear;
                    rear=tmp;
                }
                else
                {
                    cout<<"\nwrong choice\n"<<endl;
                    return -1;
                }

            }
          }
}

int main()
{
    int option,x, elem;
    cout<<"Enter size of queue : ";
    cin>>number;
    while(option!=4)
    {
        cout<<"\n1.insert   2.display   3.delete  4.exit  : ";
        cin>>option;

        switch(option)
        {
        case 1:
            cout<<"\nEnter Element :\n";
            cin>>x;
            enqueue(x);
            break;

        case 2:
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
    cout<<"\n\nShow :"<<endl;
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
    //tmp=front;
    int choice;

    if(front==NULL)
    {
        cout<<"underflow :"<<endl;
        return 1;
    }

    if(front==rear)
    {
        front=rear=NULL;
    }

    else
    {
        cout<<"\nFrom which way ? 1. From TOP   2. From Tail  :  ";
        cin>>choice;
        if(choice ==1)
        {
            front=front->nxt;
        }
        else if(choice==2)
        {
            rear=rear->pre;
            rear->nxt=NULL;
        }
        else
        {
            cout<<"\nwrong choice\n"<<endl;
            return -1;
        }

    }
    --count;
    //delete(tmp);

   display();
}

