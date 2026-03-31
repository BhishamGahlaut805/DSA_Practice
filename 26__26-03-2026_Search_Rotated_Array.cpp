/*
There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly left rotated at an unknown index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be left rotated by 3 indices and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.
*/

//Strategy: Apply Binary Search and Search in the left and Right range subsequently until the target is found.

#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int st = 0;
        int en = nums.size() - 1;

        while (st <= en)
        {
            int mid = st + (en - st) / 2;
            if (nums[mid] == target)
                return mid;

            else if (nums[mid] >= nums[st])
            {
                if (nums[st] <= target && target <= nums[mid])
                {
                    en = mid - 1;
                }
                else
                {
                    st = mid + 1;
                }
            }
            else
            {
                if (nums[mid] <= target && target <= nums[en])
                {
                    st = mid + 1;
                }
                else
                {
                    en = mid - 1;
                }
            }
        }
        return -1;
    }
};

int main(){
    vector<int>nums={4,5,6,7,0,1,2};
    Solution sol;
    cout<<sol.search(nums,0)<<endl; //TC:O(log(n)) ,SC:O(1)


}

/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 26__26-03-2026_Search_Rotated_Array.cpp -o 26__26-03-2026_Search_Rotated_Array } ; if ($?) { .\26__26-03-2026_Search_Rotated_Array }
4
*/

