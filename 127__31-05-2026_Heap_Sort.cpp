#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void buildMaxHeap(vector<int>&nums,int n){
        //Building a maxHeap from the last leaf node and move to the root of the tree
        for(int i=n/2-1;i>=0;i--){
            maxHeapify(nums,i,n);   //Ensure each subtree is a maxHeap
        }
    }
    void maxHeapify(vector<int>&nums,int i,int n){
        int l = 2 * i + 1; // Index of left node
        int r = 2 * i + 2; // Index of right node
        int largest = i;   // Assume the largest element is the root

        if(l<n && nums[l]>nums[largest]){
            largest=l;
        }
        if(r<n && nums[r]>nums[largest]){
            largest=r;
        }
        if(largest!=i){
            swap(nums[i],nums[largest]);
            maxHeapify(nums,largest,n);
        }
    }
    vector<int> sortArray(vector<int> &nums)
    {
        int n=nums.size();
        buildMaxHeap(nums,n);
        for(int i=n-1;i>=0;i--){
            swap(nums[0],nums[i]);
            maxHeapify(nums,0,i);
        }
        return nums;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {5, 2, 3, 1};
    vector<int> ans = s.sortArray(nums);    //TC:O(nlogn) SC:O(1)
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 131__01-06-2026_Heap_Sort.cpp -o 131__01-06-2026_Heap_Sort } ; if ($?) { .\131__01-06-2026_Heap_Sort }
1 2 3 5
*/
