/*
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
You must do it in place.
*/
/*
Strategy: use the first row and first col as markers and set the subsequent rows and cols to 0s accordingly
*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();

        bool firstRowZero = false;
        bool firstColZero = false;

        // Checking if first col has Zero
        for (int r = 0; r < rows; r++)
        {
            if (matrix[r][0] == 0)
            {
                firstColZero = true;
                break;
            }
        }

        // Checking if first row has zero
        for (int c = 0; c < cols; c++)
        {
            if (matrix[0][c] == 0)
            {
                firstRowZero = true;
                break;
            }
        }
        // Use the first row and column contains zero
        for (int r = 1; r < rows; r++)
        {
            for (int c = 1; c < cols; c++)
            {
                if (matrix[r][c] == 0)
                {
                    matrix[0][c] = 0;
                    matrix[r][0] = 0;
                }
            }
        }
        // Set the marked rows to zero
        for (int r = 1; r < rows; r++)
        {
            if (matrix[r][0] == 0)
            {
                for (int c = 1; c < cols; c++)
                {
                    matrix[r][c] = 0;
                }
            }
        }

        // Set the marked cols to zero
        for (int c = 1; c < cols; c++)
        {
            if (matrix[0][c] == 0)
            {
                for (int r = 1; r < rows; r++)
                {
                    matrix[r][c] = 0;
                }
            }
        }
        // Setting the first row to 0 if required
        if (firstRowZero)
        {
            for (int c = 0; c < cols; c++)
            {
                matrix[0][c] = 0;
            }
        }
        // Setting the first col to 0 if required
        if (firstColZero)
        {
            for (int r = 0; r < rows; r++)
            {
                matrix[r][0] = 0;
            }
        }
    }
};

int main(){
    Solution sol;
    vector<vector<int>>matrix={{1,1,1},{1,0,1},{1,1,1}};    //TC:(O(rows*cols)), SC:O(1)
    sol.setZeroes(matrix);
    for(auto i:matrix){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 16__24-03-2026_Set_Matrix_Zeros.cpp -o 16__24-03-2026_Set_Matrix_Zeros } ; if ($?) { .\16__24-03-2026_Set_Matrix_Zeros }
1 0 1
0 0 0
1 0 1
*/
