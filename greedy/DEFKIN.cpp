#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;;
    cout<<"Enter number of testcases: "<<endl;
    cin>>t;
    while(t--)
    {
        int w,h,n;
        cout<<"Enter width of grid: "<<endl;
        cin>>w;
        cout<<"Enter height of grid: "<<endl;
        cin>>h;
        cout<<"Enter number of towers: "<<endl;
        cin>>n;
        vector<int> a; // for x coordinates (width)
        vector<int> b; // for y corrdinates (height)

        for(int i=0;i<n;i++)
        {
            cout<<"Enter x and y coordinates: "<<endl;
            int x,y;
            cin>>x>>y;
            a.push_back(x);
            b.push_back(y);
        }

        a.push_back(w+1);
        b.push_back(h+1);
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int mx = 0, my = 0;
        for(int i=0;i<a.size()-1;i++)
        {
            mx = max(mx,a[i+1]-a[i]-1);
            my = max(my, b[i+1]-b[i]-1);
        }

        cout<<"penalty is: "<<mx*my<<endl;

    }
}