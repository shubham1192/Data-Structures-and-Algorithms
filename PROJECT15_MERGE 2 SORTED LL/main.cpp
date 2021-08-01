#include <iostream>

using namespace std;
struct node
    {
        int data;
        node *nxt;
    };
    node *h1=0,*h2=0,*h3,*list,*list1,*list2,*list3,*n1,*n2,*temp,*mini;

node* selsort(node* head)     //for sorting,if i/p is not sorted
{
    temp=head;
    while(temp!=0)            //until there's no node
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
    list=head;
    while(list!=0)
    {
        cout<<list -> data;
        cout<<"   ";
        list = list -> nxt;
    }
    cout<<endl;
}

//LIST 1

void list_1()
{
    int op=1;
    while(op!=0)
    {
        n1=new node;
        cout<<"\nEnter data -> "; cin>>n1 -> data;
        n1 -> nxt=0;

        if(h1==0)
        {
            h1=list=n1;
        }
        else
        {
            list -> nxt = n1;
            list=n1;
        }
        cout<<"Wanna continue(0/1) : ";
        cin>>op;
    }
    selsort(h1);
}

//LIST 2

void list_2()
{
    int op=1;
    while(op!=0)
    {
        n2=new node;
        cout<<"\nEnter data -> "; cin>>n2 -> data;
        n2 -> nxt=0;

        if(h2==0)
        {
            h2=list=n2;
        }
        else
        {
            list -> nxt = n2;
            list=n2;
        }
        cout<<"Wanna continue(0/1) : ";
        cin>>op;
    }
    selsort(h2);
}

//MERGE AND SORT

void merge()
{
    temp=new node;      //a temporary node is created,kind of helper
    list3=temp;         //pointer list3=temp
    list1=h1;           //for traversal and comparison
    list2=h2;           //for traversal and comparison

    while(list1!=0 && list2!=0)                //both need to be true
    {
        if(list1->data<list2->data)            //list1(data)<list2(data)
        {
            list3->nxt=list1;                  //or temp. node's nxt part pointing to list 1
            list1=list1->nxt;                  //list 1 moves and list 2 stays where it was before
        }
        else                                   //list1(data)>list2(data)
        {
            list3->nxt=list2;
            list2=list2->nxt;                  //list 2 moves and list 1 stays where it was before
        }

        list3=list3->nxt;                      //list 3 moves ahead every time
    }

    //if a list got terminated before the other one
    //for rest of the terms

    while(list1!=0)
    {
        list3->nxt=list1;
        list1=list1->nxt;
        list3=list3->nxt;
    }

    while(list2!=0)
    {
        list3->nxt=list2;
        list2=list2->nxt;
        list3=list3->nxt;
    }

    //OUTPUT

    cout<<endl;
    cout<<"MERGED SORTED LINKED LIST IS "<<endl;

    h3=temp->nxt;           //head = temporary node's nxt part
    list=h3;                //for traversal

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
    cout<<"\n***************************************************"<<endl;
    cout<<"\nLINKED LIST 1 - "<<endl;
    list_1();
    cout<<endl;
    cout<<"***************************************************"<<endl;
    cout<<"\nLINKED LIST 2 - "<<endl;
    list_2();
    cout<<endl;
    cout<<"***************************************************"<<endl;
    cout<<endl;
    cout<<"###################################################"<<endl;
    merge();
    cout<<endl;
    cout<<"###################################################"<<endl;

    return 0;
}
