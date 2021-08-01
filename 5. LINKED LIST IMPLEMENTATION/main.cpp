#include <iostream>

using namespace std;

int main()
{
    struct node
    {
        int data;
        node *nxt;
    };
    node *h,*t,*n;
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

    //OUTPUT

    t=h;
    while(t!=0)
    {
        cout<<t -> data;
        cout<<"   ";
        t = t -> nxt;
    }

    return 0;
}
