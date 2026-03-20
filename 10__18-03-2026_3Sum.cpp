/* 3Sum Problem
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.
*/
/*
Strategy:Take one pointer as free and other 2 iterating to get the solution in O(n^2)
*/
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k)
            {
                if (nums[i] + nums[j] + nums[k] == 0)
                {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    while (j < k && nums[j] == nums[j - 1])
                    {
                        j++;
                    }
                }

                else if (nums[i] + nums[j] + nums[k] < 0)
                {
                    j++;
                }
                else
                {
                    k--;
                }
            }
        }
        return ans;
    }
};
int main(){
Solution sol;
vector<int>nums={-1,0,1,2,-1,-4};   //TC:O(n^2),SC:O(1)
vector<vector<int>>ans=sol.threeSum(nums);
for(auto row:ans){
    for(auto i:row){
        cout<<i<<" ";
    }
    cout<<endl;
}
}

/*
Output:
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 10__18-03-2026_3Sum.cpp -o 10__18-03-2026_3Sum } ; if ($?) { .\10__18-03-2026_3Sum }
-1 -1 2
-1 0 1
*/