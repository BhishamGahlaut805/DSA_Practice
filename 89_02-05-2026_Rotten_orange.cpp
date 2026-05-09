/*
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> visited = grid;

        queue<pair<int, int>> q;
        int countFresh = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (visited[i][j] == 2)
                {
                    // fill rotten oranges into the queue
                    q.push({i, j});
                }
                if (visited[i][j] == 1)
                {
                    countFresh++;
                }
            }
        }

        if (countFresh == 0)
        {
            return 0;
        }
        if (q.empty())
            return -1;

        int minutes = -1;
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                auto it= q.front();
                q.pop();
                for (auto it1 : dirs)
                {
                    int i = it.first + it1.first;
                    int j = it.second + it1.second;
                    if (i >= 0 && i < m && j >= 0 && j < n && visited[i][j] == 1)
                    {
                        // rotten that orange
                        visited[i][j] = 2;
                        countFresh--;
                        q.push({i, j});
                    }
                }
            }
            minutes++;
        }
        if (countFresh == 0)
            return minutes;
        return -1;
    }
};

int main()
{
    vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    Solution sol;
    cout << sol.orangesRotting(grid) << endl; // TC: O(m*n), SC: O(m*n)
    return 0;
}

/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 89_02-05-2026_Rotten_orange.cpp -o 89_02-05-2026_Rotten_orange } ; if ($?) { .\89_02-05-2026_Rotten_orange }
4
*/

