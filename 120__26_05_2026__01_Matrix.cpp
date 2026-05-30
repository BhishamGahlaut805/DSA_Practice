// Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.
// The distance between two cells sharing a common edge is 1.
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int rows = mat.size();
        int cols = mat[0].size();
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        queue<pair<int, int>> q;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (mat[i][j] == 0)
                {

                    q.push({i, j});
                }
                else
                {
                    mat[i][j] = INT_MAX;
                }
            }
        }
        while (!q.empty())
        {
            pair<int, int> cell = q.front();
            q.pop();
            int row = cell.first;
            int col = cell.second;

            for (pair<int, int> dir : directions)
            {
                int newRow = row + dir.first;
                int newCol = col + dir.second;

                if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && mat[newRow][newCol] > mat[row][col] + 1)
                {
                    mat[newRow][newCol] = mat[row][col] + 1;
                    q.push({newRow, newCol});
                }
            }
        }
        return mat;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> mat = {{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};
    vector<vector<int>> result = s.updateMatrix(mat);   //TC: O(m*n)  SC: O(m*n)
    for (const auto &row : result)
    {
        for (int val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}
/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 120__26_05_2026__01_Matrix.cpp -o 120__26_05_2026__01_Matrix } ; if ($?) { .\120__26_05_2026__01_Matrix }
0 0 0
0 1 0
1 2 1
*/

