
    #include<iostream>
    #include<stdio.h>
    #include<stdlib.h>
    #include<ctype.h>
    using namespace std;

    struct tree
    {
        int data;
        struct tree* lc;
        struct tree*rc;

    };

    struct tree* gp='\0';
    static int x=0;
      int preorder(struct tree *node);
      struct tree* sear(struct tree *node,int s);
      struct tree* del_data(struct tree *tn);
      struct tree* insertion(struct tree* par,int data)
      {
          static struct tree* root;
          struct tree *nn;
          if(par=='\0')
          {
              nn=(struct tree*)malloc(sizeof(struct tree));
              nn->data=data;
              nn->lc='\0';
              nn->rc='\0';
              par=nn;
              root=par;

          }
          else
          {
              if(data<par->data)
              {
                  if(par->lc=='\0')
                  {
                      nn=(struct tree*)malloc(sizeof(struct tree));
                      nn->data=data;
                      nn->lc='\0';
                      nn->rc='\0';
                      par->lc=nn;
                  }
                  else
                    insertion(par->lc,data);
              }
              else
              {
                  if(par->rc=='\0')
                  {
                       nn=(struct tree*)malloc(sizeof(struct tree));
                      nn->data=data;
                      nn->lc='\0';
                      nn->rc='\0';
                      par->rc=nn;

                  }
                  else
                    insertion(par->rc,data);
              }
          }
          return root;

      }
      int main()
      {
          int s;
          int a;
          char ch;
          struct tree *par,*root,*tn;
          par='\0';
          while(1)
          {
              cout<<"ENTER DATA(y/n):";
              cin>>ch;
              if(ch=='y')
              {
                  cout<<"data:";
                  cin>>a;
                  par=insertion(par,a);
              }
                else
                    break;
          }

          cout<<"\npreorder:\n";
          preorder(par);

          cout<<"\nsearch data to delete\n";
          cin>>s;
          tn=sear(par,s);
          if(tn==NULL)
            cout<<"data not found";
            else if(tn==par && (tn->lc==NULL && tn->rc==NULL))
                cout<<"\ndata should not be deleted as this is the root and the only data";
          else
          {del_data(tn);
          cout<<"\npreorder:\n";
          preorder(par);}
      }

        struct tree* sear(struct tree *node,int s)
    {
        struct tree *nn;
        nn=NULL;
        if(node=='\0')
        return 0;

        else
        {

            if(node->data==s)
                {cout<<"found";
                nn=node;
                return nn ;

                }
                if(node->data>s)

                {
                    gp=node;
                    sear(node->lc,s);
                }
                else
            {
                gp=node;
                sear(node->rc,s);
            }
        }

    }
    struct tree* del_data(struct tree *tn)
    {
        struct tree *succ,*par;
        if(tn->lc == '\0' && tn->rc=='\0')
        {
            if(gp=='\0')
                tn='\0';
            else
            {
                if(gp->lc==tn)
                gp->lc='\0';
                else
                    gp->rc='\0';
            }

        }
        else if((tn->lc==NULL && tn->rc!=NULL)   ||  (tn->lc!=NULL && tn->rc=='\0') )
        {
            if(tn->lc==NULL)
                {tn->data=tn->rc->data;
                 tn->rc=NULL;}
            else
               {
                tn->data=tn->lc->data;
                tn->lc=NULL;
               }
        }
        else
        {
            succ=tn->rc;
            par=tn;
            while(succ->lc!=NULL)
            {
                par=succ;
                succ=succ->lc;
            }

             if(tn==par)
            {
                par->data=succ->data;
                par->rc=NULL;
            }
            else if(succ->rc==NULL)
           {
            tn->data=succ->data;
            par->lc=NULL;}
            else
            {
                tn->data=succ->data;
                par->lc=succ->rc;
            }

        }

    }
      int preorder(struct tree *node)
    {
        if(node=='\0')
        return 0;

        else
        {
            cout<<"\n\n"<<node->data;
            preorder(node->lc);
            preorder(node->rc);
        }

    }


