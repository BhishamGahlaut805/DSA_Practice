/*
Given an m x n grid of characters board and a string word, return true if word exists in the grid.
The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.
*/
/*
Key Idea:(DFS+BackTracking)
Explore all possible paths in the grid using Depth-First Search with backtracking to mark visited cells.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool DFS(int i, int j, int k, int wSize, int m, int n, vector<vector<char>> &board, string word)
    {
        if (k == wSize)
        {
            return true;
        }
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[k])
        {
            return false;
        }
        char temp = board[i][j];
        board[i][j] = '\0';
        if (DFS(i + 1, j, k + 1, wSize, m, n, board, word) || DFS(i - 1, j, k + 1, wSize, m, n, board, word) || DFS(i, j - 1, k + 1, wSize, m, n, board, word) || DFS(i, j + 1, k + 1, wSize, m, n, board, word))
        {
            return true;
        }
        board[i][j] = temp;
        return false;
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        int m = board.size();
        int n = board[0].size();
        int k = word.size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (DFS(i, j, 0, k, m, n, board, word))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main(){
    Solution sol;
    vector<vector<char>>grid={{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    cout<<sol.exist(grid,"ABCCED")<<endl;   //TC:O(m*n*3^k), SC:O(m*n)

}
/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 17__24-03-2026_Word_Search_DFS.cpp -o 17__24-03-2026_Word_Search_DFS } ; if ($?) { .\17__24-03-2026_Word_Search_DFS }
1
*/
