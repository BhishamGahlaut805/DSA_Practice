/*
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(vector<int>& candidates, int target,vector<vector<int>>&ans,vector<int>&curr,int start){
        if(target==0){
            ans.push_back(curr);
            return;
        }

        for(int i=start;i<candidates.size();i++){
            if(i>start && candidates[i]==candidates[i-1]){
                continue;
            }
            if(candidates[i]>target) break;
            curr.push_back(candidates[i]);
            solve(candidates,target-candidates[i],ans,curr,i+1);
            curr.pop_back();

        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>current;
        solve(candidates,target,ans,current,0);
        return ans;
    }
};

int main(){

    Solution sol;
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    vector<vector<int>> ans = sol.combinationSum2(candidates, 8);   //TC:O(2^N), SC:O(N)
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 41__01-04-2026__Combination_Sum2.cpp -o 41__01-04-2026__Combination_Sum2 } ; if ($?) { .\41__01-04-2026__Combination_Sum2 }
1 1 6
1 2 5
1 7
2 6
*/

