// Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

#include<bits/stdc++.h>
using namespace std;
//Strategy: Keep the vectors of left and right to keep the values of (nearest height) -> width in left and right of a element using monotonic stack

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> left(n);
        vector<int> right(n);
        stack<int> stk;

        // Filling the left vector(nearest smaller)
        for (int i = 0; i < n; i++)
        {
            while (!stk.empty() && heights[stk.top()] >= heights[i])
            {
                stk.pop();
            }
            left[i] = stk.empty() ? -1 : stk.top();
            stk.push(i);
        }
        // Empty the stack
        while (!stk.empty())
            stk.pop();

        // Filling the right vector(nearest smaller)
        for (int i = n - 1; i >= 0; i--)
        {
            while (!stk.empty() && heights[stk.top()] >= heights[i])
            {
                stk.pop();
            }
            right[i] = stk.empty() ? n : stk.top();
            stk.push(i);
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int width = right[i] - left[i] - 1;
            ans = max(ans, heights[i] * width);
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int>heights={2,1,5,6,2,3};
   cout<< sol.largestRectangleArea(heights);    //TC:O(N), SC:O(N)

}

/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 25__26-03-2026__Maximum_Area_Histogram.cpp -o 25__26-03-2026__Maximum_Area_Histogram } ; if ($?) { .\25__26-03-2026__Maximum_Area_Histogram }
10
*/

