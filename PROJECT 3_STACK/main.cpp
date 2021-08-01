#include <iostream>
#define S 5
int top=-1,stack[S];
using namespace std;

void push(int x)
{
    if(top==S-1)
    {
        cout<<"\n\tThis is an OVERFLOW condition\t"<<endl;
    }

    else
    {
        top++;
        stack[top]=x;
    }
}

int pop()
{
    int poppedval;
    if(top==-1)
       cout<<"\n\tThis is an UNDERFLOW condition\t"<<endl;
    else
    {
        poppedval=stack[top];
        top--;
        return poppedval;
    }
}

void display()
{
    for(int i=top;i>=0;i--)
    {
        cout<<"   stack ["<<i<<"]  ->  "<<stack[i]<<endl;
    }
}
int main()
{
    int opt;

    cout<<"*************************"<<endl;
    cout<<"SHUBHAM INDER 05916412819"<<endl;
    cout<<"*************************"<<endl;

    do
    {
        cout<<"\n\n\n   Choose the appropriate option :-"<<endl;
        cout<<"\n   1. PUSH ONTO THE STACK"<<"\n   2. POP FROM THE STACK"<<endl;
        cout<<endl;
        cout<<"   ";

        cin>>opt;
        switch(opt)
        {
        case 1:
            {
                int n;
                cout<<"\n   Enter the no. : "; cin>>n;
                push(n);
                cout<<endl;
                cout<<"   STACK IS - "<<endl;
                cout<<endl;
                display();
                break;
            }
        case 2:
            {
                if(top!=-1)
                {
                    if(top!=0)
                    {
                        cout<<"\n   Popped Value :"<<pop()<<endl;
                            cout<<endl;
                        display();
                    }
                    else
                    {
                        cout<<"\n   Popped Value :"<<pop()<<endl;
                        cout<<"\n\tSTACK IS EMPTY NOW\t"<<endl;
                    }

                }

                else
                {
                    pop();

                }

            }
        }
    }while(opt!=0);

    return 0;
}
