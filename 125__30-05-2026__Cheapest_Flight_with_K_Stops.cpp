/*
There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        // Using Dijkstra's Algorithm
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        for (int i = 0; i <= k; i++)
        {
            vector<int> temp = dist;
            for (auto &flight : flights)
            {
                int u = flight[0];
                int v = flight[1];
                int c = flight[2];

                if (dist[u] != INT_MAX && dist[u] + c < temp[v])
                {
                    temp[v] = dist[u] + c;
                }
            }
            dist = temp;
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};

int main()
{
    Solution sol;
    int n = 3;
    vector<vector<int>> flights = {{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
    int src = 0;
    int dst = 2;
    int k = 1;

    cout << sol.findCheapestPrice(n, flights, src, dst, k) << endl; // TC:O(K*E) SC:O(N)

    return 0;
}
/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 125__30-05-2026__Cheapest_Flight_with_K_Stops.cpp -o 125__30-05-2026__Cheapest_Flight_with_K_Stops } ; if ($?) { .\125__30-05-2026__Cheapest_Flight_with_K_Stops }
200
*/

