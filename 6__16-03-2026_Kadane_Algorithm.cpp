//Maximum Subarray Sum

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int ans = nums[0];
        int total = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (total < 0)
            {
                total = 0;
            }
            total += nums[i];
            ans = max(ans, total);
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int>nums={-2,1,-3,4,-1,2,1,-5,4};
    cout<<sol.maxSubArray(nums)<<endl;  //TC:O(n), SC:O(1)

}
/*
Output:

PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice>  cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 6__16-03-2026_Kadane_Algorithm.cpp -o 6__16-03-2026_Kadane_Algorithm } ; if ($?) { .\6__16-03-2026_Kadane_Algorithm }
6
*/