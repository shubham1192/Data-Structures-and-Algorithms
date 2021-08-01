#include <iostream>

using namespace std;

int main()
{
    int n,i;
    cout<<"Enter Size ";
    cin>>n;
    int arr[n];

    //INPUT

    for(i=0;i<n;i++)
    {
        cout<<"\narr" <<"["<<i<<"]" << "=" ; cin>>arr[i];
    }

    cout<<"\nTRAVERSAL"<<endl;

    //OUTPUT

    for(i=0;i<n;i++)
    {
        cout<<arr[i]<< " ";
    }
    return 0;
}
