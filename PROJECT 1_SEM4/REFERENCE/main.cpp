#include<iostream>
using namespace std;

void traverse(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int insert(int a[],int n)
{

    int num;
    cout<<"Enter the element you want to insert in the array : ";
    cin>>num;
    a[n++]=num;
    return n;

}

int insertatbeg(int a[],int n)
{
    int num;

    cout<<"Enter the element you want to insert in the array : ";
    cin>>num;
    for(int i=n-1;i>=0;i--)
    {
        a[i+1]=a[i];
        if(i==0)
        {
            a[i]=num;
            break;
        }
    }
    n++;
    return n;
}

int insertatgiven(int a[],int n,int pos)
{

   int num;
   cout<<"Enter the element you want to enter : ";
   cin>>num;

   for(int i=n-1;i>=0;i--)
   {
        a[i+1]=a[i];

       if(i==pos-1)
       {
           a[i]=num;
           break;
       }

   }
   n++;
   return n;
}
int deleteatend(int a[],int n)
{
    n--;
    return n;
}
int deleteatbeg(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        if(i<n)
        {
            a[i]=a[i+1];
        }
    }
    n--;
    return n;
}
int deleteatgiven(int a[],int n,int pos)
{
    for(int i=0;i<n;i++)
    {
        if(i>=pos-1)
        {
            a[i]=a[i+1];
        }
    }
    n--;
    return n;
}
void search(int a[],int n)
{
    cout<<"Enter the number you want to search in the array : ";
    int num;
    cin>>num;
    for(int i=0;i<n;i++)
    {
        if(num==a[i])
        {
          cout<<"Number "<<num<<" found at position "<<i<<endl;
          break;
        }
    }
}
void selectionsort(int a[],int n)
{
    for(int i=0;i<n;i++)
    {

        for(int j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            {
                int temp;
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
}
int main()
{
   int arr[10];
   int number=0;
   int num;
     while(num!=6)
    {
   cout<<"1.To traverse the array"<<endl<<"2.To insert in the array"<<endl<<"3.To perform delete in the array"<<
            endl<<"4.To perform linear search in the array"<<endl<<"5.To perfrom selection sort"<<endl<<"6.EXIT"<<endl;

    cout<<"Enter your choice : ";
    cin>>num;

     switch(num)
    {

        case 1:
        {

            if(number>0)
            {
              traverse(arr,number);
            }
            else
            {
                cout<<"No element in the array"<<endl;

            }
            break;

        }

        case 2:
        {
           if(number==0)
           {
                int s= insert(arr,number);
                number=s;
           }
           else
           {
               cout<<"1.To insert at the beginning"<<endl<<"2.To insert at end"<<endl<<"3.To insert at the given position"<<endl;
               int num1;
               cout<<"Enter your choice : ";
               cin>>num1;
               switch (num1)
               {
                    case 1:
                    {
                       int s= insertatbeg(arr,number);
                       number=s;
                       break;
                    }
                    case 2:
                    {
                        int s=insert(arr,number);
                        number=s;
                        break;
                    }
                    case 3:
                    {
                        int position;
                         cout<<"Enter the position you want to insert the element : ";
                        cin>>position;
                        if(position<=number)
                        {
                        int s= insertatgiven(arr,number,position);
                        number=s;
                        break;
                        }
                        else
                        {
                            cout<<"Wrong position";
                        }
                    }
               }
           }
            break;
        }
        case 3:
        {
            cout<<"1.Delete from beginning"<<endl<<"2.Delete from end"<<endl<<"3.Delete from specific position"<<endl;
            int num2;
            cout<<"Enter your choice : ";
            cin>>num2;
            switch(num2)
            {
                case 1:
                {
                    int s=deleteatbeg(arr,number);
                    number=s;
                    break;

                }
                case 2:
                {
                    int s=deleteatend(arr,number);
                    number=s;
                    break;
                }
                case 3:
                {


                    int position;
                    cout<<"Enter the position you want to delete the element : ";
                     cin>>position;

                    if(position<=number)
                    {
                         int s=deleteatgiven(arr,number,position);
                         number=s;
                         break;
                    }
                    else
                    {
                        cout<<"Wrong position";
                    }
                }
            }
        }
        case 4:
        {
            search(arr,number);
            break;
        }
        case 5:
        {
                selectionsort(arr,number);
                break;
        }
        case 6:
        {
            exit;
        }
    }
    }

}
