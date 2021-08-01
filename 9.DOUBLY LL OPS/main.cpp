#include <iostream>

using namespace std;
struct node
{
    node *pre;
    int data;
    node *nxt;
};
node *h=0,*list,*n;
void create1()
{
    n=new node;
    cout<<"\nEnter data : ";
    cin>>n->data;
    n->nxt=0;
    //n->pre=0;
}
void disp()
{
    list=h;
    if(list!=0)
    {
        cout<<"\nLIST IS"<<endl;
        while(list->nxt!=0)
        {
            cout<<list->data<<" ----> ";
            list=list->nxt;
        }
         cout<<list->data<<" ----> ! "<<endl;
         // CHECK THE DLL -
         //if(list->pre!=0)
         //cout<<list->pre->data<<"  ";
    }
    else
        cout<<"\nEMPTY"<<endl;
}
void in_beg()
{
    create1();
    n->nxt=h;
    n->pre=0;
    h->pre=n;
    h=n;
}
void in_end()
{
    create1();
    list=h;
    while(list->nxt!=0)
    {
        list=list->nxt;
    }
    list->nxt=n;
    n->pre=list;
}
void in_pos()
{

    int pos,count=1; cout<<"\nEnter position : "; cin>>pos;

    list=h;
    create1();
    while(list->data!=pos)
    {
        list=list->nxt;
        if(list==0)
        {
           count=0;
           break;
        }
    }
    if(count!=0)
    {

    if(list->nxt!=0)
    {
        n->nxt=list->nxt;
        n->pre=list;
        list->nxt=n;
        n->nxt->pre=n;
    }
    else if(list->nxt==0)
    {
        n->nxt=list->nxt;
        n->pre=list;
        list->nxt=n;
    }
    }
    else
        cout<<"\nINVALID"<<endl;
}
void del_beg()
{
    list=h;
    if(list->nxt!=0)
    {
        h=h->nxt;
        h->pre=0;
        delete list;
    }
    else if(list->nxt==0)
        {
            h=0;
            delete list;
        }
}
void del_end()
{
    list=h;
    while(list->nxt!=0)
    {
        list=list->nxt;
    }
    if(list==h)
    {
        h=0;
        delete list;
    }
    else
    list->pre->nxt=0;
    delete list;
}
void del_pos()
{
    int pos,count=1; cout<<"\nEnter position : "; cin>>pos;
    list=h;
    while(list->data!=pos)
    {
        list=list->nxt;
        if(list==0)
        {
            count=0;
            break;
        }
    }
    if(count==1)
    {

    if(list->nxt==0 && list!=h)
    {
    list->pre->nxt=0;
    delete list;
    }
    else if(list==h && list->nxt!=0)
    {
        list->nxt->pre=0;
        h=list->nxt;
        delete list;
    }
    else if(list==h && list->nxt==0)
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
                    create1();
                    h=n;
                    disp();
                }
                else
                {
                    in_beg();
                    disp();
                }
                break;
            }
        case 2:
            {
               if(h==0)
                {
                    create1();
                    h=n;
                    disp();
                }
                else
                {
                    in_end();
                    disp();
                }
                break;
            }
        case 3:
            {
                if(h==0)
                {
                    cout<<"\n Can't insert now";
                }
                else
                {
                    in_pos();
                    disp();
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
                    del_beg();
                    disp();
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
                    del_end();
                    disp();
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
                    del_pos();
                    disp();
                }
                break;
            }
        }

    }while(opt!=0);
    return 0;
}
