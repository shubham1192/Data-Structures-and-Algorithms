#include <iostream>

using namespace std;
struct node
{
    int co,ex; //coeff & exponent
    node *nxt;
};
node *h1=0,*h2=0,*n1,*n2,*list1,*list2; //for 2 LLs

void poly1()
{
    char opt;
    do
    {
        n1=new node;
        cout<<endl;
        cout<<"COEFFICIENT : "; cin>>n1->co;
        cout<<endl;
        cout<<"EXPONENT : "; cin>>n1->ex;
        n1->nxt=0;
        if(h1==0)          //first time
        {
            h1=list1=n1;
        }

        else
        {
            list1->nxt=n1;
            list1=n1;
        }
        cout<<endl;
        cout<<"ADD TERM (y/n) -> "; cin>>opt;
    }while(opt=='y');
}
void disp1()
{
    list1=h1;
    while(list1!=0)
    {
        cout<<list1->co<<"x^"<<list1->ex;
        list1=list1->nxt;
        if(list1!=0)
        {
            cout<<" + ";
        }
    }
}
void poly2()
{
    char opt;
    do
    {
        n2=new node;
        cout<<endl;
        cout<<"COEFFICIENT : "; cin>>n2->co;
        cout<<endl;
        cout<<"EXPONENT : "; cin>>n2->ex;
        n2->nxt=0;
        if(h2==0)
        {
            h2=list2=n2;
        }
        else
        {
            list2->nxt=n2;
            list2=n2;
        }
        cout<<endl;
        cout<<"ADD TERM (y/n) -> "; cin>>opt;
    }while(opt=='y');
}
void disp2()
{
    list2=h2;
    while(list2!=0)
    {
        cout<<list2->co<<"x^"<<list2->ex;
        list2=list2->nxt;
        if(list2!=0)
        {
            cout<<" + ";
        }
    }
}
void add()
{
    list1=h1;
    list2=h2;
    while(list1!=0 && list2!=0)           //both need to be true
    {
        if(list1->ex == list2->ex)        //eq. expos
        {
            cout<<list1->co+list2->co<<"x^"<<list1->ex;
            list1=list1->nxt;
            list2=list2->nxt;
        }
        else if(list1->ex > list2->ex)
        {
            cout<<list1->co<<"x^"<<list1->ex;  //greater one
            list1=list1->nxt;                  //list 1 moves and list 2 stays where it was before
        }
        else
        {
            cout<<list2->co<<"x^"<<list2->ex;  //list2ex>list1ex
            list2=list2->nxt;                  //list 2 moves and list 1 stays where it was before
        }
        if(list1!=0 || list2!=0)
        {
            cout<<" + ";
        }
    }
    //for rest of the terms
    while(list1!=0)
    {
        cout<<list1->co<<"x^"<<list1->ex;
        list1=list1->nxt;
        if(list1!=0)
        {
            cout<<" + ";
        }
    }
    while(list2!=0)
    {
        cout<<list2->co<<"x^"<<list2->ex;
        list2=list2->nxt;
        if(list2!=0)
        {
            cout<<" + ";
        }
    }

}

int main()
{
    cout<<"\n\n----------------------------------"<<endl;
    cout<<"Enter polynomial 1 : "<<endl;
    poly1();
    cout<<"\nPOLYNOMIAL 1 EXPRESSION :"<<endl;
    disp1();
    cout<<endl;
    cout<<"\n\n----------------------------------"<<endl;
    cout<<"Enter polynomial 2 : "<<endl;
    poly2();
    cout<<"\nPOLYNOMIAL 2 EXPRESSION :"<<endl;
    disp2();
    cout<<endl;
    cout<<endl;
    cout<<"----------------------------------"<<endl;
    cout<<"RESULT : ";
    add();
    cout<<endl;
    cout<<endl;
    cout<<endl;

    return 0;
}
