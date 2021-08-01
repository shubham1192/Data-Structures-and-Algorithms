#include <iostream>

using namespace std;

void T_HAN(int n, char source,char destination,char auxilary)
{
    if(n==1)
    {
        cout<<"   Disk "<<n<<" moved from "<<source<<" to "<<destination<<endl;
        return;
    }
    T_HAN(n-1,source,auxilary,destination);
    cout<<"   Disk "<<n<<" moved from "<<source<<" to "<<destination<<endl;
    T_HAN(n-1,auxilary,destination,source);
}

int main()
{
    int n;
    cout<<"*************************"<<endl;
    cout<<"SHUBHAM INDER 05916412819"<<endl;
    cout<<"*************************"<<endl;
    cout<<"\n\n   Enter the no. of disks ->  ";
    cin>>n;
    cout<<endl;
    cout<<"   A -> FIRST ROD"<<endl;
    cout<<"   B -> SECOND ROD"<<endl;
    cout<<"   C -> THIRD ROD"<<endl;
    cout<<endl;
    T_HAN(n,'A','C','B');
    return 0;
}
