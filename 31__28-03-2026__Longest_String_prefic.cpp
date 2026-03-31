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
int main(){
    Solution sol;
    vector<string> strs = {"flower", "flow", "flight"};
    string ans = sol.longestCommonPrefix(strs); // TC:O(min(strs[i].size())) ,SC:O(1)
    cout<<ans<<endl;
}

/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 31__28-03-2026__Longest_String_prefic.cpp -o 31__28-03-2026__Longest_String_prefic } ; if ($?) { .\31__28-03-2026__Longest_String_prefic }
fl
*/

