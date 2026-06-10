/*
Given an integer n, return a list of all simplified fractions between 0 and 1 (exclusive) such that the denominator is less-than-or-equal-to n. You can return the answer in any order.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int gcd(int a,int b){
        if(b==0) return a;
        return gcd(b,a%b);
    }
    vector<string> simplifiedFractions(int n) {
        vector<string>ans;
        for(int i=2;i<=n;i++){
            for(int j=1;j<i;j++){
                if(gcd(i,j)==1){
                    ans.push_back(to_string(j)+"/"+to_string(i));
                }
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    int n=4;
    vector<string>ans=s.simplifiedFractions(n); //TC:O(N^2*logN) SC:O(N^2)
    for(auto i:ans){
        cout<<i<<" ";
    }
}
/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 140__09-06-2026_Simplified_Fractions.cpp -o 140__09-06-2026_Simplified_Fractions } ; if ($?) { .\140__09-06-2026_Simplified_Fractions }
1/2 1/3 2/3 1/4 3/4
*/
