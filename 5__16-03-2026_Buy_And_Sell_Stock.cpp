/*You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.Return the maximum profit you can achieve from this transaction.If you cannot achieve any profit,return 0.*/
#include<bits/stdc++.h>

using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();

        int minPrice = prices[0];
        int maxProfit = 0;
        for (int i = 1; i < n; i++)
        {
            if (prices[i] < minPrice)
            {
                minPrice = prices[i];
            }
            maxProfit = max(maxProfit, prices[i] - minPrice);
        }
        return maxProfit;
    }
};
int main(){
    Solution sol;
    vector<int>prices={7,1,5,3,6,4};    //TC:O(n), SC:O(1)
    cout<<sol.maxProfit(prices);
}

/*
Output:
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 5__16-03-2026_Buy_And_Sell_Stock.cpp -o 5__16-03-2026_Buy_And_Sell_Stock } ; if ($?) { .\5__16-03-2026_Buy_And_Sell_Stock }
5
*/