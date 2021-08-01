#include <iostream>

using namespace std;

int main()
{
    int arr[10],i,size,pos,num;
    cout<<"Enter the size of array = ";
    cin>>size;
    for(i=0;i<size;i++)
    {
        cout<<"\narr" <<"["<<i<<"]" << "=" ; cin>>arr[i];
    }
        cout<<"\nTRAVERSAL"<<endl;

    //OUTPUT

    for(i=0;i<size;i++)
    {
        cout<<arr[i]<< " ";
    }
     cout<<"\nPosition at which deletion to be performed"<<endl;
    cin>>pos;
    //cout<<"Enter number = "; cin>>num;

    for(i=pos-1;i<size-1;i++)
    {
        arr[i]=arr[i+1];
    }
    //arr[pos-1]=num;
    size--;

    //OUTPUT

    for(i=0;i<size;i++)
    {
        cout<<arr[i]<< " ";
    }
    return 0;
}
