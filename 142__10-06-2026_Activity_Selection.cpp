/*
Given a set of activities, each with a start time and a finish time, represented by the arrays start[] and finish[], respectively. A single person can perform only one activity at a time, meaning no two activities can overlap. Your task is to determine the maximum number of activities that a person can complete in a day.

Note: Start time and finish time cannot overlap, i.e., if a person finishes an activity at time x, then they cannot start another activity at time x.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static bool cmp(const pair<int, int> &a, const pair<int, int> &b)
    {
        if (a.first == b.first)
        {
            return a.second < b.second;
        }
        return a.first < b.first;
    }
    int activitySelection(vector<int> &start, vector<int> &finish)
    {
        // code here
        vector<pair<int, int>> jobs;
        for (int i = 0; i < start.size(); i++)
        {
            jobs.push_back({finish[i], start[i]});
        }
        sort(jobs.begin(), jobs.end(), cmp);

        int ans = 1;
        int prevEnd = jobs[0].first;
        for (int i = 1; i < start.size(); i++)
        {
            int currStart = jobs[i].second;
            if (currStart > prevEnd)
            {
                ans++;
                prevEnd = jobs[i].first;
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> finish = {2, 4, 6, 7, 9, 9};
    cout << s.activitySelection(start, finish); //TC:O(NlogN) SC:O(N)
}
/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 142__10-06-2026_Activity_Selection.cpp -o 142__10-06-2026_Activity_Selection } ; if ($?) { .\142__10-06-2026_Activity_Selection }
4
*/
