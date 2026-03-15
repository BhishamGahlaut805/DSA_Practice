/*
You are given a 0-indexed 2D integer matrix grid of size n * n with values in the range [1, n2]. Each integer appears exactly once except a which appears twice and b which is missing. The task is to find the repeating and missing numbers a and b.
Return a 0-indexed integer array ans of size 2 where ans[0] equals to a and ans[1] equals to b.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid)
    {
        int n = grid.size();

        long long exp = 1LL * (n * n) * (n * n + 1) / 2;
        long long expsq = 1LL * (n * n) * (n * n + 1) * (2 * n * n + 1) / 6;

        long long actualsum = 0, actualsq = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                actualsum += grid[i][j];
                actualsq += (long long)grid[i][j] * grid[i][j];
            }
        }
        // a-b is
        long long diffSum = actualsum - exp;

        // a^2-b^2 is
        long long diffSq = actualsq - expsq;

        // a+b is
        long long sumAb = diffSq / diffSum;

        int a = (sumAb + diffSum) / 2;
        int b = (sumAb - diffSum) / 2;
        return {a, b};
    }
};

int main()
{
    vector<vector<int>> grid = {{1, 3}, {2, 2}};
    Solution sol;
    vector<int> ans = sol.findMissingAndRepeatedValues(grid); // T.C:O(n*2) , S.C:O(1)
    cout << ans[0] << " " << ans[1] << endl;
}

/*
Output:
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 2__14-03-2026_Repeat_MissingNumber_Easy.cpp -o 2__14-03-2026_Repeat_MissingNumber_Easy } ; if ($?) { .\2__14-03-2026_Repeat_MissingNumber_Easy }
2 4
*/