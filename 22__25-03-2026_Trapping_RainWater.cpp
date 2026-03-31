/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
*/
#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int left = 0;
        int right = height.size() - 1;
        int leftMax = height[left];
        int rightMax = height[right];
        int ans = 0;

        while (left < right)
        {
            if (leftMax < rightMax)
            {
                left++;
                leftMax = max(leftMax, height[left]);
                ans += leftMax - height[left];
            }
            else
            {
                right--;
                rightMax = max(rightMax, height[right]);
                ans += rightMax - height[right];
            }
        }
        return ans;
    }
};
int main(){
    Solution sol;
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
     cout << sol.trap(height) << endl; // TC:O(N),SC:O(1)

}

/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 22__25-03-2026_Trapping_RainWater.cpp -o 22__25-03-2026_Trapping_RainWater } ; if ($?) { .\22__25-03-2026_Trapping_RainWater }
6
*/
