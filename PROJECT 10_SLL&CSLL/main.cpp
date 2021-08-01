#include <iostream>

using namespace std;


    int first=0;
    struct node
    {
        int data;
        node *nxt;
    };
    node *head,*temp,*n,*h=0,*list;

//SINGLE LL----------------------------------------------------------------------

int sz()
{
    int coun=0;
    temp=head;
    while(temp!=0)
    {
        temp=temp->nxt;
        coun++;
    }
    return coun;
}
void disp()
{
    if(head!=0){
    temp=head;
    cout<<endl;
    cout<<"  LIST IS -"<<endl;
    cout<<"  ";
    while(temp!=0)

    {
        cout<<temp -> data; cout<<" ----> ";
        temp=temp ->nxt;
    }
    cout<<"!";
    cout<<endl;
    }
}
void create()
{
    n=new node;
    cout<<"\n  Enter data : ";

    cin>>n -> data;
    n -> nxt=0;
}
void beg()
{
    create();
    n ->nxt=head;
    head=n;
}
void at_end()
{
    create();
    temp=head;
    while(temp -> nxt!=0)
    {
        temp=temp ->nxt;
    }
    temp ->nxt=n;
}
void loc()
{
    int i=2,pos;
    cout<<"  Enter position : ";
    cin>>pos;
                if(pos>sz()+1 || pos<=0)
                {
                    cout<<"\n  INVALID";
                    cout<<endl;
                }
                else if(pos==1){
                    beg();
                    first++;
                    }
                else if(pos==sz()+1){
                    at_end();
                    }
                    else
                    {
                        create();
                        temp=head;
                        while(i<pos)
                        {
                            temp=temp->nxt;
                            i++;
                        }
                        n->nxt=temp->nxt;
                        temp->nxt=n;
                    }

                }
void delbeg()
{
if(sz()==1)
{   temp=head;
    head=head->nxt;
    delete temp;
    cout<<"\n  ALL ELEMENTS DELETED";
    cout<<endl;
    first=0;
}
else{
     temp=head;
     head=head->nxt;
     delete temp;
}
}
void delend()
{
    node *prev;
    temp=head;
    while(temp->nxt!=0)
    {
        prev=temp;
        temp=temp->nxt;
    }
    prev->nxt=0;
    delete temp;

}
void deloc()
{
    int loc;
    cout<<"  Enter position : ";
    cin>>loc;
    //temp=head;
    //node *prev;
    //while(temp->data!=loc)
    //{
      //  prev=temp;
        //temp=temp->nxt;
    //}
    //prev->nxt=temp->nxt;
    //delete temp;
    //}
    //else
      //  delbeg();
      if(loc<=0 || loc>sz())
        cout<<"\n  INVALID"<<endl;
    else if(loc==1)
        delbeg();
    else if(loc==sz())
        delend();
    else
    {
        int i=1;
        node *target;
        temp=head;
        while(i<loc-1)
        {
            temp=temp->nxt;
            i++;
        }
        target=temp->nxt;
        temp->nxt=target->nxt;
        delete target;
    }
}


