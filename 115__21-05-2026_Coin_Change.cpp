/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(vector<int>& coins,int index, int amount,vector<vector<int>>& dp){
        //Base-Case
        if(amount == 0) return 0;
        if(index < 0) return INT_MAX - 1;

        if(dp[index][amount]!=-1){
            return dp[index][amount];
        }
        //Recursive CAse
        int ans=-1;
        if(coins[index]>amount){    //Always excclude if more than amount
            int excl=0+solve(coins,index-1,amount,dp);
            ans=excl;
        }
        else{
            //else either include or exclude recursively and take the minimum
            int incl=1+solve(coins,index-0,amount-coins[index],dp);   //We can take that coin again as we have infinite coins
            int excl=0+solve(coins,index-1,amount-0,dp);    //Amount will not change as we are excluding that coin
            ans=min(incl,excl);
        }
        dp[index][amount]=ans;
        return dp[index][amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans1=solve(coins,n-1,amount,dp);

        if(ans1==INT_MAX-1){
            return -1;
        }
        return ans1;
    }
};
int main(){
    Solution s;
    vector<int> coins={1,2,5};
    int amount=11;
    cout<<s.coinChange(coins,amount)<<endl; //TC: O(N*Amount) SC: O(N*Amount) + O(Amount) for recursive stack space
    return 0;
}
/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 115__21-05-2026_Coin_Change.cpp -o 115__21-05-2026_Coin_Change } ; if ($?) { .\115__21-05-2026_Coin_Change }
3
*/

