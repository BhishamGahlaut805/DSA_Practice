/*
In this problem, a tree is an undirected graph that is connected and has no cycles.

You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.

Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.
*/
#include <bits/stdc++.h>
using namespace std;

class UnionFind
{
public:
    vector<int> parent, size;
    UnionFind(int n)
    {
        parent.resize(n);
        size.resize(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }
    // Path Compression
    int find(int x)
    {
        if (x == parent[x])
        {
            return x;
        }
        return parent[x] = find(parent[x]);
    }
    // Union
    bool Union(int u, int v)
    {
        int pu = find(u);
        int pv = find(v);
        if (pu == pv)
            return false; // return false if pu and pv are already in Union
        if (size[pu] > size[pv])
        {
            size[pu] += size[pv]; // union by having larger size
            parent[pv] = pu;
        }
        else
        {
            size[pv] += size[pu];
            parent[pu] = pv;
        }

        return true;
    }
};
class Solution
{
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        int n = edges.size();
        UnionFind uf(n);
        for (auto &e : edges)
        {
            if (!uf.Union(e[0] - 1, e[1] - 1))
            {
                return {e[0], e[1]};
            }
        }
        return {};
    }
};
int main()
{
    Solution sol;
    vector<vector<int>> edges = {{1, 2}, {1, 3}, {2, 3}};
    vector<int> ans = sol.findRedundantConnection(edges);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}
/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 114__20-05-2026__Redundant_Connection_Cycle_detection.cpp -o 114__20-05-2026__Redundant_Connection_Cycle_detection } ; if ($?) { .\114__20-05-2026__Redundant_Connection_Cycle_detection }
2 3
*/
