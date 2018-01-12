#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
    int i,x=0,y=0,z=0;
    int t=0,o=0,p=0;
    char ch[50];
    printf("Enter 0 to terminate...\n");
    for(i=1;i<=50;i++)
    {
        printf("\nEnter inputting bracket_%d : ",i);
        cin>>ch[i];
        if(ch[i]=='0')
        {
            break;
        }
        if(ch[i]=='(' || ch[i]=='[' || ch[i]=='{')
        {
            //top=top+1;
            if(ch[i]=='(')
            {
                t++;
                x--;
            }
            if(ch[i]=='{')
            {
                o++;
                y--;
            }
            if(ch[i]=='[')
            {
                p++;
                z--;
            }
        }
        else if(ch[i]==')' || ch[i]=='}' || ch[i]==']')
        {
            //top=top-1;
            if(ch[i]==')')
            {
                t--;
                x++;
            }
            if(ch[i]=='}')
            {
                o--;
                y++;
            }
            if(ch[i]==']')
            {
                p--;
                z++;
            }
        }
        else
        {
            printf("\ninvalid input..\n");
            break;
        }
        /*if(x==1 || y==1 || z==1)
        {
            cout<<"\nyour input method is wrong in this position. Check and try later...\n";
            break;
        }*/
    }
    if(t==0 && o==0 && p==0)
    {
        printf("\nInput is correct..\n");
    }
    else
    {
        cout<<"\ninput is wrong...\n";
    }
    return 0;
}

