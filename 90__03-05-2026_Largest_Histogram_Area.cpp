// Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.
#include <bits/stdc++.h>
using namespace std;

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

int main()
{
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    Solution sol;
    cout << sol.largestRectangleArea(heights) << endl; // TC: O(n), SC: O(n)
    return 0;
}
/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 90__03-05-2026_Largest_Histogram_Area.cpp -o 90__03-05-2026_Largest_Histogram_Area } ; if ($?) { .\90__03-05-2026_Largest_Histogram_Area }
10
*/

