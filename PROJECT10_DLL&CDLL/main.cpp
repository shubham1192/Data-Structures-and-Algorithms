#include <iostream>

using namespace std;
struct node
{
    node *pre;
    int data;
    node *nxt;
};
node *h=0,*list,*n;

//DOUBLY LL---------------------------------------------------------------------------------------------------------------------------------------

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

    int pos,count=1; cout<<"\nEnter the specific element : "; cin>>pos;

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
    int pos,count=1; cout<<"\nEnter the specific element : "; cin>>pos;
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

//////////////////////////////////////////////////////////////////////////////////////////////////////////

void doublyLL()
{
    h=0;
    int opt;
    do
    {
        cout<<"\n--------------------------------------------------------------------"<<endl;
        cout<<"  DOUBLY LINKED LIST - CHOOSE THE APPROPRIATE OPTION/MAIN MENU-0"<<endl;
        cout<<"--------------------------------------------------------------------"<<endl;
        cout<<"\n  1. Insertion at the beginning"<<"\n  2. Insertion at the end"<<"\n  3. Insertion at a specific location"<<"\n  4. Deletion-Beginning"<<"\n  5. Deletion-End"<<"\n  6. Deletion-Specific Location"<<endl;
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
}


//CIRCULAR DLL------------------------------------------------------------------------------------------------------------------------------------


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
     int pos,count=1; cout<<"\nEnter the specific element :"; cin>>pos;
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

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void circularDLL()
{
    h=0;
    int opt;
    do
    {
        cout<<"\n--------------------------------------------------------------------"<<endl;
        cout<<"  CIRCULAR DOUBLY LINKED LIST - CHOOSE THE APPROPRIATE OPTION/MAIN MENU-0"<<endl;
        cout<<"--------------------------------------------------------------------"<<endl;
        cout<<"\n  1. Insertion at the beginning"<<"\n  2. Insertion at the end"<<"\n  3. Insertion at a specific location"<<"\n  4. Deletion-Beginning"<<"\n  5. Deletion-End"<<"\n  6. Deletion-Specific Location"<<endl;
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
}


int main()
{
    int opt;
    cout<<"*************************"<<endl;
    cout<<"SHUBHAM INDER 05916412819"<<endl;
    cout<<"*************************"<<endl;

    do
    {

        cout<<endl;
        cout<<"\n---------------------------------------"<<endl;
        cout<<"  CHOOSE THE APPROPRIATE LIST/EXIT-0"<<endl;
        cout<<"\n  1. DOUBLY LINKED LIST"<<"\n  2. CIRCULAR DOUBLY LINKED LIST"<<endl;
        cout<<"---------------------------------------"<<endl;
        cout<<"  ";

        cin>>opt;
        switch(opt)
        {
        case 1:
            {
                doublyLL();
                break;
            }
        case 2:
            {
                circularDLL();
                break;
            }

        }
    }while(opt!=0);
    return 0;
}
