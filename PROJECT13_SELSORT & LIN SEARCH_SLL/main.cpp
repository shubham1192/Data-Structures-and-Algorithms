#include <iostream>

using namespace std;
struct node
    {
        int data;
        node *nxt;
    };
    node *h=0,*list,*n,*temp,*mini;


void disp()
{
    //OUTPUT

    cout<<"\nLIST IS"<<endl;
    list=h;
    while(list!=0)
    {
        cout<<list -> data;
        cout<<"   ";
        list = list -> nxt;
    }
    cout<<endl;
}
void LS()          //LINEAR SRCH
{
    int a;
    do{
    int num,pos=0;
    cout<<"\nENTER NUMBER : ";
    cin>>num;

    list=h;        //CHECK THE DATA
    while(list->data!=num)
    {
        pos++;     //POSITION COUNTER
        list=list->nxt;
        if(list==0)//NOTHING FOUND,AT THE NXT PART OF THE LAST NODE
        {
            break;
        }
    }

    if(list==0)
    {
        cout<<"\nELEMENT NOT FOUND"<<endl;
    }
    else
        cout<<"\nNUMBER = "<<num<<", found at POSITION = "<<pos+1<<endl;
        cout<<"\nWanna continue(0/1) : ";
        cin>>a;
    }while(a!=0);
}


void selsort()
{
    temp=h;
    while(temp!=0)
    {
        mini=temp;            //take the first element's address as min.
        list=temp->nxt;       //nxt node

        while(list!=0)
        {
            if(list->data<mini->data)
            {
                mini=list;    //now min=list
            }
            list=list->nxt;   //traverse the whole thing
        }

        if(mini!=temp)
        {
            //swapping
            int x;
            x=temp->data;
            temp->data=mini->data;
            mini->data=x;
        }
        temp=temp->nxt;
    }

    //OUTPUT
    cout<<endl;
    cout<<"SORTED LIST IS "<<endl;
    list=h;
    while(list!=0)
    {
        cout<<list -> data;
        cout<<"   ";
        list = list -> nxt;
    }
    cout<<endl;
}
int main()
{
    cout<<"*************************"<<endl;
    cout<<"SHUBHAM INDER 05916412819"<<endl;
    cout<<"*************************"<<endl;
    int op;

    //IMPLEMENTATION

    while(op!=0)
    {
        n=new node;
        cout<<"\nEnter data -> "; cin>>n -> data;
        n -> nxt=0;

        if(h==0)
        {
            h=list=n;
        }
        else
        {
            list -> nxt = n;
            list=n;
        }
        cout<<"Wanna continue(0/1) : ";
        cin>>op;
    }

    disp();

    int a;
    do
    {
        cout<<"\nCHOOSE THE APPROPRIATE OPTION"<<endl;
        cout<<"\n1. LINEAR SEARCH"<<"\n2. SELECTION SORT"<<endl;
        cin>>a;
        switch(a)
        {
        case 1:
            {
                LS();
                break;
            }
        case 2:
            {
                selsort();
                break;
            }
        }
    }while(a!=0);

return 0;
}
