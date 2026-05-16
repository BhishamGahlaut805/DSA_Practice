/*You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int solve(vector<int> &nums, int target, int st)
    {
        if (st == nums.size())
        {
            return (target == 0) ? 1 : 0;
        }
        int plus = solve(nums, target + nums[st], st + 1);
        int minus = solve(nums, target - nums[st], st + 1);
        return plus + minus;
    }

    int findTargetSumWays(vector<int> &nums, int target)
    {
        int ans = solve(nums, target, 0);
        return ans;
    }
};
class Solution_Optimized        //TC:O(n*sum) , SC:O(n*sum) for the dp array.
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        unordered_map<int, int> counter;
        counter[0] = 1;

        for (int n : nums)
        {
            unordered_map<int, int> tmp;
            for (const auto i : counter)
            {
                tmp[i.first + n] += i.second;
                tmp[i.first - n] += i.second;
            }
            counter = tmp;
        }
        return counter[target];
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;
    cout << s.findTargetSumWays(nums, target) << endl; //TC: O(2^n) where n is the size of the input array. SC: O(n) for the recursive call stack.
    return 0;
}
/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 109__15-05-2026_Target_Sum.cpp -o 109__15-05-2026_Target_Sum } ; if ($?) { .\109__15-05-2026_Target_Sum }
5
*/

