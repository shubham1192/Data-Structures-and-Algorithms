#include <iostream>

using namespace std;
int first=0;
    struct node
    {
        int data;
        node *nxt;
    };
    node *head,*temp,*n;
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
    temp=head;
    while(temp!=0)
    {
        cout<<temp -> data; cout<<"   ";
        temp=temp ->nxt;
    }
}
void create()
{
    n=new node;
    cout<<"Enter data : ";
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
    cin>>pos;
                if(pos>sz()+1 || pos<=0)
                {
                    cout<<"INVALID";
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
    cout<<"ALL ELEMENTS DELETED";
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
        cout<<"INVALID"<<endl;
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
                cout<<"EMPTY";
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
                cout<<"EMPTY";
                }
                break;
            }
        case 6:
            {
                deloc();
                disp();
            }
            break;

        }

    }while(opt!=0);
    return 0;
}
