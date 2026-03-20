/*
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.
*/
/*
Take 4 pointers, 3 as iterating and 1 as free to get the solution in O(n^3)
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
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
            for (; j < nums.size(); j++)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                {
                    continue;
                }
                int k = j + 1;
                int l = nums.size() - 1;
                while (k < l)
                {
                    long long currentSum = (long long)nums[i] + nums[j] + nums[k] + nums[l];
                    if (currentSum == target)
                    {
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++;
                        l--; // Better optimised
                        while (k < l && nums[k] == nums[k - 1])
                        {
                            k++;
                        }
                        while (k < l && nums[l] == nums[l + 1])
                        {
                            l--;
                        }
                    }
                    else if (currentSum < target)
                    {
                        k++;
                    }
                    else
                    {
                        l--;
                    }
                }
            }
        }
        return ans;
    }
};
int main(){
    Solution sol;
    vector<int> nums = {-1, 0, 1, 0,-2,2}; // TC:O(n^3),SC:O(1)
    vector<vector<int>> ans = sol.fourSum(nums,0);
    for (auto row : ans)
    {
        for (auto i : row)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}

/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 11__19-03-2026_4Sum.cpp -o 11__19-03-2026_4Sum } ; if ($?) { .\11__19-03-2026_4Sum }
-2 -1 1 2
-2 0 0 2
-1 0 0 1
*/
