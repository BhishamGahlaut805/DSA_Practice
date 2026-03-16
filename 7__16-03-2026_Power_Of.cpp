//Power (x,n)
#include<bits/stdc++.h>
using namespace std;
//using Divide and conquer in O(log(n))Time complexity
class Solution
{
public:
    double myPow(double x, int n)
    {
        if (n == 0)
        {
            return 1.0;
        }
        double res = myPow(x, abs(n / 2));
        if (n % 2 == 0)
        {
            if (n > 0)
            {
                return res * res;
            }
            else
            {
                return 1 / (res * res);
            }
        }
        else
        {
            if (n > 0)
            {
                return res * res * x;
            }
            else
            {
                return 1 / (res * res * x);
            }
        }
        return 0.0;
    }
};

int main(){
    Solution sol;
    cout<<sol.myPow(5,3);   

    /*
    Output:
    PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 7__16-03-2026_Power_Of.cpp -o 7__16-03-2026_Power_Of } ; if ($?) { .\7__16-03-2026_Power_Of }
    125
    */
}