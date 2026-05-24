/*
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = i;
        }
        for (int j = 0; j <= m; j++)
        {
            dp[0][j] = j;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1]; // No Operation required
                }
                else
                {
                    // required op:either insert,remove or replace
                    dp[i][j] = 1 + min({
                                       dp[i - 1][j],    // Delete
                                       dp[i][j - 1],    // insert
                                       dp[i - 1][j - 1] // replace
                                   });
                }
            }
        }
        return dp[n][m];
    }
};

int main()
{
    Solution sol;
    string word1 = "horse";
    string word2 = "ros";
    cout << sol.minDistance(word1, word2) << endl; // TC:O(n*m) SC:O(n*m )
    return 0;
}
/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 117__23-05-2026__Edit_Distance_2d_DP.cpp -o 117__23-05-2026__Edit_Distance_2d_DP } ; if ($?) { .\117__23-05-2026__Edit_Distance_2d_DP }
3
*/

