#include <iostream>

using namespace std;
struct node
    {
        int data;
        node *nxt;
    };
    node *h,*t,*n,*Next,*curr,*pre;

void reverse()
{
    pre=0;                 //initially pre=0
    curr=Next=h;           //all pointing to h

    while(Next!=0)         //traverse until Next(nxt part of a node) comes out be 0
    {
        Next=curr->nxt;    //move ahead
        curr->nxt=pre;     //current node's nxt part=pre which is 0 for the first time
        pre=curr;
        curr=Next;         //move curr ahead(next node)
    }

    h=pre;                 //h pointing to the last node in the original list,
                           //which has become the first node in the reversed list

    //OUTPUT

    t=h;
    while(t!=0)
    {
        cout<<t -> data;
        cout<<"   ";
        t = t -> nxt;
    }
}
void nodes()
{
    cout<<endl;
    cout<<"*********************************************"<<endl;
    cout<<"ORIGINAL LINKED LIST -"<<endl;
    int count=0;

    t=h;
    while(t!=0)
    {
        cout<<t -> data;
        cout<<"   ";
        t = t -> nxt;
        count++;                 //for counting nodes
    }

    cout<<endl;
    cout<<"*********************************************"<<endl;
    cout<<endl;
    cout<<"*****************************"<<endl;
    cout<<"TOTAL NO. OF NODES = "<<count<<endl;
    cout<<"*****************************"<<endl;
}
int main()
{
    h=0;

    int op;

    //IMPLEMENTATION

    cout<<"*************************"<<endl;
    cout<<"SHUBHAM INDER 05916412819"<<endl;
    cout<<"*************************"<<endl;
    cout<<endl;
    while(op!=0)
    {
        n=new node;
    cout<<"Enter data -> "; cin>>n -> data;
    n -> nxt=0;

    if(h==0)
    {
        h=t=n;
    }
    else
    {
        t -> nxt = n;
        t=n;
    }
    cout<<"Wanna continue(0/1)"<<endl;
    cin>>op;
    }

    nodes();

    cout<<endl;

    cout<<"*********************************************"<<endl;
    cout<<"REVERSED LINKED LIST -"<<endl;
    reverse(); cout<<endl;
    cout<<"*********************************************"<<endl;
    return 0;
}
