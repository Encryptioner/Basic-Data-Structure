

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

      int preorder(struct tree *node);
      int inorder(struct tree *node);
      int postorder(struct tree *node);
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
          int i,n=0;
          int a,b[1000];
          char ch;
          struct tree *par,*root;
          for(i=0; ;i++)
          {
              cin>>a;
              if(a==-1)
                break;
              else
                b[i]=a;
              n++;
          }
          par='\0';
          for(i=0;i<n;i++)
          {
                  a=b[i];
                  par=insertion(par,a);

          }
          cout<<"\n\npreorder\n";
          preorder(par);
          cout<<"\n\nin order:\n";
          inorder(par);
          cout<<"\n\npost order:\n";
          postorder(par);
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

      int inorder(struct tree *node)
    {
        if(node=='\0')
        return 0;

        else
        {
            inorder(node->lc);
            cout<<"\n\n"<<node->data;
            inorder(node->rc);

        }

    }

      int postorder(struct tree *node)
    {
        if(node=='\0')
        return 0;

        else
        {

            postorder(node->lc);
            postorder(node->rc);
            cout<<"\n\n"<<node->data;
        }

    }


