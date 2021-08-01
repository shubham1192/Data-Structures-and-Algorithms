#include <iostream>

using namespace std;
struct node
{
    node *pre;
    int data;
    node *nxt;
};
node *h=0,*list,*n;
void create2()
{
    n=new node;
    cout<<"\nEnter data : ";
    cin>>n->data;
}
void disp2()
{
    list=h;
    if(list!=0)
    {
        cout<<"\nLIST IS"<<endl;
        while(list->nxt!=h)
        {
            cout<<list->data<<" ----> ";
            list=list->nxt;
        }
         cout<<list->data<<" ----> ! "<<endl;
         // CHECK THE CDLL -

         //cout<<list->nxt->data<<"  ";
         //cout<<list->pre->data<<"  ";
    }
    else
        cout<<"\nEMPTY"<<endl;
}
void ins_beg()
{
    create2();
    list=h->pre;
    n->nxt=h;
    n->pre=list;
    h->pre=n;
    list->nxt=n;
    h=n;
}
void ins_end()
{
    create2();
    list=h->pre;
    n->nxt=h;
    n->pre=list;
    h->pre=n;
    list->nxt=n;
}
void ins_pos()
{
     int pos,count=1; cout<<"\nEnter position : "; cin>>pos;
     list=h;
     create2();
     while(list->data!=pos)
     {
        list=list->nxt;
        if(list==h)
        {
           count=0;
           break;
        }
     }
     if(count!=0)
     {
        n->nxt=list->nxt;
        n->pre=list;
        list->nxt=n;
        n->nxt->pre=n;
    }
     else
        cout<<"\nINVALID"<<endl;
}
void delt_beg()
{
    if(h->pre==h)
    {
        list=h;
        h=0;
        delete list;
    }
    else
    {
        list=h;
        h->pre->nxt=h->nxt;
        h->nxt->pre=h->pre;
        h=h->nxt;
        delete list;
    }
}
void delt_end()
{
    if(h->pre==h)
    {
        list=h;
        h=0;
        delete list;
    }
    else
    {
        list=h->pre;
        h->pre=list->pre;
        list->pre->nxt=h;
        delete list;
    }
}
void delt_pos()
{
     int pos,count=1; cout<<"\nEnter position : "; cin>>pos;
     list=h;
     while(list->data!=pos)
     {
        list=list->nxt;
        if(list==h)
        {
           count=0;
           break;
        }
     }
     if(count!=0)
     {
         if(list==h && list->pre!=h)
         {
             h->pre->nxt=h->nxt;
             h->nxt->pre=h->pre;
             h=h->nxt;
             delete list;
         }
         else if(list->pre==h && list==h)
         {
             h=0;
             delete list;
         }
         else
         {
            list->pre->nxt=list->nxt;
            list->nxt->pre=list->pre;
            delete list;
         }
     }
     else
        cout<<"\nINVALID"<<endl;
}
int main()
{
    int opt;
    do
    {
        cout<<"\n1. Beginning"<<"\n2. End"<<"\n3. Specified location"<<"\n4. Deletion-Beginning"<<"\n5. Deletion-End"<<"\n6. Deletion-Location"<<endl;
        cin>>opt;
        switch(opt)
        {
        case 1:
            {
                if(h==0)
                {
                    create2();
                    h=n;
                    n->nxt=h;
                    n->pre=h;
                    disp2();

                }
                else
                {
                    ins_beg();
                    disp2();
                }
                break;
            }
        case 2:
            {
               if(h==0)
                {
                    create2();
                    h=n;
                    n->nxt=h;
                    n->pre=h;
                    disp2();
                }
                else
                {
                    ins_end();
                    disp2();
                }
                break;
            }
        case 3:
            {
                if(h==0)
                {
                    cout<<"\n Can't insert now"<<endl;
                }
                else
                {
                    ins_pos();
                    disp2();
                }
                break;
            }

        case 4:
            {
                if(h==0)
                {
                    cout<<"EMPTY";
                }
                else
                {
                    delt_beg();
                    disp2();
                }
                break;
            }
        case 5:
            {
                if(h==0)
                {
                    cout<<"EMPTY";
                }
                else
                {
                    delt_end();
                    disp2();

                }
                break;
            }
        case 6:
            {
                if(h==0)
                {
                    cout<<"EMPTY";
                }
                else
                {
                    delt_pos();
                    disp2();
                }
                break;
            }
        }

    }while(opt!=0);
    return 0;
}
