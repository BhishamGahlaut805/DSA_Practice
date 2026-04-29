/*
The min-product of an array is equal to the minimum value in the array multiplied by the array's sum.

For example, the array [3,2,5] (minimum value is 2) has a min-product of 2 * (3+2+5) = 2 * 10 = 20.
Given an array of integers nums, return the maximum min-product of any non-empty subarray of nums. Since the answer may be large, return it modulo 109 + 7.

Note that the min-product should be maximized before performing the modulo operation. Testcases are generated such that the maximum min-product without modulo will fit in a 64-bit signed integer.

A subarray is a contiguous part of an array.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSumMinProduct(vector<int> &nums)
    {
        int n = nums.size();
        const long long MOD = 1e9 + 7;

        // find prefix sum
        vector<long long> prefix(n + 1, 0);

        for (int i = 0; i < n; i++)
        {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        // find the prev smaller element

        vector<int> prev(n, 0);
        stack<int> st;

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && nums[st.top()] >= nums[i])
            {
                st.pop();
            }
            prev[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty())
        {
            st.pop();
        }

        vector<int> next(n, 0);
        // find the next smaller element
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && nums[st.top()] > nums[i])
            {
                st.pop();
            }
            next[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        // finding ans
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            int left = prev[i] + 1;
            int right = next[i] - 1;

            long long subsum = prefix[right + 1] - prefix[left];
            long long product = subsum * nums[i];
            ans = max(ans, product);
        }
        return ans % MOD;
    }
};
/*

The approach is to use a stack to find the previous smaller and next smaller elements for each element in the array. We also calculate the prefix sum of the array to efficiently compute the sum of any subarray.
1. We first calculate the prefix sum of the input array `nums` to allow for O(1) time complexity when calculating the sum of any subarray.
2. We then use a stack to find the index of the previous smaller element for each element in the array. If there is no smaller element to the left, we store -1.
3. We repeat the process in reverse to find the index of the next smaller element for each
element in the array. If there is no smaller element to the right, we store n (the length of the array).
4. Finally, we iterate through each element in the array and calculate the min-product for the
subarray defined by the previous and next smaller elements. We keep track of the maximum min-product found and return it modulo 10^9 + 7.

*/
int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3, 2};
    int result = sol.maxSumMinProduct(nums); // TC:O(n), SC:O(n)
    cout << result << endl;
}

/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 84__27-04-2026_Maximum_Subarray_Min_Product.cpp -o 84__27-04-2026_Maximum_Subarray_Min_Product } ; if ($?) { .\84__27-04-2026_Maximum_Subarray_Min_Product }
14
*/

