/*
There are n people in a line queuing to buy tickets, where the 0th person is at the front of the line and the (n - 1)th person is at the back of the line.

You are given a 0-indexed integer array tickets of length n where the number of tickets that the ith person would like to buy is tickets[i].

Each person takes exactly 1 second to buy a ticket. A person can only buy 1 ticket at a time and has to go back to the end of the line (which happens instantaneously) in order to buy more tickets. If a person does not have any tickets left to buy, the person will leave the line.

Return the time taken for the person initially at position k (0-indexed) to finish buying tickets.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int timeRequiredToBuy(vector<int> &tickets, int k)
    {
        int ans = 0;

        for (int i = 0; i < tickets.size(); i++)
        {
            if (i <= k)
            {
                ans += min(tickets[i], tickets[k]);
            }
            else
            {
                ans += min(tickets[i], tickets[k] - 1);
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> tickets = {2, 3, 2};
    int k = 2;
    cout << sol.timeRequiredToBuy(tickets, k) << endl; // Output: 6//TC O(n) SC O(1)
    return 0;
}
/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 82__25-04-2026_Time_needed_TO_Buy_tickets.cpp -o 82__25-04-2026_Time_needed_TO_Buy_tickets } ; if ($?) { .\82__25-04-2026_Time_needed_TO_Buy_tickets }
6
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP>
*/
