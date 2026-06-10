/*
We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i], obtaining a profit of profit[i].

You're given the startTime, endTime and profit arrays, return the maximum profit you can take such that there are no two jobs in the subset with overlapping time range.

If you choose a job that ends at time X you will be able to start another job that starts at time X.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
    {
        int numJobs = profit.size();
        vector<tuple<int, int, int>> jobs(numJobs);

        for (int i = 0; i < numJobs; i++)
        {
            jobs[i] = {endTime[i], startTime[i], profit[i]};
        }
        sort(jobs.begin(), jobs.end());
        vector<int> dp(numJobs + 1, 0);

        vector<int> eT; // As order of EndTime Changes after Sorting
        for (int i = 0; i < numJobs; i++)
        {
            // auto [en, st, p] = jobs[i];
            eT.push_back(get<0>(jobs[i]));
        }
        for (int i = 0; i < numJobs; i++)
        {
            // auto [en, st, p] = jobs[i];

            // find first Job having Time > currentEndTime using binary Search
            int index = upper_bound(eT.begin(), eT.end(), get<1>(jobs[i])) - eT.begin();
            dp[i + 1] = max(dp[i], dp[index] + get<2>(jobs[i]));
        }
        return dp[numJobs];
    }
};
int main()
{
    Solution s;
    vector<int> startTime = {1, 2, 3, 3};
    vector<int> endTime = {3, 4, 5, 6};
    vector<int> profit = {50, 10, 40, 70};
    cout << s.jobScheduling(startTime, endTime, profit); //TC:O(NlogN) SC:O(N)
}
/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 141__10-06-2026_Maximum_Profit_in_Job_Scheduling.cpp -o 141__10-06-2026_Maximum_Profit_in_Job_Scheduling } ; if ($?) { .\141__10-06-2026_Maximum_Profit_in_Job_Scheduling }
120
*/
