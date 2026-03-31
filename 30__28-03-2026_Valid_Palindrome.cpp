/*
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int st = 0;
        int en = s.size() - 1;
        while (st <= en)
        {
            if (!isalnum(s[st]))
            {
                st++;
                continue;
            }
            if (!isalnum(s[en]))
            {
                en--;
                continue;
            }
            if (tolower(s[st]) != tolower(s[en]))
            {
                return false;
            }
            else
            {
                st++;
                en--;
            }
        }
        return true;
    }
};
int main(){
Solution sol;
string s = "A man, a plan, a canal: Panama";
cout<<sol.isPalindrome(s);  //TC:O(n), SC:O(1);


}

/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 30__28-03-2026_Valid_Palindrome.cpp -o 30__28-03-2026_Valid_Palindrome } ; if ($?) { .\30__28-03-2026_Valid_Palindrome }
1
*/
