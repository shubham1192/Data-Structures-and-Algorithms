#include <iostream>

using namespace std;
void maxheap(int a[],int n,int i)
{
    int large=i,temp;
    int left=(2*i)+1;
    int right=(2*i)+2;
    if(left<n && a[left]>a[large])
    {
        large=left;
    }
    if(right<n && a[right]>a[large])
    {
        large=right;
    }
    if(large!=i)
    {
        temp=a[large];
        a[large]=a[i];
        a[i]=temp;
        maxheap(a,n,large);
    }
}
void heapsort(int a[],int n)
{
    for(int i=n/2 -1 ;i>=0;i--)
    {
        maxheap(a,n,i);
    }
    for(int i=n-1;i>=0;i--)
    {
        int temp=a[i];
        a[i]=a[0];
        a[0]=temp;
        maxheap(a,i-1,0);
    }
}
int main()
{
    int n,i,j;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    heapsort(arr,n);

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<"  ";
    }
    return 0;
}
