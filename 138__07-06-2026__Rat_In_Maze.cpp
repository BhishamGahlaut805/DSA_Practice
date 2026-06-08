/*
Consider a rat placed at position (0, 0) in an n x n square matrix maze[][]. The rat's goal is to reach the destination at position (n-1, n-1). The rat can move in four possible directions: 'U'(up), 'D'(down), 'L' (left), 'R' (right).

The matrix contains only two possible values:

0: A blocked cell through which the rat cannot travel.
1: A free cell that the rat can pass through.
Your task is to find all possible paths the rat can take to reach the destination, starting from (0, 0) and ending at (n-1, n-1), under the condition that the rat cannot revisit any cell along the same path. Furthermore, the rat can only move to adjacent cells that are within the bounds of the matrix and not blocked.
If no path exists, return an empty list.

Note: Return the final result vector in lexicographically smallest order.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void solve(vector<vector<int>> &maze, vector<string> &ans, int i, int j, string path, int n)
    {

        if (i < 0 || i >= n || j < 0 || j >= n || maze[i][j] == 0)
        {
            return; // No path is possible
        }
        if (i == n - 1 && j == n - 1)
        {
            ans.push_back(path);
            return;
        }

        maze[i][j] = 0;
        solve(maze, ans, i + 1, j, path + "D", n);
        solve(maze, ans, i - 1, j, path + "U", n);
        solve(maze, ans, i, j + 1, path + "R", n);
        solve(maze, ans, i, j - 1, path + "L", n);
        maze[i][j] = 1;
    }
    vector<string> ratInMaze(vector<vector<int>> &maze)
    {
        // code here
        vector<string> ans;
        solve(maze, ans, 0, 0, "", maze.size());
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> maze(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> maze[i][j];
        }
    }
    Solution ob;
    vector<string> result = ob.ratInMaze(maze);
    if (result.empty())
    {
        cout << -1 << endl;
    }
    else
    {
        for (const string &path : result)
        {
            cout << path << " ";
        }
        cout << endl;
    }
    return 0;
}
/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 138__07-06-2026__Rat_In_Maze.cpp -o 138__07-06-2026__Rat_In_Maze } ; if ($?) { .\138__07-06-2026__Rat_In_Maze }
cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 138__07-06-2026__Rat_In_Maze.cpp -o 138__07-06-2026__Rat_In_Maze} ; if ($?) { .\138__07-06-2026__Rat_In_Maze }
-1
*/

