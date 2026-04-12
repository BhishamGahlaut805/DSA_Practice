// Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int n;
    bool isPalindrome(int l, int r, string s)
    {
        while (l < r)
        {
            if (s[l] != s[r])
            {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    void solve(vector<vector<string>> &ans, vector<string> &tmp, string &s, int i)
    {
        if (i == n)
        {
            ans.push_back(tmp);
            return;
        }
        for (int j = i; j < s.length(); j++)
        {
            if (isPalindrome(i, j, s))
            {
                tmp.push_back(s.substr(i, j - i + 1));
                solve(ans, tmp, s, j + 1);
                tmp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s)
    {
        n = s.length();
        vector<vector<string>> ans;
        vector<string> tmp;
        solve(ans, tmp, s, 0);
        return ans;
    }
};

int main(){

Solution sol;
string s="aab";
vector<vector<string>>ans=sol.partition(s); //TC:O(2^N) ,SC:O(N)
for(auto i:ans){
    for(auto j:i){
        cout<<j<<" ";
    }
    cout<<endl;
}

}
/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 42__02-04-2026_Palindrome_Partioning.cpp -o 42__02-04-2026_Palindrome_Partioning } ; if ($?) { .\42__02-04-2026_Palindrome_Partioning }
a a b
aa b
*/
