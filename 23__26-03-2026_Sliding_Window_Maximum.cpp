/*
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.
*/
// Using a monotonic decreasing deque to maintain indices of potential maximums within the sliding window.

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> ans;
        deque<int> dq;
        for (int i = 0; i < n; i++)
        {
            // Keeping only K elements in the deque
            while (!dq.empty() && dq.front() <= i - k)
            {
                dq.pop_front();
            }
            // Maintaining the decreasing order in deque
            while (!dq.empty() && nums[dq.back()] <= nums[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);
            if (i >= k - 1)
            {
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int>nums={1,3,-1,-3,5,3,6,7};
    vector<int>ans=sol.maxSlidingWindow(nums,3);   //TC:O(n), SC:O(n)
    for(int i:ans){
        cout<<i<<" ";
    }
}
/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 23__26-03-2026_Sliding_Window_Maximum.cpp -o 23__26-03-2026_Sliding_Window_Maximum } ; if ($?) { .\23__26-03-2026_Sliding_Window_Maximum }
3 3 5 5 6 7
*/
