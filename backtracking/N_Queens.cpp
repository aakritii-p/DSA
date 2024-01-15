#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void addSolution(vector<vector<int>> &ans, vector<vector<int>> &board, int n)
{
    vector<int> temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] != 0)
            {
                temp.push_back(j + 1);
            }
        }
    }
    ans.push_back(temp);
}

bool isSafe(int row, int col, vector<vector<int>> &board, int n)
{
    int x = row;
    int y = col;

    // check for row
    while (y >= 0)
    {
        if (board[x][y] == 1)
        {
            return false;
        }
        y--;
    }

    // check for upper diagonal
    x = row;
    y = col;

    while (x >= 0 && y >= 0)
    {
        if (board[x][y] == 1)
        {
            return false;
        }
        x--;
        y--;
    }

    // check for lower diagonal
    x = row;
    y = col;

    while (x < n && y >= 0)
    {
        if (board[x][y] == 1)
        {
            return false;
        }
        x++;
        y--;
    }

    return true; // if all cases pass
}

void solve(int col, vector<vector<int>> &ans, vector<vector<int>> &board, int n)
{
    if (col == n)
    {
        addSolution(ans, board, n); // if all queens are placed safely
        return;
    }

    // solve 1 case and rest will be taken care by recursion
    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, board, n))
        {
            board[row][col] = 1;           // placing the queen
            solve(col + 1, ans, board, n); // recursive fun sending for next column
            board[row][col] = 0;           // backtracking
        }
    }
}

vector<vector<int>> nQueen(int n)
{
    vector<vector<int>> ans;
    vector<vector<int>> board(n, vector<int>(n, 0));
    solve(0, ans, board, n);
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    int n;
    cout << "Enter n for board(n*n): " << endl;
    cin >> n;
    vector<vector<int>> res = nQueen(n);
    cout<<"Number of solutions possible: "<<res.size()<<endl;
    if(res.size() == 0)
            cout<<-1<<"\n";
    else {
        for(int i = 0;i < res.size();i++){
            cout<<"[";
            for(int u: res[i])
                cout<<u<<" ";
            cout<<"] ";
        }
        cout<<endl;
    }
    return 0;
}