void singleLL()
{
    h=0,first=0;
    int opt;
    do
    {
        cout<<"\n--------------------------------------------------------------------"<<endl;
        cout<<"  SINGLE LINKED LIST - CHOOSE THE APPROPRIATE OPTION/MAIN MENU-0"<<endl;
        cout<<"--------------------------------------------------------------------"<<endl;
        cout<<"\n  1. Insertion at the beginning"<<"\n  2. Insertion at the end"<<"\n  3. Insertion at a specific location"<<"\n  4. Deletion-Beginning"<<"\n  5. Deletion-End"<<"\n  6. Deletion-Specific Location"<<endl;
        cout<<"  ";
        cin>>opt;
        switch(opt)
        {
        case 1:
            {
                if(first==0)
                {
                    create();
                    head=temp=n;
                    first++;
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
                if(first==0)
                {
                    create();
                    head=temp=n;
                    first++;
                    disp();
                }
                else
                {
                    at_end();
                    disp();
                    //cout<<sz();
                }
                break;
            }
        case 3:
            {

                loc();
                disp();
                break;

            }
        case 4:
            {
                if(sz()>=1)
                {
                delbeg();
                disp();
                }
                else
                cout<<"\n  EMPTY"<<endl;
                //cout<<sz();
                //cout<<first;
                break;
            }
        case 5:
            {
                if(sz()>1)
                {
                delend();
                disp();
                }
                else if(sz()==1)
                {
                    delbeg();
                }
                else{
                cout<<"\n  EMPTY"<<endl;
                }
                break;
            }
        case 6:
            {
                deloc();
                disp();
            }
            break;
        case 7:
            {
                disp();
                break;
            }

        }

    }while(opt!=0);
}


//CIRCULAR LL----------------------------------------------------------------------


void create2()
{
    n=new node;
    cout<<"\n  Enter data : ";
    cin>>n->data;
}
void disp2()
{
    //node *list;
    list=h;
    if(list!=0)
        {
            cout<<endl;
            cout<<"  LIST IS -"<<endl;
            cout<<"  ";
            while(list->nxt!=h)
            {
                cout<<list->data<<" ----> ";
                list=list->nxt;
            }
                cout<<list->data<<" ---->  !"<<endl;;
                // CHECK THE CSLL -
                // cout<<list->nxt->data<<"  ";
        }
    else
    cout<<"\n  LIST IS EMPTY NOW"<<endl;

}
void beg2()
{
    create2();
    list=h;
    while(list->nxt!=h)
        list=list->nxt;
    n->nxt=h;

    list->nxt=n;

    h=n;
}
void end()
{
    create2();
    list=h;
    while(list->nxt!=h)
        list=list->nxt;

    n->nxt=h;
    list->nxt=n;
}
void pos()
{
    int p,count=1; //count-input element is not there
    cout<<"  Enter the specific element : ";
    cin>>p;
    list=h;
    create2();
    while(list->data!=p)
    {
         list=list->nxt;
         if(list==h) //whole traversal done,comes back at the first pos
         {
             count=0;
             break;
         }
    }

    if(count==1){
    n->nxt=list->nxt;
    list->nxt=n;}

    else
        cout<<"\n  INVALID POSITION"<<endl;
}
void beg_del()
{
    list=h;
    while(list->nxt!=h)
    {
        list=list->nxt;
    }
    temp=h;
    if(list->nxt==list)//if only one element
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
    if(temp->nxt==temp)//one element
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
    cout<<"  Enter the specific element : ";
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

    if(temp==h && temp->nxt!=h)//deletion of the very first element when there
    {                          //are other elements also
       list=h;                 //like del. at beg
       while(list->nxt!=h)
       {
           list=list->nxt;
       }
        list->nxt=h->nxt;
        h=list->nxt;
        delete temp;
    }
    else if(temp==h && temp->nxt==h)//del when there is only one element
    {
        h=0;
        delete temp;
    }
    else
    list->nxt=temp->nxt;
    delete temp;
    }
    else
        cout<<"\n  INVALID"<<endl;
}


circularSLL()
{
    head=0;
    int opt;
    do
    {
        cout<<"\n----------------------------------------------------------------------------"<<endl;
        cout<<"  CIRCULAR SINGLE LINKED LIST - CHOOSE THE APPROPRIATE OPTION/MAIN MENU-0"<<endl;
        cout<<"----------------------------------------------------------------------------"<<endl;
        cout<<"\n  1. Insertion at the beginning"<<"\n  2. Insertion at the end"<<"\n  3. Insertion at a specific location"<<"\n  4. Deletion-Beginning"<<"\n  5. Deletion-End"<<"\n  6. Deletion-Specific Location"<<endl;
        cout<<"  ";
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
                    disp2();
                }
                else
                {
                    beg2();
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
                    disp2();
                }
                else
                {
                    end();
                    disp2();
                }
                break;
            }
        case 3:
            {
                if(h==0)
                {
                    cout<<"\n  Can't insert now"<<endl;
                }
                else
                {
                    pos();
                    disp2();
                }
                break;
            }
        case 4:
            {
                if(h==0)
                {
                    cout<<"\n  EMPTY"<<endl;
                }
                else
                {
                    beg_del();
                    disp2();
                }
                break;
            }
        case 5:
            {
                if(h==0)
                {
                    cout<<"\n  EMPTY"<<endl;
                }
                else
                {
                    end_del();
                    disp2();
                }
                break;
            }
        case 6:
            {
                if(h==0)
                {
                    cout<<"\n  EMPTY"<<endl;
                }
                else
                {
                    loc_del();
                    disp2();
                }
                break;
            }
        case 7:
            {
                disp2();
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
        cout<<"\n  1. SINGLE LINKED LIST"<<"\n  2. CIRCULAR SINGLE LINKED LIST"<<endl;
        cout<<"---------------------------------------"<<endl;
        cout<<"  ";

        cin>>opt;
        switch(opt)
        {
        case 1:
            {
                singleLL();
                break;
            }
        case 2:
            {
                circularSLL();
                break;
            }

        }
    }while(opt!=0);

    return 0;
}
