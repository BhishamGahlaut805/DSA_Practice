#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solveSudoku(vector<vector<char>> &board)
    {
        solve(board);
    }
    bool solve(vector<vector<char>> &board)
    {
        for (int r = 0; r < 9; r++)
        {
            for (int c = 0; c < 9; c++)
            {
                if (board[r][c] == '.')
                {
                    for (char ch = '1'; ch <= '9'; ch++)
                    {
                        if (isValid(board, r, c, ch))
                        {
                            board[r][c] = ch;
                            if (solve(board))
                                return true;
                            board[r][c] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    bool isValid(vector<vector<char>> &board, int r, int c, char ch)
    {
        for (int i = 0; i < 9; i++)
        {
            if (board[r][i] == ch)
                return false;
            if (board[i][c] == ch)
                return false;
        }
        int strow = (r / 3) * 3;
        int stcol = (c / 3) * 3;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[strow + i][stcol + j] == ch)
                    return false;
            }
        }
        return true;
    }
};

int main()
{

    Solution sol;
    vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                  {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                  {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                  {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                  {'4', '.', '8', '8', '6', '3', '.', '.', '1'},
                                  {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                  {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                  {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                  {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    sol.solveSudoku(board); // TC:O(9^(N*N)), SC:O(N*N) - Recursive Stack
    for (auto &i : board)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 46__06-04-2026_Solve_Soduko.cpp -o 46__06-04-2026_Solve_Soduko } ; if ($?) { .\46__06-04-2026_Solve_Soduko }
5 3 4 6 7 8 9 1 2
6 7 2 1 9 5 3 4 8
1 9 8 3 4 2 5 6 7
8 5 9 7 6 1 4 2 3
4 2 8 8 6 3 7 9 1
7 1 3 9 2 4 8 5 6
9 6 1 5 3 7 2 8 4
2 8 7 4 1 9 6 3 5
3 4 5 2 8 6 1 7 9
*/
