// Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int firstUniqChar(string s)
    {
        unordered_map<char, int> mp;
        for (char c : s)
        {
            mp[c]++;
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (mp[s[i]] == 1)
            {
                return i;
            }
        }
        return -1;
    }
};

int main()
{
    string s = "leetcode";
    Solution sol;
    cout << sol.firstUniqChar(s) << endl;   //TC:O(n), SC:O(1) since there are only 26 lowercase letters
    return 0;
}
/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 81__24-04-2026_First_non_repeating_element.cpp -o 81__24-04-2026_First_non_repeating_element } ; if ($?) { .\81__24-04-2026_First_non_repeating_element }
0
*/

