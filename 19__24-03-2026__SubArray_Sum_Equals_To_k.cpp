#include<bits/stdc++.h>
using namespace std;
/*
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.
*/

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> prefix(nums.size(), 0);
        prefix[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            prefix[i] = nums[i] + prefix[i - 1];
        }
        unordered_map<int, int> mp;
        int ans = 0;
        for (int i = 0; i < prefix.size(); i++)
        {
            if (prefix[i] == k)
            {
                ans++;
            }
            if (mp.find(prefix[i] - k) != mp.end())
            {
                ans += mp[prefix[i] - k];
            }
            mp[prefix[i]]++;
        }
        return ans;
    }
};

int main(){
    vector<int>nums={1,1,1};
    int k=2;
    Solution sol;
    cout<<sol.subarraySum(nums,k)<<endl;    //TC:O(n),SC:O(n)

}
/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 19__24-03-2026__SubArray_Sum_Equals_To_k.cpp -o 19__24-03-2026__SubArray_Sum_Equals_To_k } ; if ($?) { .\19__24-03-2026__SubArray_Sum_Equals_To_k }
2
*/
