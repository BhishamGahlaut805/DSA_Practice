/*
Given the root of a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus the sum of all keys greater than the original key in BST.

As a reminder, a binary search tree is a tree that satisfies these constraints:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
*/
#include <bits/stdc++.h>
using namespace std;

//  * Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution
{
    int sum = 0;

public:
    TreeNode *bstToGst(TreeNode *root)
    {
        traverse(root);
        return root;
    }
    void traverse(TreeNode *root)
    {
        if (root)
        {
            traverse(root->right);
            sum += root->val;
            root->val = sum;
            traverse(root->left);
        }
    }
};

int main()
{
    Solution sol;
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(1);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);

    TreeNode *ans = sol.bstToGst(root); // TC:O(N) SC:O(H)
    cout << "Greater Tree Root Value: " << ans->val << endl; // Output the value of the new root node

    return 0;
}
/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 74__20-04-2026_BST_to_GST.cpp -o 74__20-04-2026_BST_to_GST } ; if ($?) { .\74__20-04-2026_BST_to_GST }
Greater Tree Root Value: 22
*/

