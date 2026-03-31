#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int compress(vector<char> &chars)
    {
        int ans = 0;

        for (int i = 0; i < chars.size();)
        {
            const char curr = chars[i];
            int count = 0;

            while (i < chars.size() && chars[i] == curr)
            {
                count++;
                i++;
            }
            chars[ans++] = curr;
            if (count > 1)
            {
                for (const char c : to_string(count))
                {
                    chars[ans++] = c;
                }
            }
        }
        return ans;
    }
};
int main(){

    Solution sol;
    vector<char>chars={'a','a','a','a','b','b','c','c','c','c','c','c','c'};
    cout<<sol.compress(chars)<<endl;  //TC:O(N), SC:O(1)
    for(auto i:chars){
        cout<<i;
    }
}
/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 36__29-03-2026_String_Compressions.cpp -o 36__29-03-2026_String_Compressions } ; if ($?) { .\36__29-03-2026_String_Compressions }
6
a4b2c7ccccccc
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice>


*/


