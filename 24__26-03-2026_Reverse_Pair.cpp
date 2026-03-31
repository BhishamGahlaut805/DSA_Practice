#include<bits/stdc++.h>
using namespace std;

/*
Given an integer array nums, return the number of reverse pairs in the array.

A reverse pair is a pair (i, j) where:

0 <= i < j < nums.length and
nums[i] > 2 * nums[j].
*/

class Solution
{
public:
    int reversePairs(vector<int> &nums)
    {
        int n = nums.size();
        return MergeSort(nums, 0, n - 1);
    }
    int MergeSort(vector<int> &nums, int p, int r)
    {
        int ans = 0;
        if (p < r)
        {
            int q = p + (r - p) / 2;
            ans += MergeSort(nums, p, q);
            ans += MergeSort(nums, q + 1, r);
            ans += Count_Pairs(nums, p, q, r);

            merge(nums, p, q, r);
        }
        return ans;
    }
    int Count_Pairs(vector<int> &nums, int p, int q, int r)
    {
        int ans = 0;
        int right = q + 1;
        for (int left = p; left <= q; left++)
        {
            while (right <= r && nums[left] > 2LL * nums[right])
            {
                right++;
            }
            ans += (right - q - 1);
        }
        return ans;
    }
    void merge(vector<int> &nums, int p, int q, int r)
    {
        int n1 = q - p + 1;
        int n2 = r - q;
        vector<int> L(n1);
        vector<int> R(n2);
        for (int i = 0; i < n1; i++)
        {
            L[i] = nums[p + i];
        }
        for (int i = 0; i < n2; i++)
        {
            R[i] = nums[q + i + 1];
        }
        int i = 0, j = 0, k = p;
        while (i < n1 && j < n2)
        {
            if (L[i] <= R[j])
            {
                nums[k++] = L[i++];
            }
            else
            {
                nums[k++] = R[j++];
            }
        }
        while (i < n1)
        {
            nums[k++] = L[i++];
        }
        while (j < n2)
        {
            nums[k++] = R[j++];
        }
    }
};
int main(){
    vector<int>nums={1,3,2,3,1};
    Solution sol;
    cout<<sol.reversePairs(nums);   //TC:O(N*(log(N)))  , SC:O(N)
}
/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 24__26-03-2026_Reverse_Pair.cpp -o 24__26-03-2026_Reverse_Pair } ; if ($?) { .\24__26-03-2026_Reverse_Pair }
2
*/
