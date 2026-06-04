/*
On a 2D plane, we place n stones at some integer coordinate points. Each coordinate point may have at most one stone.

A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.

Given an array stones of length n where stones[i] = [xi, yi] represents the location of the ith stone, return the largest possible number of stones that can be removed.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int removeStones(vector<vector<int>> &stones)
    {
        int n = stones.size();
        vector<bool> visited(n, 0);
        int result = 0;
        for (int i = 0; i < stones.size(); i++)
        {
            if (!visited[i])
            {

                result += dfs(stones, i, visited, n);
            }
        }
        return result;
    }
    int dfs(vector<vector<int>> &stones, int idx, vector<bool> &visited, int &n)
    {
        visited[idx] = true;
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && (stones[idx][0] == stones[i][0] || stones[idx][1] == stones[i][1]))
            {
                res += (dfs(stones, i, visited, n) + 1);
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> stones = {{0, 0}, {0, 1}, {1, 0}, {1, 2}, {2, 1}, {2, 2}};
    int ans = s.removeStones(stones);    //TC:O(n^2) SC:O(n)
    cout << ans << endl;
    return 0;
}
/*
Approach:
1. We can use Depth First Search (DFS) to explore the connected components of stones that share the same row or column.
2. We maintain a visited array to keep track of which stones have been removed.
3. For each unvisited stone, we perform a DFS to find all connected stones and count how many can be removed.
1. We iterate through each stone and if it is not visited, we call the DFS function to explore all connected stones.
2. The DFS function marks the current stone as visited and recursively visits all stones that share the same row or column.
3. The number of stones that can be removed from a connected component is the size of that component minus one (since we can keep one stone).
4. We sum up the counts of removable stones from all connected components to get the final result
*/
/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 132__02-06_2026__Most_Stones_Removed.cpp -o 132__02-06_2026__Most_Stones_Removed } ; if ($?) { .\132__02-06_2026__Most_Stones_Removed }
5
*/