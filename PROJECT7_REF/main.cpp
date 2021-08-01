#include<iostream>
#include<stack>
#include<math.h>
#include<string.h>
using namespace std;
int solve(int ,int,char);
int check(char);
int main()
{
    int count =0; // To check if there exist any operand to solve or not
    stack<int>stac[10];
    char exp[100];
    cout<<"Enter the expression : ";
    cin>>exp;
    for(int i=0;i<strlen(exp);i++)
    {
        if(exp[i]=='+'||exp[i]=='-'||exp[i]=='*'||exp[i]=='/'||exp[i]=='^')
        {
            count=1;
            int b=stac->top();
            stac->pop();
            int a=stac->top();
            stac->pop();
           int getval= solve(a,b,exp[i]);
           stac->push(getval);
        }
        else
        {

            int val=check(exp[i]);

            stac->push(val);

        }
    }
    if(count==1)
    cout<<stac->top();
    else
    cout<<"No operand given to simplyfy the equation";
    stac->pop();
    cout<<endl;

}
int check(char val)
{
  if(val=='0')
    {
        return 0;
    }
    else if(val=='1')
    {
        return 1;
    }
    else if(val=='2')
    {
        return 2;
    }
    else if(val=='3')
    {
        return 3;
    }
    else if(val=='4')
    {
        return 4;
    }
    else if(val=='5')
    {
        return 5;
    }
    else if(val=='6')
    {
        return 6;
    }
    else if(val=='7')
    {
        return 7;
    }
    else if(val=='8')
    {
        return 8;
    }
    else if(val=='9')
    {
        return 9;
    }
    return 0;
}
int solve(int a,int b,char val)
{
   if(val=='+')
   {
       return a + b;
   }
   else if(val=='-')
   {
       return a-b;
   }
   else if(val=='*')
   {
       return a*b;
   }
   else if(val=='/')
   {
       return a/b;
   }
   else if(val=='^')
   {
       return pow(a,b);
   }
   return 0;
}
