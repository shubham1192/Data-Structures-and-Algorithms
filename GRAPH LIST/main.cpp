#include <iostream>

using namespace std;
struct node
{
    int info;
    node *nxt;
    node *pre;
};

node *h; node *n; node *temp1;node *temp;node *t;

int main()
{
    cout<<"*************************"<<endl;
    cout<<"SHUBHAM INDER 05916412819"<<endl;
    cout<<"*************************"<<endl;
    int x,opt;
    cout<<"\nVertices : "; cin>>x;
    n=new node;
    h=temp=t=temp1=n;
    n->info=1;
    n->nxt=0;
    n->pre=0;

    for(int i=2;i<=x;i++)
    {
        n=new node;
        n->nxt=0;
        n->pre=0;
        n->info=i;
        temp->pre=n;
        temp=n;
    }


    int j;
    for(int i=1;i<=x;i++)
    {
        for(j=i;j<=x;j++)
        {
            cout<<"Edge b/w "<<i<<" & "<<j<<" : ";
            cin>>opt;
            if(opt==1)
            {
                n=new node;
                n->nxt=0;
                n->pre=0;
                n->info=j;
                while(temp1->nxt!=0)
                {
                    temp1=temp1->nxt;
                }

                temp1->nxt=n;


                temp=h;
                while(temp->info!=j)
                {
                    temp=temp->pre;
                }

                n=new node;
                n->nxt=0;
                n->pre=0;
                n->info=i;
                while(temp->nxt!=0)
                {
                    temp=temp->nxt;
                }
                temp->nxt=n;
            }
        }
        t=t->pre;
        temp1=t;
    }
    cout<<endl;
                temp=h,temp1=h->nxt;
                while(temp!=0)
                {
                    cout<<temp->info;
                    temp=temp->pre;
                    while(temp1!=0)
                    {
                        cout<<"  "<<temp1->info;
                        temp1=temp1->nxt;
                    }
                    temp1=temp->nxt;
                    cout<<endl;
                }



    return 0;
}
