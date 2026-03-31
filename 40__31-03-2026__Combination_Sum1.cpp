/*Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(int index, vector<int> &candidates, int target, vector<vector<int>> &ans, vector<int> &solution)
    {
        if (target == 0)
        {
            ans.push_back(solution);
            return;
        }
        if (index >= candidates.size() || target < 0)
            return;

        if (candidates[index] <= target)
        {
            solution.push_back(candidates[index]);
            solve(index, candidates, target - candidates[index], ans, solution);
            solution.pop_back();
        }
        solve(index + 1, candidates, target, ans, solution);
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> Solution;
        solve(0, candidates, target, ans, Solution);
        return ans;
    }
};

int main(){
    vector<int>candidates={2,3,6,7};
    Solution sol;
    vector<vector<int>>ans=sol.combinationSum(candidates,7);
    /*
   TC: O(n^(target/min(candidates))
    */
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 40__31-03-2026__Combination_Sum1.cpp -o 40__31-03-2026__Combination_Sum1 } ; if ($?) { .\40__31-03-2026__Combination_Sum1 }
2 2 3
7
*/
