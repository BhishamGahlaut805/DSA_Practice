/*
There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        unordered_set<int> visited;
        int provinces = 0;

        for (int i = 0; i < isConnected.size(); i++)
        {
            if (visited.find(i) == visited.end())
            {
                dfs(i, isConnected, visited);
                provinces++;
            }
        }
        return provinces;
    }
    void dfs(int city, vector<vector<int>> &isConnected, unordered_set<int> &visited)
    {
        visited.insert(city);
        for (int i = 0; i < isConnected[city].size(); i++)
        {
            int connected = isConnected[city][i];
            if (connected == 1 && visited.find(i) == visited.end())
            {
                // Not visited and Connected (Neighbor)
                dfs(i, isConnected, visited);
            }
        }
    }
};

int main()
{
    Solution s;
    vector<vector<int>> isConnected = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    int ans = s.findCircleNum(isConnected);    //TC:O(n^2) SC:O(n)
    cout << ans << endl;
    return 0;
}
/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 131__02-06-2026_Number_OF_Provinces.cpp -o 131__02-06-2026_Number_OF_Provinces } ; if ($?) { .\131__02-06-2026_Number_OF_Provinces }
2
*/
