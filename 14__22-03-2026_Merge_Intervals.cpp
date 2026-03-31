/*
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        if (intervals.empty())
        {
            return {};
        }
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> res;
        res.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++)
        {
            vector<int> &last = res.back();
            if (intervals[i][0] <= last[1])
            {
                last[1] = max(last[1], intervals[i][1]);
            }
            else
            {
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};

int main(){
    Solution sol;
    vector<vector<int>>intervals={{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>>res=sol.merge(intervals);    //TC:O(n*log(n)), SC:O(n)
    for(auto i:res){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 14__22-03-2026_Merge_Intervals.cpp -o 14__22-03-2026_Merge_Intervals } ; if ($?) { .\14__22-03-2026_Merge_Intervals }
1 6
8 10
15 18
*/
