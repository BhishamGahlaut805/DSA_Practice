#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(vector<int> &nums, vector<vector<int>> &ans, vector<int> &temp, int idx)
    {

        ans.push_back(temp);
        for (int j = idx; j < nums.size(); j++)
        {
            if (j > idx && nums[j] == nums[j - 1])
                continue;
            temp.push_back(nums[j]);
            solve(nums, ans, temp, j + 1);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        solve(nums, ans, temp, 0);
        return ans;
    }
};

int main(){

    Solution sol;
    vector<int>nums={1,2,3};
   vector<vector<int>>ans= sol.subsetsWithDup(nums);    //TC:O(2^N), SC:O(N)- Recursive Stack
   for(auto &i:ans){
    for(auto j:i){
        cout<<j<<" ";
    }
    cout<<endl;
   }
}

/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 45__05-04-2026__Subsets2.cpp -o 45__05-04-2026__Subsets2 } ; if ($?) { .\45__05-04-2026__Subsets2 }

1
1 2
1 2 3
1 3
2
2 3
3
*/
