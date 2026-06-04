/*
You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can sell and buy the stock multiple times on the same day, ensuring you never hold more than one share of the stock.

Find and return the maximum profit you can achieve.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int profit = 0;
        for (int i = 1; i < n; i++)
        {
            if (prices[i] - prices[i - 1] > 0)
            {
                profit += prices[i] - prices[i - 1];
            }
        }
        return profit;
    }
};
int main()
{
    Solution sol;
    vector<int> prices = {7, 1, 5, 3, 6, 4}; // TC:O(n), SC:O(1)
    cout << sol.maxProfit(prices);
} /*
 PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 133__03-06-2026_Buy_And_Sell_Stocks2.cpp -o 133__03-06-2026_Buy_And_Sell_Stocks2 } ; if ($?) { .\133__03-06-2026_Buy_And_Sell_Stocks2 }
 7
 */

 