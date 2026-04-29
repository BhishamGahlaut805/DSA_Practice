/*
Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.

The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> st;

        for (int i = 0; i < 2 * n; i++)
        {
            int num = nums[i % n];
            while (!st.empty() && nums[st.top()] < num)
            {
                res[st.top()] = num;
                st.pop();
            }
            if (i < n)
                st.push(i);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 1};
    vector<int> result = sol.nextGreaterElements(nums); // TC:O(n), SC:O(n)
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;

}
/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 83__26-04-2026_Next_Greater_Element2.cpp -o 83__26-04-2026_Next_Greater_Element2 } ; if ($?) { .\83__26-04-2026_Next_Greater_Element2 }
2 -1 2
*/


