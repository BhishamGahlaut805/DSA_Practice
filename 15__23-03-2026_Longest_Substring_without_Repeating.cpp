// Given a string s, find the length of the longest substring without duplicate characters.

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int l = 0, r = 0;
        int ans = 0;

        unordered_set<int> st;
        while (r < s.size())
        {
            //Not found case
            if (st.find(s[r]) == st.end())
            {
                st.insert(s[r]);
                ans = max(ans, r - l + 1);
                r++;
            }
            else
            {
                st.erase(s[l]);
                l++;
            }
        }
        return ans;
    }
};

int main(){
    Solution sol;
   cout<< sol.lengthOfLongestSubstring("abcabcbb");     //TC:O(n),SC:O(n)
}
/*
Output:
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 15__23-03-2026_Longest_Substring_without_Repeating.cpp -o 15__23-03-2026_Longest_Substring_without_Repeating } ; if ($?) { .\15__23-03-2026_Longest_Substring_without_Repeating }
3
*/
