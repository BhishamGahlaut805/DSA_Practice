/*
Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

class Node {
    public int val;
    public List<Node> neighbors;
}


Test case format:

For simplicity, each node's value is the same as the node's index (1-indexed). For example, the first node with val == 1, the second node with val == 2, and so on. The graph is represented in the test case using an adjacency list.

An adjacency list is a collection of unordered lists used to represent a finite graph. Each list describes the set of neighbors of a node in the graph.

The given node will always be the first node with val = 1. You must return the copy of the given node as a reference to the cloned graph.

*/

#include <bits/stdc++.h>
using namespace std;
// /*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
// */

class Solution
{
public:
    Node *dfs(Node *curr, unordered_map<Node *, Node *> &mp)
    {
        vector<Node *> neigh;
        Node *clone = new Node(curr->val);
        mp[curr] = clone;
        for (auto it : curr->neighbors)
        {
            if (mp.find(it) != mp.end())
            {
                neigh.push_back(mp[it]);
            }
            else
            {
                neigh.push_back(dfs(it, mp));
            }
        }
        clone->neighbors = neigh;
        return clone;
    }
    Node *cloneGraph(Node *node)
    {
        unordered_map<Node *, Node *> mp;
        if (node == NULL)
        {
            return NULL;
        }
        if (node->neighbors.size() == 0)
        {
            Node *clone = new Node(node->val);
            return clone;
        }
        return dfs(node, mp);
    }
};

int main(){
    Solution sol;
    Node *node = new Node(1);
   Node*newNode= sol.cloneGraph(node);  //TC: O(N) where N is the number of nodes in the graph ,SC: O(N) where N is the number of nodes in the graph (for the hash map and the recursion stack)
    cout<<newNode->val<<endl;
    return 0;
}
/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 113__19-05-2026__Clone_graph.cpp -o 113__19-05-2026__Clone_graph } ; if ($?) { .\113__19-05-2026__Clone_graph }
1
*/
