// Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(auto i:nums){
            mp[i]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        for(auto i:mp){
            pq.push({i.second,i.first});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<int>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};

class Solution_Optimized_Using_QuickSelect
//TC:O(N) on average, O(N^2) in worst case, SC:O(N)
{
public:
    int partition(vector<pair<int, int>> &freq, int left, int right)
    {
        int pivot = freq[right].second;
        int i = left;
        for (int j = left; j < right; j++)
        {
            if (freq[j].second > pivot)
            {
                swap(freq[i], freq[j]);
                i++;
            }
        }
        swap(freq[i], freq[right]);
        return i;
    }
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        for (auto i : nums)
        {
            mp[i]++;
        }
        vector<pair<int, int>> freq(mp.begin(), mp.end());
        int n = freq.size();
        int left = 0, right = n - 1;
        while (left <= right)
        {
            int pivotIndex = partition(freq, left, right);
            if (pivotIndex == k - 1)
            {
                break;
            }
            else if (pivotIndex < k - 1)
            {
                left = pivotIndex + 1;
            }
            else
            {
                right = pivotIndex - 1;
            }
        }
        vector<int> ans;
        for (int i = 0; i < k; i++)
        {
            ans.push_back(freq[i].first);
        }
        return ans;
    }
};
int main(){
    Solution s;
    vector<int>nums={1,1,1,2,2,3};
    int k=2;
    vector<int>ans=s.topKFrequent(nums,k);  //TC:O(NlogK) SC:O(N)
    for(auto i:ans){
        cout<<i<<" ";
    }
}
/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 128__31-05-2026_Top_K_Frequent.cpp -o 128__31-05-2026_Top_K_Frequent } ; if ($?) { .\128__31-05-2026_Top_K_Frequent }
2 1
*/

