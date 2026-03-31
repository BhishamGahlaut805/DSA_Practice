#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> mp;
        for (auto &i : strs)
        {
            array<int, 26> count = {0};
            for (char c : i)
            {
                count[c - 'a']++;
            }
            string key;

            for (int num : count)
            {
                key += to_string(num) + "@"; // Anything just as a key separator
            }
            mp[key].push_back(i);
        }
        vector<vector<string>> ans;
        for (auto i : mp)
        {
            ans.push_back(i.second);
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> ans = sol.groupAnagrams(strs); // TC:O(M*N), SC:O(1) // M=strs.size(), N=strs[0].size();
    for(auto i:ans){
        for(auto j:i){
            cout<<j;
        }
        cout<<" ";
    }
}

/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 37__29-03-2026__Group_Anagrams.cpp -o 37__29-03-2026__Group_Anagrams } ; if ($?) { .\37__29-03-2026__Group_Anagrams }
bat tannat eatteaate
*/


