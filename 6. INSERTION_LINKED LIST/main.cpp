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
void disp()
{
    temp=head;
    while(temp!=0)
    {
        cout<<temp -> data; cout<<"   ";
        temp=temp ->nxt;
    }
}
int main()
{

    int opt;
    do
    {
        cout<<"\n1. Beginning"<<"\n2. End"<<"\n3. Specified location"<<endl;
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

            }

        }

    }while(opt!=0);
    return 0;
}
