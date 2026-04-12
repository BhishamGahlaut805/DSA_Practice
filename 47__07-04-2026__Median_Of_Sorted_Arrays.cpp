/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).
*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int totalsize = nums1.size() + nums2.size();
        vector<int> nums(totalsize);
        merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), nums.begin());
        if (totalsize % 2 == 0)
        {
            double i = nums[(totalsize / 2) - 1];
            double j = nums[(totalsize / 2)];
            return (i + j) / 2;
        }
        double ans = (nums[(totalsize / 2)]);
        return ans;
    }
};

class Solution1
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        if (nums1.size() > nums2.size())
        {
            return findMedianSortedArrays(nums2, nums1);
        }

        int len1 = nums1.size(), len2 = nums2.size();
        int left = 0, right = len1;

        while (left <= right)
        {
            int part1 = (left + right) / 2;
            int part2 = (len1 + len2 + 1) / 2 - part1;

            int maxLeft1 = (part1 == 0) ? INT_MIN : nums1[part1 - 1];
            int minRight1 = (part1 == len1) ? INT_MAX : nums1[part1];
            int maxLeft2 = (part2 == 0) ? INT_MIN : nums2[part2 - 1];
            int minRight2 = (part2 == len2) ? INT_MAX : nums2[part2];

            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1)
            {
                if ((len1 + len2) % 2 == 0)
                {
                    return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0;
                }
                else
                {
                    return max(maxLeft1, maxLeft2);
                }
            }
            else if (maxLeft1 > minRight2)
            {
                right = part1 - 1;
            }
            else
            {
                left = part1 + 1;
            }
        }
        return 0.0;
    }
};
int main(){
    Solution1 sol;
    vector<int>nums1={1,3};
    vector<int>nums2={2};
//    double ans= sol.findMedianSortedArrays(nums1,nums2); //TC:O(m+n), SC:O(1)
    double ans = sol.findMedianSortedArrays(nums1, nums2); // TC:O(log(m+n)), SC:O(1)
    cout << ans;
}
/*
2
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 47__07-04-2026__Median_Of_Sorted_Arrays.cpp -o 47__07-04-2026__Median_Of_Sorted_Arrays } ; if ($?) { .\47__07-04-2026__Median_Of_Sorted_Arrays }
2
*/


