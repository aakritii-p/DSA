#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int minimum_platform(int arr[], int dep[], int n)
{
    sort(arr,arr+n);
    sort(dep,dep+n);

    int i=1;
    int j=0;

    int platform_req =1 ;
    while(i<n)
    {
        if(arr[i]>dep[j])
        {
            j++;
        }
        else
        {
            platform_req+=1;
        }
        i++;
    }
    return platform_req;
}

int main()
{
    int arr[]={900,940,950,1100,1500,1800};
    int dep[]={910,1200,1120,1130,1900,2000};

    int n = 6;
    cout<<minimum_platform(arr,dep,n);
    return 0;
}

