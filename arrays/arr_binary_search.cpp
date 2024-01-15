#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int binary_search(int arr[], int n,int data)
{
    int low=0, high=n-1;
    
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(data==arr[mid])
        {
            return mid+1;
        }
        else if(data<arr[mid])
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }

    return -1;

}

int main()
{
    int arr[]={3,5,7,9,11};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k = 11;
    int res_index=binary_search(arr,n,k);
    cout<<"The data has been found at position: "<<res_index<<endl;
    return 0;
}