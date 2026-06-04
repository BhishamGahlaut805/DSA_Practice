/*
Given an integer array nums, find a subarray that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.

Note that the product of an array with a single element is the value of that element.
*/

/*
Approach :
Initialize res with max(nums):

This handles edge cases where the input contains only one number or all numbers are negative.
Track cur_max and cur_min:

cur_max: The maximum product ending at the current position.
cur_min: The minimum product ending at the current position. This is crucial because a negative number multiplied by another negative number can result in a larger positive product.
Iterate Through the Array:

For each element n, calculate the potential maximum and minimum products by considering:
The product of the current cur_max with n.
The product of the current cur_min with n.
The current number n itself (in case starting fresh is better).
Update res:

Keep track of the global maximum product seen so far.

*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int res = *max_element(nums.begin(), nums.end());
        int currMax = 1, currMin = 1;
        for (int n : nums)
        {
            int temp = currMax * n;
            currMax = max({temp, currMin * n, n});
            currMin = min({temp, currMin * n, n});
            res = max(res, currMax);
        }
        return res;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {2, 3, -2, 4}; // TC:O(n), SC:O(1)
    cout << sol.maxProduct(nums);
}
/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 135__04-06-2026__Maximum_Product_SubArray.cpp -o 135__04-06-2026__Maximum_Product_SubArray } ; if ($?) { .\135__04-06-2026__Maximum_Product_SubArray }
6
*/

