/*
Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.
*/
#include <bits/stdc++.h>
using namespace std;

//  * Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
    int res = 0;

public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        solve(root);
        return res;
    }
    int solve(TreeNode *root)
    {
        if (!root)
            return 0;
        int l = solve(root->left);
        int r = solve(root->right);

        res = max(res, l + r);
        return 1 + max(l, r);
    }
};

int main(){
    Solution s;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    int result = s.diameterOfBinaryTree(root); //TC:O(n)  SC:O(n)

    // Print the result
    cout << result << endl;
}

/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 64__13-03-2026_Diameter_BinaryTree.cpp -o 64__13-03-2026_Diameter_BinaryTree } ; if ($?) { .\64__13-03-2026_Diameter_BinaryTree }
3
*/
