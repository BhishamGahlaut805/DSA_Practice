/*
Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”


*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        while (root != NULL)
        {
            if (min(p->val, q->val) > root->val)
            {
                // move to the right
                root = root->right;
            }
            else if (max(p->val, q->val) < root->val)
            {
                // move towards left
                root = root->left;
            }
            else
            {
                return root;
            }
        }
        return NULL;
    }
};

int main()
{
    TreeNode *root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);
    TreeNode *p = root->left;  // Node with value 2
    TreeNode *q = root->right; // Node with value 8
    Solution s;
    TreeNode *lca = s.lowestCommonAncestor(root, p, q);//TC:O(H) SC:O(1)
    if (lca != NULL)
        cout << "LCA of " << p->val << " and " << q->val << " is: " << lca->val << endl;
    else
        cout << "LCA does not exist." << endl;
}

/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 98__10-05-2026_Lowest_Common_Ancestor_BST.cpp -o 98__10-05-2026_Lowest_Common_Ancestor_BST } ; if ($?) { .\98__10-05-2026_Lowest_Common_Ancestor_BST }
LCA of 2 and 8 is: 6
*/
