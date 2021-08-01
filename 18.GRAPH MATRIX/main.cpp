#include <iostream>

using namespace std;

int main()
{
    cout<<"*************************"<<endl;
    cout<<"SHUBHAM INDER 05916412819"<<endl;
    cout<<"*************************"<<endl;
    int x,opt;
    cout<<"\nVertices : "; cin>>x;
    int mat[x][x];

    int j;
    for(int i=1;i<=x;i++)
    {
        for(j=i;j<=x;j++)
        {
            cout<<"Edge b/w "<<i<<" & "<<j<<" : ";
            cin>>opt;
            if(opt==1)
            {
                mat[i][j]=1;
                mat[j][i]=1;
            }
            else
            {
                mat[i][j]=0;
                mat[j][i]=0;

            }

        }
    }

    cout<<endl;
    for(int i=1;i<=x;i++)
    {
        cout<<"        "<<i;
    }
    cout<<endl;
    cout<<endl;
    for(int i=1;i<=x;i++)
    {
        cout<<i<<" -> "<<" ";
        for(int q=1;q<=x;q++)
        {
            cout<<"  "<<mat[i][q]<<"      ";
        }
        cout<<endl;
        cout<<endl;
    }

    return 0;
}
