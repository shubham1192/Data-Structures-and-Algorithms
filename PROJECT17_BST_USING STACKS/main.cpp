#include <iostream>
#define S 50
int top=-1;

using namespace std;
struct node
{
    int data;
    node *lft;
    node *rt;
};
node* stack[S];
node *root=0;
node *temp,*parent,*curr;

void push(node* x) //push fn
{
   top++;
   stack[top]=x;
}

node *Top() //Top fn
{
    node *topval=stack[top];
    return topval;
}

node* pop()  //pop fn
{
    node* poppedval=stack[top];
    top--;
    return poppedval;
}

void insert()
{
    int x;
    cout<<endl;
    cout<<"Enter data : "; cin>>x;


    temp=new node;
    temp->data=x;
    temp->lft=0; temp->rt=0;

    parent=root;

    if(root==0)  //setting up the root
    {
        root=temp;
    }
    else
    {
        curr=root;     //starting with root
        while(curr)
        {
            parent=curr;  //finding parent
            if(temp->data>curr->data)
            {
                curr=curr->rt;
            }
            else
            {
                curr=curr->lft;
            }
        }

    if(temp->data>parent->data)   //setting up the child nodes
    {
        cout<<endl;
        cout<<temp->data<<" is the RIGHT CHILD of "<<parent->data<<endl;
        parent->rt=temp;
        cout<<endl;
    }

    else
    {
        cout<<endl;
        cout<<temp->data<<" is the LEFT CHILD of "<<parent->data<<endl;
        cout<<endl;
        parent->lft=temp;
    }

  }
}


void in() //inorder (LNR)
{
    node *ptr=0;
    ptr=root; //starting with root

    while(1)
    {
        while(ptr!=0) //proceeding down towards left and pushing node
        {
            push(ptr);
            ptr=ptr->lft;
        }

        if(top==-1)  //stack empty->break
           break;

         ptr=pop();
         cout<<ptr->data<<"  ";  //popped data
         ptr=ptr->rt;  //checking for right child and assigning ptr if popped element has rt child
    }

}

void pre()  //preorder (NLR)
{
    node *ptr=0;
    ptr=root;

    while(ptr!=0)
    {
        while(ptr!=0)  //pushing rt child if any and proceeding towards left
        {
            if(ptr->rt!=0)
            {
                push(ptr->rt);
            }
            cout<<ptr->data<<"  ";//printing node
            ptr=ptr->lft;
        }

        //no left child
        if(top!=-1) //if stack is not empty
        ptr=pop();  //assign ptr to popped element which is a rt child

    }
}

void post()  //postorder (LRN)
{
    node *ptr=0;
    ptr=root;

    while(1)
    {
        if(ptr!=0)
        {
            push(ptr);  //pushing node
            ptr=ptr->lft; //proceeding down towards left
        }

        else  //ptr==0(left child absent)
        {
            if(top==-1)  //stack empty->break
                break;

            else
                {
                    if(Top()->rt==0)  //right child of the topmost element in the stack is absent
                    {
                        ptr=pop();  //assign ptr to popped element

                        cout<<ptr->data<<"  ";   //printing popped element

                        while(ptr==Top()->rt)  //if ptr(popped ele) is a child of the topmost element in the stack
                        {                      //BACKTRACKING(1.L 2.R 3.Node)
                            cout<<Top()->data<<"  "; //means NODE
                            ptr=pop(); //assign ptr to popped element,again loop

                            if(top==-1)
                                break; //out of while
                        }
                    }

                    if(top!=-1) //stack not empty
                        ptr=Top()->rt; //assign ptr to the right child of the topmost element
                    else
                        ptr=0; //stack empty,will result in execution of the break statement
                }
        }
    }

}

int main()

{
    cout<<"*************************"<<endl;
    cout<<"SHUBHAM INDER 05916412819"<<endl;
    cout<<"*************************"<<endl;
    int opt;
    do
    {
        cout<<endl;
        cout<<"************************************"<<endl;
        cout<<"CHOOSE THE APPROPRIATE OPTION"<<endl;
        cout<<"************************************"<<endl;
        cout<<"\n1. INSERTION"<<"\n2. INORDER TRAVERSAL"<<"\n3. PREORDER TRAVERSAL"<<"\n4. POSTORDER TRAVERSAL"<<endl;
        cin>>opt;
        switch(opt)

        {
        case 1:
            {
                int op=1;
                while(op!=0)
                {
                    insert();
                    cout<<"Wanna continue(0/1)"<<endl;
                    cin>>op;
                }
                break;
            }
        case 2:
            {
                if(root==0)
                    cout<<"\nEMPTY"<<endl;
                else
                {
                    cout<<"\nPREORDER TRAVERSAL -> ";
                    in();
                    cout<<endl;
                }
                break;
            }

        case 3:

            {
                if(root==0)
                    cout<<"\nEMPTY"<<endl;
                else
                {
                    cout<<"\nPREORDER TRAVERSAL -> ";
                    pre();
                    cout<<endl;
                }
                break;
            }

        case 4:

            {
                if(root==0)
                    cout<<"\nEMPTY"<<endl;
                else
                {
                    cout<<"\nPOSTORDER TRAVERSAL -> ";
                    post();
                    cout<<endl;
                }
                break;
            }
        }

    }while(opt!=0);
    return 0;
}
