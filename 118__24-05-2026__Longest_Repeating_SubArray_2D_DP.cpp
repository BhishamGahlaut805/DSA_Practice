// Given two integer arrays nums1 and nums2, return the maximum length of a subarray that appears in both arrays.
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solve(vector<int> &nums1, vector<int> &nums2, vector<vector<int>> &dp, int i, int j)
    {
        if (i < 0 || j < 0)
        {
            return 0;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        if (nums1[i] == nums2[j])
        {
            dp[i][j] = 1 + solve(nums1, nums2, dp, i - 1, j - 1);
        }
        else
        {
            dp[i][j] = 0;
        }
        return dp[i][j];
    }
    int findLength(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int m = nums2.size();
        int ans = 0;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                ans = max(ans, solve(nums1, nums2, dp, i, j));
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums1 = {1, 2, 3, 2, 1};
    vector<int> nums2 = {3, 2, 1, 4, 7};
    cout << sol.findLength(nums1, nums2) << endl; // TC:O(n*m) SC:O(n*m)
}

/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 118__24-05-2026__Longest_Repeating_SubArray_2D_DP.cpp -o 118__24-05-2026__Longest_Repeating_SubArray_2D_DP } ; if ($?) { .\118__24-05-2026__Longest_Repeating_SubArray_2D_DP }
3
*/

