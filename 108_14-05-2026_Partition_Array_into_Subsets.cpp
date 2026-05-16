// Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.
#include<bits/stdc++.h>
using namespace std;


class Solution {
    bool solve(vector<int>&nums,int i,int sum,vector<vector<int>>&dp){
        if(sum==0){
            return true;
        }
        if(i<0 || sum<0){
            return false;
        }
        if(dp[i][sum]!=-1){
            return dp[i][sum];
        }
       bool take= solve(nums,i-1,sum-nums[i],dp);
      bool skip= solve(nums,i-1,sum,dp);
       return dp[i][sum]=take|| skip;
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum%2!=0){
            return false;
        }
        int target=sum/2;
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        bool ans=solve(nums,n-1,target,dp);
        return ans;
    }
};

int main(){
    Solution s;
    vector<int>nums={1,5,11,5};
    cout<<s.canPartition(nums)<<endl;   //TC: O(n*sum) where n is the size of the input array and sum is the total sum of the elements in the array. SC: O(n*sum) for the dp array.
    return 0;
}
/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 108_14-05-2026_Partition_Array_into_Subsets.cpp -o 108_14-05-2026_Partition_Array_into_Subsets } ; if ($?) { .\108_14-05-2026_Partition_Array_into_Subsets }
1
*/
