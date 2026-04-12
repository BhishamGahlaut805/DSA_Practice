#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isSafe(int row, int col, int n, vector<string> &ans)
    {
        for (int i = 0; i < row; i++)
        {
            if (ans[i][col] == 'Q')
            {
                return false;
            }
        }

        int i = row;
        int j = col;
        while (i >= 0 && j >= 0)
        {
            if (ans[i][j] == 'Q')
            {
                return false;
            }
            i--;
            j--;
        }
        i = row;
        j = col;
        while (i >= 0 && j < n)
        {
            if (ans[i][j] == 'Q')
            {
                return false;
            }
            i--;
            j++;
        }
        return true;
    }
    void solve(int x, int n, vector<vector<string>> &ans, vector<string> &Sol)
    {
        // Base-condition
        if (x >= n)
        {
            ans.push_back(Sol);
            return;
        }

        for (int i = 0; i < n; i++)
        {
            if (isSafe(x, i, n, Sol))
            {
                Sol[x][i] = 'Q';
                solve(x + 1, n, ans, Sol);
                Sol[x][i] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<string> Sol(n, string(n, '.'));
        vector<vector<string>> ans;
        solve(0, n, ans, Sol);
        return ans;
    }
};

int main(){
    Solution sol;

    vector<vector<string>>ans= sol.solveNQueens(4); //TC:O(2^N), SC:O(N)
    
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<endl;
        }
        cout<<endl;
    }
}
/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 43__03-04-2026_N_Queens.cpp -o 43__03-04-2026_N_Queens } ; if ($?) { .\43__03-04-2026_N_Queens }
.Q..
...Q
Q...
..Q.

..Q.
Q...
...Q
.Q..

*/
