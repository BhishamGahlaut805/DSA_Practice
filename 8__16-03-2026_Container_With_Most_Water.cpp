/*You are given an integer array height of length n.There are n vertical lines drawn such that the two endpoints of the ith line are(i, 0) and (i, height[i]).Find two lines that together with the x- axis form a container,such that the container contains the most water.
Return the maximum amount of water a container can store.
Notice that you may not slant the container.*/

#include<bits/stdc++.h>
    using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int ans = INT_MIN;
        int right = height.size() - 1;
        int left = 0;
        while (left < right)
        {
            int width = right - left;
            ans = max(ans, width * min(height[left], height[right]));
            if (height[left] < height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int>nums={1,8,6,2,5,4,8,3,7};
   cout<< sol.maxArea(nums);    //TC:O(n), SC:O(1)

}
/*
Output:
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 8__16-03-2026_Container_With_Most_Water.cpp -o 8__16-03-2026_Container_With_Most_Water } ; if ($?) { .\8__16-03-2026_Container_With_Most_Water }
49
*/