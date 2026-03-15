/*You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non - decreasing order.The final sorted array should not be returned by the function,but instead be stored inside the array nums1.To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored.nums2 has a length of n.*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = m;
        for (int j = 0; j < n; j++)
        {
            nums1[i] = nums2[j];
            i++;
        }
        sort(nums1.begin(), nums1.end());
    }
};
class Solution_Optimised
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while (j >= 0)
        {
            if (i >= 0 && nums1[i] > nums2[j])
            {
                nums1[k--] = nums1[i--];
            }
            else
            {
                nums1[k--] = nums2[j--];
            }
        }
    }
};
int main(){
    vector<int> nums1 = {1, 3, 4, 6, 7, 8, 9, 0, 0, 0, 0, 0, 0};
    vector<int> nums2 = {11, 21, 22, 23, 34, 55};
    Solution sol1;
    sol1.merge(nums1, 7, nums2, 6); //T.C: O((m+n)log(m+n)), S.C:O(1)
    Solution_Optimised sol;
    sol.merge(nums1, 7, nums2, 6);  //TC:O(m+n), SC:O(1)

    for (auto &i : nums1)
    {
        cout << i << " ";
    }
    /*
    Output:
    PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 3__15-03-2026_Merge_Sorted.cpp -o 3__15-03-2026_Merge_Sorted } ; if ($?) { .\3__15-03-2026_Merge_Sorted }
1 3 4 6 7 8 9 11 21 22 23 34 55
    */
}
