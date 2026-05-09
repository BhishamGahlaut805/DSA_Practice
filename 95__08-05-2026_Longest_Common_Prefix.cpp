/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string ans = "";
        sort(strs.begin(), strs.end());
        int n = strs.size();
        string first = strs[0], last = strs[n - 1];
        for (int i = 0; i < min(first.size(), last.size()); i++)
        {
            if (first[i] != last[i])
            {
                return ans;
            }
            ans += first[i];
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<string> strs = {"flower", "flow", "flight"};
    cout << sol.longestCommonPrefix(strs); //TC:O(NlogN) SC:O(1)
    return 0;
}
/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 95__08-05-2026_Longest_Common_Prefix.cpp -o 95__08-05-2026_Longest_Common_Prefix } ; if ($?) { .\95__08-05-2026_Longest_Common_Prefix }
fl
*/

