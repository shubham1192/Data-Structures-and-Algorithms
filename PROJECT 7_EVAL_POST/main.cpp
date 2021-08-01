#include <iostream>
#include <math.h>
#define s 50
int top=-1;
int stack[s],opr1,opr2,f=0;

using namespace std;
int peek()
{
    return stack[top];
}
int push(int a)
{
    top++;
    stack[top]=a;
}
int pop()
{
    if(top>=0)
    top--;

}
int OP(char op)
{
    if(op=='+')
        return opr2+opr1;
    else if(op=='-')
        return opr2-opr1;
    else if(op=='*')
        return opr2*opr1;
    else if(op=='/')
        return opr2/opr1;
    else if(op=='^')
        return pow(opr2,opr1);
        else
        return -1;
}
int evalpos(string a)
{
    int l=a.length();
    for(int i=0;i<l;i++)
    {
        if(a[i]>='0' && a[i]<='9')
        {
            push(a[i]-'0');
        }
        else
        {
            opr1=peek();
            pop();

            if(top>=0)
            opr2=peek();
            else
              {
                  break;
              } // cout<<"INVALID";
            pop();
            //int S=OP(a[i]);
            push(OP(a[i]));
        }
    }
    if(top==0)
        return peek();
    else {
        cout<<"INVALID";
        return -1;}
}


int main()
{
    int opt;
    cout<<"*************************"<<endl;
    cout<<"SHUBHAM INDER 05916412819"<<endl;
    cout<<"*************************"<<endl;
    do{
    string exp;
    cout<<"Enter postfix expression : ";
    cin>>exp;
    cout<<evalpos(exp);
    cout<<"\nWant to proceed";
    cin>>opt;
    top=-1;}while(opt!=0);
    return 0;
}
