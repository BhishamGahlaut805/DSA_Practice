/*
A string is called a happy prefix if is a non-empty prefix which is also a suffix (excluding itself).

Given a string s, return the longest happy prefix of s. Return an empty string "" if no such prefix exists.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string longestPrefix(string s)
    {
        vector<int> dp(s.size());
        int j = 0;
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] == s[j])
            {
                j++;
                dp[i] = j;
            }
            else if (j > 0)
            {
                j = dp[j - 1];
                i--;
            }
        }
        return s.substr(0, j);
    }
};

int main(){
    Solution sol;
    string s="level";
    cout<<sol.longestPrefix(s);// TC:O(N), SC:O(N)

}
/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 39__31-03-2026_Longest_Happy_Prefix_KMP.cpp -o 39__31-03-2026_Longest_Happy_Prefix_KMP } ; if ($?) { .\39__31-03-2026_Longest_Happy_Prefix_KMP }
l
*/

