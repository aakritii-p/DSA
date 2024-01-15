#include<iostream>
#include<bits/stdc++.h>

using namespace std;


void merge(int a[],int lb,int mid,int ub)
{
    int i = lb;
    int j = mid+1;
    int k = lb;
    
    int b[7];

    while(i<=mid && j<=ub)
    {
        if(a[i]<=a[j])
        {
            b[k]=a[i];
            i++;
        }
        else{
            b[k]=a[j];
            j++;
        }
        k++;
    }
    while(j<=ub)
    {
        b[k]=a[j];
        j++;
        k++;
    }
    
    while(i<=mid)
    {
        b[k]=a[i];
        i++;
        k++;
    }

    for(int s=0;s<6;s++)
    {
        a[s]=b[s];
    }
    
}

void merge_sort(int *a, int lb, int ub)
{
    if(lb>=ub) return;
    int mid = (lb+ub)/2;
    merge_sort(a,lb,mid);
    merge_sort(a,mid+1,ub);
    merge(a,lb,mid,ub);
}

int main()
{
    int a[]={34,12,55,67,90,44};
    int n = sizeof(a)/sizeof(a[n]);
    merge_sort(a,0,n-1);
    for(int i=0;i<6;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}