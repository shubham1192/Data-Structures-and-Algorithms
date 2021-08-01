#include <iostream>

using namespace std;

int main()
{
    int size,arr[10],num;
    cout << "Enter Size" << endl;
    cin>>size;
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    int found=0;
    cout<<"\nEnter num"; cin>>num;
    for(int i=0;i<size;i++)
    {
        if(arr[i]==num)
        {
            cout<<"Successful";
            cout<<"Element found at"<<i+1<<endl;
            found=1;
            //break;
        }
    }
    if(found==0)
    {
        cout<<"Not found";
    }


}
