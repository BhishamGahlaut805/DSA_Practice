// You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.

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
    TreeNode *first = NULL;
    TreeNode *second = NULL;
    TreeNode *prev = NULL;

    void recoverTree(TreeNode *root)
    {
        solve(root);

        swap(first->val, second->val);
    }
    void solve(TreeNode *node)
    {
        if (!node)
            return;
        // Solve by intuition of inorder traversal
        solve(node->left);
        if (prev && prev->val > node->val)
        { // voilating inorder condition of BST
            if (first == NULL)
                first = prev;
            second = node;
        }
        prev = node;
        solve(node->right);
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    Solution s;
    s.recoverTree(root);
    cout << root->val << " " << root->left->val << " " << root->left->right->val << endl; //TC:O(N) SC:O(H)
}
/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 100__10-05-2026_Recover_BST.cpp -o 100__10-05-2026_Recover_BST } ; if ($?) { .\100__10-05-2026_Recover_BST }
3 1 2
*/

