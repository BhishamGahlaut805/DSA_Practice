#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        bool ans = true;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                st.push(s[i]);
            }
            else if (s[i] == ')')
            {
                if (!st.empty() && st.top() == '(')
                {
                    st.pop();
                }
                else
                {
                    ans = false;
                    break;
                }
            }

            else if (s[i] == '}')
            {
                if (!st.empty() && st.top() == '{')
                {
                    st.pop();
                }
                else
                {
                    ans = false;
                    break;
                }
            }

            else if (s[i] == ']')
            {
                if (!st.empty() && st.top() == '[')
                {
                    st.pop();
                }
                else
                {
                    ans = false;
                    break;
                }
            }
        }
        if (!st.empty())
            ans = false;
        return ans;
    }
};

int main(){
    Solution sol;
    string s="{{}{}{}([])}";
    cout<<sol.isValid(s);   //TC:O(N),SC:O(N)
}
/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 71__18-04-2026_Valid_Parentheses.cpp -o 71__18-04-2026_Valid_Parentheses } ; if ($?) { .\71__18-04-2026_Valid_Parentheses }
1
*/
