// Given two strings s and t, return true if t is an anagram of s, and false otherwise.
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
            return false;

        unordered_map<char, int> mp;
        for (auto i : s)
        {
            mp[i]++;
        }
        for (char i : t)
        {
            if (mp.find(i) == mp.end() || mp[i] == 0)
                return false;
            mp[i]--;
        }
        return true;
    }
};
int main(){
    Solution sol;
    string s="anagram";
    string t="nagaram";
    cout<<sol.isAnagram(s,t);   //TC:O(N), SC:O(N)
}

/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 32__28-03-2026_Valid_Anagram.cpp -o 32__28-03-2026_Valid_Anagram } ; if ($?) { .\32__28-03-2026_Valid_Anagram }
1
*/

