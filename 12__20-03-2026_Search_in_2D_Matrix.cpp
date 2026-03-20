/*
You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int row = matrix.size();
        int col = matrix[0].size();
        int i = 0, j = col - 1;
        while (i < row && j > -1)
        {
            if (matrix[i][j] == target)
            {
                return true;
            }
            if (matrix[i][j] < target)
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return false;
    }
};
int main(){
Solution sol;
vector<vector<int>> matrix = { { 1, 3, 5, 7 }, { 10, 11, 16, 20 }, { 23, 30, 34, 60 } } ;
cout<<sol.searchMatrix(matrix, 3);    //TC:O(m+n), SC:O(1)

}

/*
Output:
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 12__20-03-2026_Search_in_2D_Matrix.cpp -o 12__20-03-2026_Search_in_2D_Matrix } ; if ($?) { .\12__20-03-2026_Search_in_2D_Matrix }
1
*/
