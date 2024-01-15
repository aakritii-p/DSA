#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 

class Solution 
{
    public:
    
    static bool comp(Job a, Job b)
    {
        return (a.profit>b.profit);
    }
    
    
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        int count=0;
        int total_profit=0;
        sort(arr,arr+n,comp);
        
        
        bool timeslot[n] = {0};
        for(int i=0;i<n;i++)
        {
            int timeslot_reqd = (arr[i].dead)-1;
            for(int j=min(n,timeslot_reqd); j>=0; j--)
            {
                if(timeslot[j]==0){
                    count++;
                    total_profit+=arr[i].profit;
                    timeslot[j]=1;
                    break;
                }
            }
        }
        
        return {count,total_profit};
        
    } 
};

int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}
