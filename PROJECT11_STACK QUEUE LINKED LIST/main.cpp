#include <iostream>

using namespace std;

struct node
{
    int data;
    node *nxt;
};
node *h=0,*list,*n,*front=0,*rear=0;

/////////STACKS/////////

void push()
{
    n=new node;
    cout<<"Enter data -> "; cin>>n -> data;
    n->nxt=0;
    if(h==0)     //for the first time
    {
        h=n;
    }
    else
    {
        n->nxt=h; //INSERTION AT BEG
        h=n;
    }
}

void pop()
{
       list=h;   //DEL AT BEG
       h=list->nxt;
       delete list;
}

void disp()
{
if(h!=0)
{

     cout<<"\n  STACK is :"<<endl;
     list=h;
     while(list!=0)
    {
       cout<<"  "<<list->data<<endl;
       //cout<<endl;
       list=list->nxt;
    }
}
else   //h=0
    cout<<"\n  STACK IS EMPTY"<<endl;
    cout<<endl;
}


/////////QUEUES/////////

void enq()
{
    n=new node;
    cout<<"Enter data -> "; cin>>n -> data;
    n->nxt=0;

    if(front==0)       //first time
    {
        front=rear=n;   //pointing to same thing
    }
    else
    {                   //IN QUEUES- INSERTION =>end(rear)
        rear->nxt=n;
        rear=n;         //assign rear to new node
    }
}

void dq()
{
    list=front;         //IN QUEUES- DEL =>front
    front=list->nxt;    //assign front to the nxt node
    delete list;
}

void disp1()
{
    if(front!=0)
    {
     cout<<"\n  QUEUE IS "<<endl;
     list=front;
     while(list!=0)
      {
       cout<<"  "<<list->data;
       cout<<" ";
       list=list->nxt;
      }
      cout<<endl;
    }
    else
        cout<<"\n  QUEUE IS EMPTY"<<endl;
        cout<<endl;
}

int main()
{
    int opt;
    cout<<"*************************"<<endl;
    cout<<"SHUBHAM INDER 05916412819"<<endl;
    cout<<"*************************"<<endl;

    do
    {
        h=0,front=0;
        cout<<"\nCHOOSE THE APPROPRIATE OPTION. EXIT-0"<<endl;
        cout<<"\n1. STACKS"<<"\n2. QUEUES"<<endl;
        cin>>opt;
        switch(opt)
        {
        case 1:
            {
                cout<<"\nCHOOSE THE APPROPRIATE OPTION. MAIN MENU-0"<<endl;
                front=0;
                int op;
                do{
                    cout<<"-------------------";
                    cout<<"\n1. PUSH"<<"\n2. POP"<<endl;
                    cout<<"-------------------";
                    cout<<endl;
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
                                    cout<<"\n  STACK IS EMPTY"<<endl;
                                    cout<<endl;
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
                cout<<"\nCHOOSE THE APPROPRIATE OPTION. MAIN MENU-0"<<endl;
                do
                {
                    cout<<"-------------------";
                    cout<<"\n1. ENQUEUE"<<"\n2. DEQUEUE"<<endl;
                    cout<<"-------------------";
                    cout<<endl;
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
                                cout<<"\n  QUEUE IS EMPTY"<<endl;
                                cout<<endl;
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

    }while(opt!=0);
    return 0;
}
