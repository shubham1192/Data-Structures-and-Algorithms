#include <iostream>

using namespace std;

int main()
{
    struct node
    {
        int data;
        node *nxt;
    };
    node *h,*list,*n;
    h=0;

    int op;

    //IMPLEMENTATION

    while(op!=0)
    {
        n=new node;
    cout<<"Enter data -> "; cin>>n -> data;
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
    cout<<"Wanna continue(0/1)"<<endl;
    cin>>op;
    }

    //OUTPUT

    list=h;
    while(list!=0)
    {
        cout<<list -> data;
        cout<<"   ";
        list = list -> nxt;
    }
    cout<<endl;
    //LINEAR SEARCH
    int a;
    do{
    int num,pos=0;
    cout<<"\nENTER NUMBER : ";
    cin>>num;
    list=h;
    while(list->data!=num)
    {
        pos++;
        list=list->nxt;
        if(list==0)
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
         cout<<"\nWanna continue(0/1)"<<endl;
         cin>>a;
    }while(a!=0);

    return 0;
}
