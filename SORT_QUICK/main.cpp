#include <iostream>

using namespace std;

int partn(int a[],int l,int u)
{
    int piv=a[l],temp;
    int start=l; int end=u;
    while(start<end)
    {
        while(a[start]<=piv)
        {
            start++;
        }
        while(a[end]>piv)
        {
            end--;
        }
        if(start<end)
        {
            temp=a[end];
            a[end]=a[start];
            a[start]=temp;
        }
    }
    temp=a[end];
    a[end]=a[l];
    a[l]=temp;
    return end;
}
void quick(int a[],int l,int u)
{
    if(l<u)
    {
        int pos;
        pos=partn(a,l,u);
        quick(a,l,pos-1);
        quick(a,pos+1,u);
    }
}
int main()
{
    int n,lower,upper;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    lower=0; upper=n-1;

    quick(arr,lower,upper);

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<"  ";
    }
    return 0;
}
