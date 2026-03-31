#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        if (s1.length() > s2.length())
        {
            return false;
        }
        unordered_map<int, int> s1Count;
        unordered_map<int, int> s2Count;
        for (int i = 0; i < s1.length(); i++)
        {
            s1Count[s1[i]]++;

            s2Count[s2[i]]++;
        }
        if (s1Count == s2Count)
            return true;
        int left = 0;
        for (int i = s1.length(); i < s2.length(); i++)
        {
            s2Count[s2[i]]++;
            s2Count[s2[left]]--;
            if (s2Count[s2[left]] == 0)
            {
                s2Count.erase(s2[left]);
            }
            left++;
            if (s1Count == s2Count)
            {
                return true;
            }
        }
        return false;
    }
};

int main(){
    Solution sol;
    string s1="ab";
    string s2="eadiynbano";
   cout<< sol.checkInclusion(s1,s2);  //TC:O(L1+L2), SC:O(L1)
}
/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 35__29-03-2026__String_Permutation.cpp -o 35__29-03-2026__String_Permutation } ; if ($?) { .\35__29-03-2026__String_Permutation }
1
*/
