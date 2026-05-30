/*
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int islands = 0;
        int n = grid.size();
        int m = grid[0].size();

        unordered_set<string> visited;
        vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '1' && visited.find(to_string(i) + "," + to_string(j)) == visited.end())
                {
                    islands++;
                    bfs(grid, i, j, visited, dir, n, m);
                }
            }
        }
        return islands;
    }
    void bfs(vector<vector<char>> &grid, int i, int j, unordered_set<string> &visited, vector<pair<int, int>> &dir, int n, int m)
    {
        queue<pair<int, int>> q;
        visited.insert(to_string(i) + "," + to_string(j));
        q.push({i, j});

        while (!q.empty())
        {
            auto &it = q.front();
            int row = it.first;
            int col = it.second;

            q.pop();

            for (auto &d : dir)
            {
                int nr = row + d.first;
                int nc = col + d.second;
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == '1' && visited.find(to_string(nr) + "," + to_string(nc)) == visited.end())
                {
                    q.push({nr, nc});
                    visited.insert(to_string(nr) + "," + to_string(nc));
                }
            }
        }
    }
};

int main()
{
    Solution s;
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}};
    cout << s.numIslands(grid) << endl; //TC:O(N*M) SC:O(N*M)
    return 0;
}
/*
Approach for solution :
1. We will traverse the grid and whenever we encounter a '1' which is not visited, we will increment the count of islands and perform a BFS/DFS to mark all the connected '1's as visited.
2. We will use a queue for BFS and an unordered_set to keep track of visited cells.
3. We will also define the directions for moving up, down, left and right.
4. The BFS will continue until the queue is empty, and we will check for valid neighboring cells that are '1' and not visited, and add them to the queue and mark them as visited.
5. Finally, we will return the count of islands.
*/
/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 122__28-05-2026_Number_of_islands.cpp -o 122__28-05-2026_Number_of_islands } ; if ($?) { .\122__28-05-2026_Number_of_islands }
3
*/
