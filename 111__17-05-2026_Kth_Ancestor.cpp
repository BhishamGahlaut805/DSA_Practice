/*
You are given a tree with n nodes numbered from 0 to n - 1 in the form of a parent array parent where parent[i] is the parent of ith node. The root of the tree is node 0. Find the kth ancestor of a given node.

The kth ancestor of a tree node is the kth node in the path from that node to the root node.

Implement the TreeAncestor class:

TreeAncestor(int n, int[] parent) Initializes the object with the number of nodes in the tree and the parent array.
int getKthAncestor(int node, int k) return the kth ancestor of the given node node. If there is no such ancestor, return -1.
*/
#include <bits/stdc++.h>
using namespace std;
class TreeAncestor
{
public:
    vector<int> anc[16];
    TreeAncestor(int n, vector<int> &parent)
    {
        anc[0] = parent;
        for (int i = 1; i < 16; i++)
        {
            anc[i].resize(n);
            for (int v = 0; v < n; v++)
            {
                if (anc[i - 1][v] == -1)
                {
                    anc[i][v] = -1;
                }
                else
                {
                    anc[i][v] = anc[i - 1][anc[i - 1][v]];
                }
            }
        }
    }

    int getKthAncestor(int node, int k)
    {
        for (int i = 0; i < 16; i++)
        {
            if (node == -1)
            {
                return -1;
            }
            if ((1 << i) & k)
            {
                node = anc[i][node];
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */

 int main(){
        int n = 7;
        vector<int> parent = {-1,0,0,1,1,2,2};
        TreeAncestor* obj = new TreeAncestor(n, parent);    //TC;O(nlogn) SC:O(nlogn)
        cout<<obj->getKthAncestor(3,1)<<endl; // Output: 1
        cout<<obj->getKthAncestor(5,2)<<endl; // Output: 0
        cout<<obj->getKthAncestor(6,3)<<endl; // Output: -1
        return 0;
 }
/*
Solution Approach: Binary Lifting
1. We will create a 2D vector anc where anc[i][v] will store the 2^i-th ancestor of node v.
2. We will fill this vector using dynamic programming. For i = 0, anc[0][v] will be the parent of v. For i > 0, anc[i][v] will be the ancestor of anc[i-1][v] at distance 2^(i-1).
3. To find the kth ancestor of a node, we will check each bit of k. If the j-th bit of k is set, we will move to the ancestor stored in anc[j][node]. We will repeat this process until we have processed all bits of k or we reach -1 (which means there is no ancestor).
*/
 /*
 PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 111__17-05-2026_Kth_Ancestor.cpp -o 111__17-05-2026_Kth_Ancestor } ; if ($?) { .\111__17-05-2026_Kth_Ancestor }
1
0
-1
 */

 