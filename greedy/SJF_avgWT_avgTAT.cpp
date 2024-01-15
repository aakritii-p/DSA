#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    double round(double var)
    {
        double value = (int)(var * 100 + .5); // eg: 12.345 : (int)(12.34*100 + .5) = (int)(1234.5) = 1235 
        return (double)value / 100; //(double) 1235/100 = 12.35
    }

    vector<double> averageTimes(vector<int> arrivalTime, vector<int> burstTime, int n)
    {

        vector<int> ct(n);
        vector<int> tat(n);
        vector<int> wt(n);
        vector<int> completed(n);

        int systemTime = 0;
        double tatime = 0;
        double wtime = 0;
        int total_processes = 0;

        for (int i = 0; i < n; i++)
        {
            completed[i] = 0;
        }

        while (total_processes != n)
        {
            int min = INT_MAX;
            int check = n; // if no minimum burst time found, check would remain n and we have to increase the system time

            for (int i = 0; i < n; i++)
            {
                if ((completed[i] == 0) and (burstTime[i] < min) and (arrivalTime[i] <= systemTime))
                {
                    min = burstTime[i];
                    check = i;
                }
            }

            if (check == n)
            {
                systemTime++; //if no processes in queue then we have to check for another arriving process
            }
            else
            {
                ct[check] = systemTime + burstTime[check];
                systemTime += burstTime[check];
                tat[check] = ct[check] - arrivalTime[check];
                wt[check] = tat[check] - burstTime[check];
                completed[check] = 1;
                total_processes++;
            }
        }

        for (int i = 0; i < n; i++)
        {
            wtime += wt[i];
            tatime += tat[i];
        }

        vector<double> ans(2);

        ans[0] = (double)(wtime / n);
        ans[1] = (double)(tatime / n);

        double res1 = round(ans[0]);
        double res2 = round(ans[1]);
        return {res1, res2};
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arrivalTime(n), burstTime(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arrivalTime[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> burstTime[i];
        }
        Solution ob;
        vector<double> ans = ob.averageTimes(arrivalTime, burstTime, n);
        for (auto it : ans)
        {
            cout << it << " ";
        }
        cout << endl;
    }
    return 0;
}
