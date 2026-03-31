/*
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.
*/
#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> ans(nums.size(), 1);

        // Left Prefix product
        int left = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            ans[i] *= left;
            left *= nums[i];
        }
        // Right array product
        int right = 1;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            ans[i] *= right;
            right *= nums[i];
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int>nums={1,2,3,4};
    vector<int>ans=sol.productExceptSelf(nums); //TC:O(n),SC:O(n)
    for(auto i:ans)cout<<i<<" ";
}
/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 18__24-03-2026_Product_OF_Array.cpp -o 18__24-03-2026_Product_OF_Array } ; if ($?) { .\18__24-03-2026_Product_OF_Array }
24 12 8 6
*/
