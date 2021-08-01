#include <iostream>
using namespace std;
int n,temp,lower,upper;;
void output(int arr[])
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<"  ";
    }
}
void bubble(int arr[])
{
    for(int i=0;i<n-1;i++)
    {
        int swap=0;
        {
            for(int j=0;j<n-1-i;j++)
            {
                if(arr[j]>arr[j+1])
                {
                    temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
                    swap=1;
                }
            }
            if(swap==0)
            {
                break;
            }
        }
    }
}
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
void insertion(int arr[])
{
    for(int i=1;i<n;i++)
    {
        temp=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>temp)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}
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
        maxheap(a,i,0);
    }
}
int main()
{
    cout<<"*************************"<<endl;
    cout<<"SHUBHAM INDER 05916412819"<<endl;
    cout<<"*************************"<<endl;
    int opt1,opt2;
    do
    {
        cout<<"\nENTER SIZE : "; cin>>n;
        int arr[n];

        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }

    do
    {
        cout<<"\nCHOOSE THE APPROPRIATE OPTION (EXIT 0)"<<endl;
        cout<<"\n1. BUBBLE SORT"<<"\n2. QUICK SORT"<<"\n3. INSERTION SORT"<<"\n4. MERGE SORT"<<"\n5. HEAP SORT"<<endl;
        cin>>opt1;
        switch(opt1)
        {
        case 1:
            {
                cout<<"\nBUBBLE SORT :";
                bubble(arr);
                output(arr);
                cout<<endl;
                break;
            }
        case 2:
            {
                lower=0; upper=n-1;
                cout<<"\nQUICK SORT :";
                quick(arr,lower,upper);
                output(arr);
                cout<<endl;
                break;
            }
        case 3:
            {
                cout<<"\nINSERTION SORT :";
                insertion(arr);
                output(arr);
                cout<<endl;
                break;
            }
        case 4:
            {
                cout<<"\nMERGE SORT :";
                lower=0; upper=n-1;
                mergesort(arr,lower,upper);
                output(arr);
                cout<<endl;
                break;
            }
        case 5:
            {
                cout<<"\nHEAP SORT :";
                heapsort(arr,n);
                output(arr);
                cout<<endl;
                break;
            }
        }

    }while(opt1!=0);
    cout<<"\nARRAY INITIALISATION(1) EXIT(0) : "; cin>>opt2;
    }while(opt2!=0);
    return 0;
}
