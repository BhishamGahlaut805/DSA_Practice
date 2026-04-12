/*
There is a knight on an n x n chessboard. In a valid configuration, the knight starts at the top-left cell of the board and visits every cell on the board exactly once.

You are given an n x n integer matrix grid consisting of distinct integers from the range [0, n * n - 1] where grid[row][col] indicates that the cell (row, col) is the grid[row][col]th cell that the knight visited. The moves are 0-indexed.

Return true if grid represents a valid configuration of the knight's movements or false otherwise.

Note that a valid knight move consists of moving two squares vertically and one square horizontally, or two squares horizontally and one square vertically. The figure below illustrates all the possible eight moves of a knight from some cell.
*/
#include<bits/stdc++.h>
using namespace std;


class Solution
{
    const vector<pair<int, int>> dxdy = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};

public:
    bool solve(vector<vector<int>> &grid, int i, int j, int req, const int &size, const int &maxSize)
    {
        if (i >= size || i < 0 || j >= size || j < 0)
            return false;
        if (grid[i][j] != req)
            return false;
        if (req == maxSize - 1)
            return true;
        for ( auto it : dxdy)
        {
            int dx=it.first;
            int dy=it.second;
            if (solve(grid, i + dx, j + dy, req + 1, size, maxSize))
            {
                return true;
            }
        }
        return false;
    }
    bool checkValidGrid(vector<vector<int>> &grid)
    {
        const int size = grid.size();
        const int maxSize = size * size;
        return solve(grid, 0, 0, 0, size, maxSize);
    }
};

int main(){
Solution sol;
vector<vector<int>>grid={{0,11,16,5,20},{17,4,19,10,15},{12,1,8,21,6},{3,18,23,14,9},{24,13,2,7,22}};
cout<<sol.checkValidGrid(grid);
}
/*
Time complexity: O(8^N^2)
Space complexity: O(1),ignoringrecursionstack

PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 44__05-04-2026_Knights_Tour.cpp -o 44__05-04-2026_Knights_Tour } ; if ($?) { .\44__05-04-2026_Knights_Tour }
1
*/


