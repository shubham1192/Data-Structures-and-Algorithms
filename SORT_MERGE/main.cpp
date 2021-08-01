#include <iostream>

using namespace std;
void merge(int a[],int l,int mid,int u)
{
    int i=l,j=mid+1,k=l,b[u];
    while(i<=mid && j<=u)
    {
        if(a[i]<=a[j])
        {
            b[k]=a[i];
            i++;
        }
        else
        {
            b[k]=a[j];
            j++;
        }
        k++;
    }
    if(i>mid)
    {
        while(j<=u)
        {
            b[k]=a[j];
            j++;
            k++;
        }
    }
    else
    {
        while(i<=mid)
        {
            b[k]=a[i];
            i++;
            k++;
        }
    }
    for(k=l;k<=u;k++)
    {
        a[k]=b[k];
    }
}
void mergesort(int a[],int l,int u)
{
    if(l<u)
    {
        int mid=(l+u)/2;
        mergesort(a,l,mid);
        mergesort(a,mid+1,u);
        merge(a,l,mid,u);
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

    mergesort(arr,lower,upper);

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<"  ";
    }
    return 0;
}
