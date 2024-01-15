#include <bits/stdc++.h>
using namespace std;


class Solution{
    public:
    
    bool isSafe(int new_x, int new_y,vector<vector<bool>> &vis,vector<vector<int>> &m,int n){
        
        if((new_x>=0 && new_x<n) && (new_y>=0 && new_y<n) && ((vis[new_x][new_y]) != 1) && m[new_x][new_y]!=0){
            return true;
        }
        else 
            return false;
    }
    
    void solve(int x, int y, vector<vector<int>> &m,vector<string> &ans,vector<vector<bool>> &vis,string path, int n)
    {
        //base case
        if( x==n-1 && y==n-1 ){
            ans.push_back(path);
        }
        
        //movements
        //D,L,R,U
        
        vis[x][y] = 1; //marking visited as true for each cell 

        
        //down
        if(isSafe(x+1,y,vis,m,n)){
            solve(x+1,y,m,ans,vis,path + 'D',n);
        }
        
        //left
        if(isSafe(x,y-1,vis,m,n)){
            solve(x,y-1,m,ans,vis,path + 'L',n);
        }
        
        //right
        if(isSafe(x,y+1,vis,m,n)){
            solve(x,y+1,m,ans,vis,path + 'R',n);
        }
        
        //up
        if(isSafe(x-1,y,vis,m,n)){
            solve(x-1,y,m,ans,vis,path + 'U',n);
        }
        
        vis[x][y] = 0; //marking visited as false after recursion - while returning

        
    }
    
    
    
    
    vector<string> findPath(vector<vector<int>> &m, int n) {

        vector<string> ans;
        vector<vector<bool>>visited(n,vector<bool>(n,0));
        
        if(m[n-1][n-1] == 0 || m[0][0] == 0){ // if starting cell or destination cell is blocked
            return ans;
        };
        
        string path = "";
        
        solve(0,0,m,ans,visited,path,n);
        return ans;

    }
};

    
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
