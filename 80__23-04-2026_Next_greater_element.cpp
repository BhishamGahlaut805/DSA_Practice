/*The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.

You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.

Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> ans;

        for (int num : nums1)
        {

            // find the index of element num in nums2
            int index = 0;
            while (index < nums2.size() && nums2[index] != num)
            {
                index++;
            }

            // find its next greater element in nums2
            int nextgreater = -1;
            for (int j = index + 1; j < nums2.size(); j++)
            {
                if (nums2[j] > num)
                {
                    nextgreater = nums2[j];
                    break;
                }
            }
            ans.push_back(nextgreater);
        }
        return ans;
    }
};
//optimised solution using stack and hashmap TC:O(n+m), SC:O(n)

class Solution1
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> ng;
        stack<int> st;

        for (int num : nums2)
        {
            while (!st.empty() && st.top() < num)
            {
                ng[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }
        vector<int> res;
        for (int num : nums1)
        {
            res.push_back(ng.count(num) ? ng[num] : -1);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    vector<int> ans = sol.nextGreaterElement(nums1, nums2); //TC:O(n*m), SC:O(n)
    for (int num : ans)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}

/*
Solution approach:
1. Brute force approach: For each element in nums1, find its index in nums2 and then find the next greater element to the right of that index in nums2. This approach has a time complexity of O(n*m) where n is the size of nums1 and m is the size of nums2.
2. Optimised approach using stack and hashmap: We can use a stack to keep track of the elements in nums2 and a hashmap to store the next greater element for each element in nums2. We iterate through nums2 and for each element, we pop elements from the stack until we find an element greater than the current element. For each popped element, we store the current element as its next greater element in the hashmap. Finally, we iterate through nums1 and for each element, we check if it exists in the hashmap and add its next greater element to the result vector. This approach has a time complexity of O(n+m) where n is the size of nums1 and m is the size of nums2, and a space complexity of O(n) for the hashmap.

*/
/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 80__23-04-2026_Next_greater_element.cpp -o 80__23-04-2026_Next_greater_element } ; if ($?) { .\80__23-04-2026_Next_greater_element }
-1 3 -1
*/

