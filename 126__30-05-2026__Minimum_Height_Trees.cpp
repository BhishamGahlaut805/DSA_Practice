/*
A tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.

Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges where edges[i] = [ai, bi] indicates that there is an undirected edge between the two nodes ai and bi in the tree, you can choose any node of the tree as the root. When you select a node x as the root, the result tree has height h. Among all possible rooted trees, those with minimum height (i.e. min(h))  are called minimum height trees (MHTs).

Return a list of all MHTs' root labels. You can return the answer in any order.

The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        if (n == 0)
            return {};
        if (n == 1)
            return {0};
        vector<int> res;
        vector<int> indegree(n, 0);
        vector<vector<int>> adj(n);
        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            indegree[edges[i][1]]++;
            indegree[edges[i][0]]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 1)
            {
                q.push(i);
            }
        }
        vector<int> ans;
        while (!q.empty())
        {

            ans.clear();
            int size = q.size();
            // level order traversal
            for (int i = 0; i < size; i++)
            {
                int curr = q.front();
                q.pop();
                ans.push_back(curr);
                for (auto &neigh : adj[curr])
                {
                    indegree[neigh]--;
                    if (indegree[neigh] == 1)
                    {
                        q.push(neigh);
                    }
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    int n = 4;
    vector<vector<int>> edges = {{1, 0}, {1, 2}, {1, 3}};

    vector<int> res = sol.findMinHeightTrees(n, edges);
    for (auto &x : res)
    {
        cout << x << " ";
    }
    cout << endl; // TC:O(N) SC:O(N)

    return 0;
}
/*
Approach: We can use the concept of topological sort to solve this problem. We will start with the leaf nodes (nodes with degree 1) and keep removing them until we are left with 1 or 2 nodes. These remaining nodes will be the roots of the minimum height trees.

We have used Topological sort because we are removing the leaf nodes level by level, which is similar to the way we do topological sort in a directed graph. The only difference is that we are dealing with an undirected graph here, so we need to keep track of the degree of each node and remove the edges accordingly.
*/
/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 26__30-05-2026__Minimum_Height_Trees.cpp -o 26__30-05-2026__Minimum_Height_Trees } ; if ($?) { .\26__30-05-2026__Minimum_Height_Trees }
1
*/

