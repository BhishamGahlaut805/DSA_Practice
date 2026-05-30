/*
You are given an array of n pairs pairs where pairs[i] = [lefti, righti] and lefti < righti.

A pair p2 = [c, d] follows a pair p1 = [a, b] if b < c. A chain of pairs can be formed in this fashion.

Return the length longest chain which can be formed.

You do not need to use up all the given intervals. You can select pairs in any order.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        return a[1] < b[1];
    }
    int findLongestChain(vector<vector<int>> &pairs)
    {
        sort(pairs.begin(), pairs.end(), cmp);
        int ans = 1;
        vector<int> prev = pairs[0];
        for (int i = 1; i < pairs.size(); i++)
        {
            vector<int> curr = pairs[i];

            if (curr[0] > prev[1])
            {
                ans++;
                prev = curr;
            }
        }

        return ans;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> pairs = {{1, 2}, {2, 3}, {3, 4}};
    cout << s.findLongestChain(pairs) << endl;  //TC: O(nlogn) SC: O(1)
    return 0;
}
/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 123__29-05-2026__Maximum_Pair_Length.cpp -o 123__29-05-2026__Maximum_Pair_Length } ; if ($?) { .\123__29-05-2026__Maximum_Pair_Length }
2
*/

