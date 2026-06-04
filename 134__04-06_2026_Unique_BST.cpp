/*
Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numTrees(int n)
    {
        vector<int> G(n + 1);
        // G(n)=G(i-1)*G(n-i); from i to n

        G[0] = 1;
        G[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                G[i] += G[j - 1] * G[i - j];
            }
        }
        return G[n];
    }
};

int main()
{
    Solution sol;
    int n = 3; // TC:O(n^2), SC:O(n)
    cout << sol.numTrees(n);
} /*

PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 134__04-06_2026_Unique_BST.cpp -o 134__04-06_2026_Unique_BST } ; if ($?) { .\134__04-06_2026_Unique_BST }
5
*/
