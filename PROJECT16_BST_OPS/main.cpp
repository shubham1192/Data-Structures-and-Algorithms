#include <iostream>

using namespace std;

struct node
{
    int data;
    node *lft;
    node *rt;
};
node *root=0;
node *temp,*parent,*curr;

void insert()
{
    int x;
    cout<<endl;
    cout<<"Enter data : "; cin>>x;


    temp=new node;
    temp->data=x;
    temp->lft=0; temp->rt=0;

    parent=root;

    if(root==0)
    {
        root=temp;
    }
    else
    {
        curr=root;
        while(curr)
        {
            parent=curr;
            if(temp->data>curr->data)
            {
                curr=curr->rt;
            }
            else
            {
                curr=curr->lft;
            }
        }
    if(temp->data>parent->data)
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

void del()
{
    int Data;
    cin>>Data;
    curr=root;
    parent=0;

    while(curr!=0 && curr->data!=Data)
    {
        parent=curr;
        if(Data < curr->data)
            curr=curr->lft;
        else
            curr=curr->rt;
    }

    if(curr==0)
    {
        cout<<"Data not found"<<endl;
    }

    else if(root->lft==0 && root->rt==0)
    {
        root=0;
        delete root;
        cout<<"DELETED";
    }

    else if(curr->lft==0 && curr->rt==0)
    {
        //cout<<curr->data;
        if(curr==parent->lft)
        {
            parent->lft=0;
            delete curr;
        }
        else
        {
            parent->rt=0;
            delete curr;
        }
    }

    else if(curr->lft==0 || curr->rt==0)
    {
        node *t,*small,*pre;
        node *large;

        if(curr==root && curr->rt==0)
        {
            t=curr->lft;
            if(t->rt!=0)
            {
                while(t->rt!=0)
                {
                    pre=t;
                    t=t->rt;
                    large=t;
                }
                curr->data=large->data;
                pre->rt=0;
                delete large;
            }

            else
            {
                curr->lft=0;
                root=t;
            }
        }

        else if(curr==root && curr->lft==0)
        {

            t=curr->rt;
            if(t->lft!=0)
            {
                while(t->lft!=0)
                {
                    pre=t;
                    t=t->lft;
                    small=t;
                }
                curr->data=small->data;
                pre->lft=0;
                delete small;
            }

            else
            {
                curr->rt=0;
                root=t;
            }
        }

        else if((curr->rt!=0 && parent->rt==curr)||(curr->lft!=0 && parent->rt==curr))
        {
            if(curr->rt!=0)
            {
                t=curr->rt;
                if(t->lft!=0)
                {
                    while(t->lft!=0)
                    {
                        pre=t;
                        t=t->lft;
                        small=t;
                    }
                    curr->data=small->data;
                    pre->lft=0;
                    delete small;
                }
                else
                {
                parent->rt=curr->rt;
                curr->rt=0;
                delete curr;
                }
            }

            else
            {

                node *t=curr->lft;
                if(t->rt!=0)
                {
                    while(t->rt!=0)
                    {
                        pre=t;
                        t=t->rt;
                        large=t;
                    }
                    curr->data=large->data;
                    pre->rt=0;
                    delete large;
                }
                else
                {
                parent->rt=curr->lft;
                curr->lft=0;
                delete curr;
                }
            }
        }

        else if((curr->lft!=0 && parent->lft==curr)||(curr->rt!=0 && parent->lft==curr))
        {
            if(curr->lft!=0)
            {
                t=curr->lft;
                if(t->rt!=0)
                {
                    while(t->rt!=0)
                    {
                        pre=t;
                        t=t->rt;
                        large=t;
                    }
                    curr->data=large->data;
                    pre->rt=0;
                    delete large;
                }
                else
                {

                    parent->lft=curr->lft;
                    curr->lft=0;
                    delete curr;
                }

            }
            else
            {
                t=curr->rt;
                if(t->rt!=0)
                {
                    while(t->lft!=0)
                    {
                        pre=t;
                        t=t->lft;
                        small=t;
                    }
                    curr->data=small->data;
                    pre->lft=0;
                    delete small;
                }
                else
                {
                parent->lft=curr->rt;
                curr->rt=0;
                delete curr;
                }
            }
        }
    }

    else if(curr->lft!=0 && curr->rt!=0)
    {
        node * n1;
        n1=curr->rt;
        if(n1->lft==0 && n1->rt==0)
        {
            curr->data=n1->data;
            curr->rt=0;
            delete n1;
        }
        else if(n1->lft!=0)
        {
            node*pre,*small;
            while(n1->lft!=0)
            {
                pre=n1;
                n1=n1->lft;
                small=n1;
            }
            if(small->rt!=0)
            {
                curr->data=small->data;
                pre->lft=small-> rt;
                delete small;
            }
            else
            {
            curr->data=small->data;
            pre->lft=0;
            delete small;
            }
        }
        else
        {
            curr->data=n1->data;
            curr->rt=n1->rt;
            n1->rt==0;
            delete n1;
        }
    }
}

void search()
{
    int Data;
    cin>>Data;

    node*temp=root;
    if(root==0)
    {
        cout<<"EMPTY"<<endl;
    }
    else
    {

    while(temp!=0)
    {
        if(Data>temp->data)
        {
            temp=temp->rt;
        }
        else if(Data==temp->data)
        {
            cout<<"FOUND"<<endl;
            break;
        }
        else if(Data<temp->data)
        {
            temp=temp->lft;
        }
    }
    if(temp==0)
    {
        cout<<"NOT FOUND"<<endl;
    }
    }

}

void inorder(node *root)
{
    if(root==0)
        return;
    else
        {
            inorder(root->lft);
            cout<<root->data<<"  ";
            inorder(root->rt);
        }
}

void preorder(node *root)
{
     if(root==0)
        return;


            cout<<root->data<<"  ";
            preorder(root->lft);
            preorder(root->rt);

}

void postorder(node *root)
{
     if(root==0)
        return;
    else
        {
            postorder(root->lft);
            postorder(root->rt);
            cout<<root->data<<"  ";
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
        cout<<"CHOOSE THE APPROPRIATE OPTION"<<endl;
        cout<<"\n1. INSERTION"<<"\n2. DELETION"<<"\n3. SEARCH"<<"\n4. INORDER TRAVERSAL"<<"\n5. PREORDER TRAVERSAL"<<"\n6. POSTORDER TRAVERSAL"<<endl;
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
                del();
                inorder(root);
                break;
            }
        case 3:
            {

                search();
                break;
            }
        case 4:
            {
                cout<<endl;
                inorder(root);
                cout<<endl;
                break;
            }

        case 5:
            {
                cout<<endl;
                preorder(root);
                cout<<endl;
                break;
            }

        case 6:
            {
                cout<<endl;
                postorder(root);
                cout<<endl;
                break;
            }
        }
    }while(opt!=0);
    return 0;
}
