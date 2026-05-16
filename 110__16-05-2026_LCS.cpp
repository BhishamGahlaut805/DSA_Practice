/*
Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings
*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int i, int j, const string &text1, const string &text2, vector<vector<int>> &dp)
    {
        // Base Case
        if (i < 0 || j < 0)
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        if (text1[i] == text2[j])
        {
            dp[i][j] = 1 + solve(i - 1, j - 1, text1, text2, dp);
        }
        else
        {
            dp[i][j] = max(solve(i - 1, j, text1, text2, dp), solve(i, j - 1, text1, text2, dp));
        }
        return dp[i][j];
    }

    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(n - 1, m - 1, text1, text2, dp);
    }
};

int main()
{
    Solution s;
    string text1 = "abcde", text2 = "ace";
    cout << s.longestCommonSubsequence(text1, text2) << endl; //TC: O(n*m) where n and m are the lengths of the input strings. SC: O(n*m) for the dp array.
    return 0;
}
/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 110__16-05-2026_LCS.cpp -o 110__16-05-2026_LCS } ; if ($?) { .\110__16-05-2026_LCS }
3
*/

