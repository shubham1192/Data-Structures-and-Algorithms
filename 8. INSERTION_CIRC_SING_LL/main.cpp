#include <iostream>

using namespace std;
struct node
{
    int data;
    node *nxt;
};
node *h=0,*n,*list,*temp;
void create()
{
    n=new node;
    cin>>n->data;
}
void disp()
{
    //node *list;
    list=h;
    if(list!=0)
        {
            while(list->nxt!=h)
            {
                cout<<list->data<<"  ";
                list=list->nxt;
            }
                cout<<list->data<<"  ";
                // CHECK THE CSLL -
                // cout<<list->nxt->data<<"  ";
        }
    else
    cout<<"LIST IS EMPTY NOW"<<endl;

}
void beg()
{
    create();
    list=h;
    while(list->nxt!=h)
        list=list->nxt;
    n->nxt=h;

    list->nxt=n;

    h=n;
}
void end()
{
    create();
    list=h;
    while(list->nxt!=h)
        list=list->nxt;

    n->nxt=h;
    list->nxt=n;
}
void pos()
{
    int p,count=1;
    cin>>p;
    list=h;
    create();
    while(list->data!=p)
    {
         list=list->nxt;
         if(list==h)
         {
             count=0;
             break;
         }
    }
if(count==1){
    n->nxt=list->nxt;
    list->nxt=n;}
    else
        cout<<"INVALID POSITION";
}
void beg_del()
{
    list=h;
    while(list->nxt!=h)
    {
        list=list->nxt;
    }
    temp=h;
    if(list->nxt==list)
    {
        temp=list;
        h=0;
        delete temp;

    }
    else{
    list->nxt=h->nxt;

    h=list->nxt;
    delete temp;}
}
void end_del()
{
    temp=h;
    while(temp->nxt!=h)
    {
        list=temp;
        temp=temp->nxt;
    }
    if(temp->nxt==temp)
    {
        h=0;
        delete temp;
    }
    else
    list->nxt=h;
    delete temp;
}
void loc_del()
{
    int p,count=1;
    cin>>p;

    temp=h;
    while(temp->data!=p)
    {
        list=temp;
        temp=temp->nxt;
        if(temp==h)
           {
               count=0;
               break;
           }
    }
    if(count==1)
    {

    if(temp==h && temp->nxt!=h)
    {
       list=h;
       while(list->nxt!=h)
       {
           list=list->nxt;

       }
        list->nxt=h->nxt;
        h=list->nxt;
        delete temp;
    }
    else if(temp==h && temp->nxt==h)
    {
        h=0;
        delete temp;
    }
    else
    list->nxt=temp->nxt;
    delete temp;
    }
    else
        cout<<"INVALID"<<endl;
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
                    n=new node;
                    cin>>n->data;
                    h=n;
                    n->nxt=h;
                    disp();
                }
                else
                {
                    beg();
                    disp();
                }
                break;
            }
        case 2:
            {
                if(h==0)
                {
                    n=new node;
                    cin>>n->data;
                    h=n;
                    n->nxt=h;
                    disp();
                }
                else
                {
                    end();
                    disp();
                }
                break;
            }
        case 3:
            {
                if(h==0)
                {
                    cout<<"Can't"<<endl;
                }
                else
                {
                    pos();
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
                    beg_del();
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
                    end_del();
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
                    loc_del();
                    disp();
                }
                break;
            }
        }

    }while(opt!=0);
    return 0;
}

