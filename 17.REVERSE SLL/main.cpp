#include <iostream>

using namespace std;
 struct node
    {
        int data;
        node *nxt;
    };
    node *h,*t,*n,*front,*last,*END;

void rev()
{
    last=h;

    while(last->nxt!=0)
    {
        last=last->nxt;
    }
    END=last;
    while(last!=h)
    {
        t=h;
        while(t!=last)
        {
            front=t;
            t=t->nxt;
        }
        last->nxt=front;
        last=front;
    }

    h->nxt=0;
    h=END;
    t=h;
    while(t!=0)
    {
        cout<<t -> data;
        cout<<"   ";
        t = t -> nxt;
    }
}
int main()
{
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
cout<<endl;
    rev();

    return 0;
}
