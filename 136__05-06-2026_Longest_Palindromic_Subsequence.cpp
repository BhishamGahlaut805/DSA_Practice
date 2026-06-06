// Given a string s, find the longest palindromic subsequence's length in s.

// A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int longestPalindromeSubseq(string s)
    {
        int n = s.size();
        string p = s;
        reverse(p.begin(), p.end());
        int m = p.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= n; i++)
        { // normal string
            for (int j = 1; j <= n; j++)
            { // reversed string
                if (s[i - 1] == p[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n][m];
    }
};

int main()
{
    Solution sol;
    string s = "bbbab";
    cout << sol.longestPalindromeSubseq(s) << endl; // TC:O(N*N) SC:O(N*N)
    return 0;
}
/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 136__05-06-2026_Longest_Palindromic_Subsequence.cpp -o 136__05-06-2026_Longest_Palindromic_Subsequence } ; if ($?) { .\136__05-06-2026_Longest_Palindromic_Subsequence }
4
*/

