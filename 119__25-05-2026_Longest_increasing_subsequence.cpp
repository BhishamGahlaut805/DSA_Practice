// Given an integer array nums, return the length of the longest strictly increasing subsequence.

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 1);
        int ans = 1;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << s.lengthOfLIS(nums) << endl; // TC: O(n^2) SC: O(n)
    return 0;
}
/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 119__25-05-2026_Longest_increasing_subsequence.cpp -o 119__25-05-2026_Longest_increasing_subsequence } ; if ($?) { .\119__25-05-2026_Longest_increasing_subsequence }
4
*/

