/*
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
There is only one repeated number in nums, return this repeated number.
You must solve the problem without modifying the array nums and using only constant extra space.
*/
/*
Approach -> using slow and fast pointers - Hare and Tortoise algorithm of Floyd's Cycle detection
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=nums[0];
        int fast=nums[0];

        while(true){
            slow=nums[slow];
            fast=nums[nums[fast]];
            if(slow==fast){
                break;
            }
        }
        int slow2=nums[0];
        while(slow!=slow2){
            slow=nums[slow];
            slow2=nums[slow2];
        }
        return slow;
    }
};

int main(){

    Solution sol;
    vector<int>nums={1,3,4,2,2};
    cout<<sol.findDuplicate(nums)<<endl;    //TC:O(n), SC:O(1)

}
/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 20__25-03-2026_Find_Missing_Element.cpp -o 20__25-03-2026_Find_Missing_Element } ; if ($?) { .\20__25-03-2026_Find_Missing_Element }
2
*/
