#include <iostream>

using namespace std;

int main()
{
    struct node
    {
        int data;
        node *nxt;
    };
    node *h,*list,*n,*temp,*min;
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

    cout<<"\nLIST IS"<<endl;
    list=h;
    while(list!=0)
    {
        cout<<list -> data;
        cout<<"   ";
        list = list -> nxt;
    }
    cout<<endl;

    //SEL SORT

    temp=h;
    while(temp!=0)
    {
        min=temp;
        list=temp->nxt;
        while(list!=0)
        {
            if(list->data<min->data)
            {
                min=list;
            }
            list=list->nxt;
        }
        if(min!=temp)
        {
            int x;
            x=temp->data;
            temp->data=min->data;
            min->data=x;
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
    return 0;
}
