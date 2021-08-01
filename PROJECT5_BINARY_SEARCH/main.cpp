#include <iostream>
#define S 50
int arr[S];
using namespace std;

void sort(int arr[],int s)
{
    int min;
    for(int i=0;i<s;i++)
    {
        min=i;
        for(int j=i+1;j<s;j++)
        {
            if(arr[j]<arr[min])
            {
                min=j;
            }
        }
        if(min!=i)
        {
            int temp;
            temp=arr[i];
            arr[i]=arr[min];
            arr[min]=temp;
        }
}
cout<<endl;
cout<<endl;
for(int i=0;i<s;i++)
 {
 cout<<"   a["<<i<<"] = "<<arr[i];
 }
}

int bs(int arr[],int l,int r,int n)

{

  if(r>=0 && l<=r)
  {
      int mid;
      mid=(l+r)/2;
      if(arr[mid]==n)
        return mid;

      else if(arr[mid]<n)
        return bs(arr,mid+1,r,n);
      else if(arr[mid]>n)
        return bs(arr,l,mid-1,n);
  }

return -1;

}

int main()
{
    cout<<"*************************"<<endl;
    cout<<"SHUBHAM INDER 05916412819"<<endl;
    cout<<"*************************"<<endl;
    char i;

    int n;
    cout<<"\n   Enter the size -> "; cin>>n;
    cout<<"\n\n   ARRAY -> ";

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"\n\n   SORTED ARRAY";

    sort(arr,n);
do{
    int num;
    cout<<"\n\n   Enter number to be searched ->  ";
    cin>>num;
    if(bs(arr,0,n-1,num)==-1){
    cout<<"\n   ELEMENT NOT FOUND";
    cout<<endl;
    cout<<endl;}
    else
        cout<<"\n   Element found at :"<<"\n   Position = "<< bs(arr,0,n-1,num)+1<<"\n   Index = "<<bs(arr,0,n-1,num);
        cout<<endl;
        cout<<endl;
        cout<<"\n   Want to search another element(y/n) ";
        cin>>i;}while(i!='n');
    return 0;
}
