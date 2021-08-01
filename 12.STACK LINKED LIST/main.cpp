#include <iostream>

using namespace std;

struct node
{
    int data;
    node *nxt;
};
node *h=0,*list,*n,*front=0,*rear=0;

void push()
{
    n=new node;
    cout<<"Enter data -> "; cin>>n -> data;
    n->nxt=0;
    if(h==0)
    {
        h=n;
    }
    else
    {
        n->nxt=h;
        h=n;
    }
}

void pop()
{

       list=h;
       h=list->nxt;
       delete list;



}

void disp()
{
if(h!=0)
{


     list=h;
   while(list!=0)
   {
       cout<<list->data<<endl;
       list=list->nxt;
   }
}
else
    cout<<"LIST IS EMPTY"<<endl;
}

void enq()
{
    n=new node;
    cout<<"Enter data -> "; cin>>n -> data;
    n->nxt=0;
    if(front==0)
    {
        front=rear=n;
    }
    else
    {
        rear->nxt=n;
        rear=n;
    }
}


void dq()
{
    list=front;
    front=list->nxt;
    delete list;
}



void disp1()
{
    if(front!=0)
    {
        list=front;
        while(list!=0)
   {
       cout<<list->data;
       cout<<"   ";
       list=list->nxt;
   }
    }
    else
        cout<<"EMPTY";
}


int main()
{
    int opt;
    do
    {
        cout<<"\n1. STACKS"<<"\n2. QUEUES"<<endl;
        cin>>opt;
        switch(opt)
        {
        case 1:
            {
                front=0;
                int op;
                do{
            cout<<"\n1. PUSH"<<"\n2. POP"<<endl;
            cin>>op;
        switch(op)
        {
        case 1:
            {
                push();
                disp();
                break;
            }
        case 2:
            {
                if(h==0)
                {
                    cout<<"emty"<<endl;
                }
                else{
                pop();
                disp();
                }
                break;
            }
        }
    }while(op!=0);
    break;

            }

        case 2:
            {
                h=0;
                int a;
                do
                {
                    cout<<"\n1. ENQUEUE"<<"\n2. DEQUEUE"<<endl;
                    cin>>a;
                    switch(a)
                    {
                    case 1:
                        {
                            enq();
                            disp1();
                            break;
                        }
                    case 2:
                        {
                            if(front==0)
                            {
                                cout<<"EMPTY"<<endl;
                            }

                            else
                            {
                                dq();
                                disp1();
                                break;
                            }
                        }
                    }
                }while(a!=0);
                break;
            }

        }

        //int opt;

        //cin>>op;
    }while(opt!=0);
    return 0;
}
