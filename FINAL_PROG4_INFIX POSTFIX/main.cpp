#include <iostream>
#define S 50
int top=-1;
char stack[S];
using namespace std;

int prec(char c)
{
    if(c == '^')
    return 3;
    else if(c == '*' || c == '/')
    return 2;
    else if(c == '+' || c == '-')
    return 1;
    else
    return -1;
}

char peek()
{
    return stack[top];
}
char push(char x)
{
    top++;
    stack[top]=x;
}
char pop()
{
    char popval;

    popval=stack[top];
    top--;
    return popval;

}
void display()
{
    for(int i=top;i>=0;i--)
    {
        cout<<"   stack ["<<i<<"]  ->  "<<stack[i]<<endl;
    }
}
void postfix(string q,string p)
{
    int size=q.length();
    q.insert(size,")");
    push('(');

    for(int i=0;i<size+1;i++)
    {
      if((q[i] >='a' && q[i]<='z')||(q[i] >='A' && q[i]<='Z'))
        {
            p=p+q[i];
        }
      else if(q[i]=='(')
            push('(');
      else if(q[i]==')')
      {
        do
        {
            char c=pop();
            p=p+c;

        }while(peek()!='(');
      if(peek()=='(')
            pop();
      }

      else
      {
          while(prec(q[i])<= prec(peek()))
            {
                char c=pop();
                p=p+c;
                //push(q[i]);
            }
             push(q[i]);
       }

    }

      cout<<"\n   Postfix Expression -> "<<p<<endl;
      cout<<endl;
      cout<<endl;
      cout<<endl;
      pop(); //clearing stack

    }


int main()
{
    string exp,nw;
    cout<<"*************************"<<endl;
    cout<<"SHUBHAM INDER 05916412819"<<endl;
    cout<<"*************************"<<endl;
    cout<<"\n\n   Enter infix expression -> "; cin>>exp;
    cout<<"is"<<nw;
    postfix(exp,nw);

    return 0;
}
