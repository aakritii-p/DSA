#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int max_sum(int arr[], int n)
{
    sort(arr,arr+n);
    bool flag = true;
    int i = 0;
    int j = n-1;
    int sum = 0;
    while(i<j)
    {
        sum+=abs(arr[i]-arr[j]);
        if(flag){
            i++;
        }
        else
        {
            j--;
        }
        flag=!flag;
    }
    sum+=abs(arr[i]-arr[0]);
    return sum;
}



int main()
{
    int arr[]={1,4,2,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    int res = max_sum(arr,n);
    cout<<"Maximum sum of absolute difference of any permutation is: "<<res;
    return 0;
}