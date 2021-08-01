#include <iostream>

using namespace std;

void trav(int arr[],int n)
{
   // for(int i=0;i<n;i++)
    //{
      //   cout<<"\narr" <<"["<<i<<"]" << "=" ; cin>>arr[i];
    //}

    //cout<<"\nTRAVERSAL"<<endl;

    //OUTPUT

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<< " ";
    }
}

void insertion(int arr[],int pos,int num,int size)
{
    int i;
    cout<<"\nPosition at which you want to insert the number"<<endl;
    cin>>pos;
    cout<<"Enter number = "; cin>>num;

    for(i=size-1;i>=pos-1;i--)
    {
        arr[i+1]=arr[i];
    }
    arr[pos-1]=num;
    size++;

    //OUTPUT

   // for(i=0;i<size;i++)
    //{
     //   cout<<arr[i]<< " ";
    //}
}
int main()
{
    int arr[10],opt,size,pos,num;
    while(opt!=6)
    {
    cout<<"\n1. Traversing an array"<<"\n2. Insertion in an array"<<"\n3. Deletion in an array"
    <<"\n4. Selection Sort"<<"\n5. Linear Serach"<<"\n6. Exit"<<endl;

    cout<<"Enter your choice"<<endl;
    cin>>opt;

        switch(opt)
    {
    case 1:
        {

            //cout<<"Enter size";
            //cin>>size;
            if(size>0)
            {
                trav(arr,size);
            }
            else{
            cout<<"Size should be greater than 0"<<endl;}
        }
        break;

    case 2:
        {
            if(size==1){
                insertion(arr,pos,num,0);
            }
            else
            insertion(arr,pos,num,size);
        }
        break;


    }

    }


    return 0;
}
