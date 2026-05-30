/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        // Topological sort + BFS

        vector<vector<int>> graph(numCourses);

        for (auto &e : prerequisites)
        {
            graph[e[1]].push_back(e[0]);
        }
        vector<int> indegree(numCourses, 0);

        for (int i = 0; i < numCourses; i++)
        {
            for (auto neigh : graph[i])
            {
                indegree[neigh]++;
            }
        }

        queue<int> q;

        for (int i = 0; i < numCourses; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
        vector<int> order;

        // BFS
        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            order.push_back(node);
            for (auto &neigh : graph[node])
            {
                indegree[neigh]--;
                if (indegree[neigh] == 0)
                {
                    q.push(neigh);
                }
            }
        }
        // check for cycle existence
        if (order.size() != numCourses)
            return {};

        return order;
    }
};

int main()
{
    Solution sol;
    int numCourses = 4;
    vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    vector<int> order = sol.findOrder(numCourses, prerequisites);   //TC:O(V+E) SC:O(V+E)
    for (int course : order)
    {
        cout << course << " ";
    }
    cout << endl;
    return 0;
}
/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 124__30-05-2026__Course_Schedule.cpp -o 124__30-05-2026__Course_Schedule } ; if ($?) { .\124__30-05-2026__Course_Schedule }
0 1 2 3
*/

