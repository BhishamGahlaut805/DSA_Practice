#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeOccurrences(string s, string part)
    {
        int index = s.find(part);
        while (index != string::npos)
        {
            s.erase(index, part.length());
            index = s.find(part);
        }
        return s;
    }
};
class Solution1
{
public:
    string removeOccurrences(string s, string part)
    {
        // Stack based approach - optimised in O(N)
        string resultStack;
        int targetLength = part.size();
        char targetEndChar = part.back();

        for (char i : s)
        {
            resultStack.push_back(i);
            if (i == targetEndChar && resultStack.size() >= targetLength)
            {
                if (resultStack.substr(resultStack.size() - targetLength) == part)
                {
                    resultStack.erase(resultStack.size() - targetLength);
                }
            }
        }
        return resultStack;
    }
};
int main(){

    Solution sol;
    string s = "daabcbaabcbc";
    string part="abc";
    // cout<<sol.removeOccurrences(s,part); //TC:O(N*N), SC:O(1)
    Solution1 sol1;
    cout<<sol1.removeOccurrences(s,part); //TC:O(N), SC:O(1)
}
/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 34__29-03-2026_Remove_Substring.cpp -o 34__29-03-2026_Remove_Substring } ; if ($?) { .\34__29-03-2026_Remove_Substring }
dab
*/
