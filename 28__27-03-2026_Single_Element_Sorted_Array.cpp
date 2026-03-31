/*
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int st = 0;
        int en = nums.size() - 1;

        while (st < en)
        {
            int mid = st + (en - st) / 2;
            if (mid % 2 == 1)
            {
                mid = mid - 1;
            }
            if (nums[mid] == nums[mid + 1])
            {
                st = mid + 2;
            }
            else
            {
                en = mid;
            }
        }
        return nums[st];
    }
};

int main(){

    Solution sol;
    vector<int>nums={1,1,2,3,3,4,4,8,8};
    cout<<sol.singleNonDuplicate(nums); //TC:O(log(N)), SC:O(1)
}

/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 28__27-03-2026_Single_Element_Sorted_Array.cpp -o 28__27-03-2026_Single_Element_Sorted_Array } ; if ($?) { .\28__27-03-2026_Single_Element_Sorted_Array }
2
*/
