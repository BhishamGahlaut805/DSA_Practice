/*
Given an array of integers preorder, which represents the preorder traversal of a BST (i.e., binary search tree), construct the tree and return its root.

It is guaranteed that there is always possible to find a binary search tree with the given requirements for the given test cases.

A binary search tree is a binary tree where for every node, any descendant of Node.left has a value strictly less than Node.val, and any descendant of Node.right has a value strictly greater than Node.val.

A preorder traversal of a binary tree displays the value of the node first, then traverses Node.left, then traverses Node.right.
*/

#include <bits/stdc++.h>
using namespace std;

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
public:
    int i = 0;
    TreeNode *solve(vector<int> &preorder, int maxVal)
    {
        if (i == preorder.size() || preorder[i] > maxVal)
            return NULL;

        TreeNode *root = new TreeNode(preorder[i++]);
        root->left = solve(preorder, root->val);
        root->right = solve(preorder, maxVal);
        return root;
    }
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        return solve(preorder, INT_MAX);
    }
};
int main()
{
    vector<int> preorder = {8, 5, 1, 7, 10, 12};
    Solution s;
    TreeNode *root = s.bstFromPreorder(preorder);
    cout << root->val << " " << root->left->val << " " << root->left->left->val << " " << root->left->right->val << " " << root->right->val << " " << root->right->right->val << endl; //TC:O(N) SC:O(H)
}
/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 101__10-05-2026_Construct_BST_Preorder.cpp -o 101__10-05-2026_Construct_BST_Preorder } ; if ($?) { .\101__10-05-2026_Construct_BST_Preorder }
8 5 1 7 10 12
*/
