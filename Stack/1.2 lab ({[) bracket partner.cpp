#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
    int i,x=0;
    int a=0,b=0,c=0;
    //int x=0,y=0,z=0,m=0,n=0,counter=0;
    int t=0,o=0,p=0;
    char ch[50];
    printf("Enter 0 to terminate...\n");
    for(i=1;i<=50;i++)
    {
        printf("\nEnter inputting bracket_%d : ",i);
        cin>>ch[i];
        //counter++;
        if(ch[i]=='0')
        {
            break;
        }
        if(ch[i]=='(' || ch[i]=='[' || ch[i]=='{')
        {
            if(ch[i]=='(')
            {
                t++;
                a++;
            }
            if(ch[i]=='{')
            {
                o++;
                b++;
                if(a>0)
                {
                    x=1;
                }
            }
            if(ch[i]=='[')
            {
                p++;
                c++;
                if(a>0 || b>0)
                {
                    x=1;
                }
            }
        }
        else if(ch[i]==')' || ch[i]=='}' || ch[i]==']')
        {
            //top=top-1;
            if(ch[i]==')')
            {
                t--;
                if(a==0)
                {
                    x=1;
                }
            }
            if(ch[i]=='}')
            {
                o--;
                if(b==0)
                {
                    x=1;
                }
            }
            if(ch[i]==']')
            {
                p--;
                if(c==0)
                {
                    x=1;
                }
            }
        }
        else
        {
            printf("\n\ninvalid input..\n");
            x=1;
            break;
        }
    }
    if((i-1)%2!=0)
    {
        cout<<"\n\ninput is wrong...\n\n";
    }
    //if(x==1 || y==1 || z==1 || m==1 || n==1)
    else if(x==1)
    {
        cout<<"\n\ninput is wrong...\n\n";
    }
    else if(t==0 && o==0 && p==0)
    {
        printf("\n\nInput is correct..\n\n");
    }
    else
    {
        cout<<"\n\ninput is wrong...\n\n";
    }
    return 0;
}

