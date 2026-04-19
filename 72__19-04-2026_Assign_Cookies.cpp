#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0, j = 0;
        while (i < g.size() && j < s.size())
        {
            if (s[j] >= g[i])
            {
                i++;
            }
            j++;
        }
        return i;
    }
};

int main(){
Solution s;
vector<int>g={1,2,3};
vector<int>s1={1,1};
cout<<s.findContentChildren(g,s1)<<endl;    //TC:O(N*log(N)), SC:O(1)
}
/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 72__19-04-2026_Assign_Cookies.cpp -o 72__19-04-2026_Assign_Cookies } ; if ($?) { .\72__19-04-2026_Assign_Cookies }
1
*/


