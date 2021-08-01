#include <iostream>
#define S 5
int queue[S],front=-1,rear=-1;
using namespace std;
void disp()
{
    cout<<"\n   QUEUE is -"<<endl;
    cout<<endl;
    cout<<"   ";
    for(int i=front;i<rear;i++)
        cout<<queue[i]<<" <-- ";
    cout<<queue[rear];
}


int enq(int x)
{
    if(front==-1 && rear==-1)
    {
        front=rear=0;
        queue[rear]=x;
    }
    else{
        rear++;
        queue[rear]=x;
        if(rear==S-1){
            cout<<"\n\n\tQUEUE IS NOW FULL";
            cout<<endl;
            cout<<endl;

        }

    }
}
void dq()
{
    if(front==-1 && rear==-1)
        cout<<"\n\n\tQUEUE IS EMPTY";
    else if(front==rear)
    {
        cout<<"\n\tDELETED NUMBER = "<<queue[front]<<endl;
        front=rear=-1;

        cout<<"\n\tALL ELEMENTS DELETED,QUEUE IS EMPTY"<<endl;
    }
    else
    {
        cout<<"\n\tDELETED NUMBER = "<<queue[front]<<endl;

        front++;
        disp();
    }
}


int main()
{
    int n,opt;

    cout<<"*************************"<<endl;
    cout<<"SHUBHAM INDER 05916412819"<<endl;
    cout<<"*************************"<<endl;

    do
    {
        cout<<"\n\n\n---------------------------------------------"<<endl;
        cout<<"   Choose the appropriate option :-"<<endl;
        cout<<"\n   1. ENQUEUE"<<"\n   2. DEQUEUE"<<endl;
        cout<<"---------------------------------------------"<<endl;
        cout<<endl;
        cout<<"   OPTION : ";
        cin>>opt;
        switch(opt)
        {
        case 1:
            {
                if(rear==S-1)
                {
                    cout<<"\n\tQUEUE IS FULL, CAN'T INSERT NOW"<<endl;
                }
                else{
                cout<<"\n   Enter number for insertion : "; cin>>n;

                enq(n);
                disp();}
                break;
            }



        case 2:
            {
                dq();

            }
        }
    }while(opt!=0);
    return 0;
}
