#include <iostream>

using namespace std;

int main()
{
    int m,n,a=1,i,j,l=0,b=0,s,zeros;
        cout<<"*************************"<<endl;
        cout<<"SHUBHAM INDER 05916412819"<<endl;
        cout<<"*************************"<<endl;

    do
    {
        cout<<"\nEnter size of the matrix = "; cin>>m; cin>>n;
        if(m<=0 || n<=0)
        {
            cout<<"\nEnter no. greater than 0\n";
        }
    }
    while(m<=0 || n<=0);

    int A1[m][n];
    cout<<"\n"<<m<<"x"<<n<<" MATRIX :-"<<endl;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>   A1[i][j];
            if(A1[i][j]!=0)
            {
               b++;
            }
        }
    }
    zeros=m*n-b;
    if(zeros>=(m*n)/2)
    {
        cout<<"\nThat's a SPARSE MATRIX, because no. of non zero elements are less"<<endl;
    }
    else{
        cout<<"\nThat's not a SPARSE MATRIX"<<endl;
        return 0;}

    s=b+1;
    int A2[s][3];
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(A1[i][j]!=0)
            {
               A2[a][0]=i+1;
               A2[a][1]=j+1;
               A2[a][2]=A1[i][j];
               a++;
               l++;
            }
        }
    }
    A2[0][0]=m;
    A2[0][1]=n;
    A2[0][2]=l;
cout<<endl;
cout<<"     TRIPLET FORM :-"<<endl;
cout<<"   ROW"<<"  COLS"<<"  DATA SIZE";
cout<<endl;
    for(i=0;i<a;i++)
    {
        for(j=0;j<3;j++)
        {
            cout<<"   "<<A2[i][j]<<"   ";
        }
        cout<<endl;

    }
    //cout<<a<<s;

    return 0;
}
