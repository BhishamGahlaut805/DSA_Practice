/*
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
You must implement a solution with a linear runtime complexity and use only constant extra space.
*/

#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int ans = 0;
        for (int num : nums)
        {
            ans = ans ^ num;
        }
        return ans;
    }
};
int main()
{
    Solution sol;
    vector<int> nums={1,1, 2, 2, 3};
    cout<<sol.singleNumber(nums);   //TC:O(n), SC:O(1)

    /*
    Output;
    PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 4_16-03-2026_Single_Number.cpp -o 4_16-03-2026_Single_Number } ; if ($?) { .\4_16-03-2026_Single_Number }
3
    */
}