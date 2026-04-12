// Given the root of a Binary Search Tree (BST), return the minimum difference between the values of any two different nodes in the tree.

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
public:
    int res = INT_MAX, pre = -1;
    int minDiffInBST(TreeNode *root)
    {
        if (root->left != NULL)
            minDiffInBST(root->left);
        if (pre >= 0)
            res = min(res, root->val - pre);
        pre = root->val;
        if (root->right != NULL)
            minDiffInBST(root->right);
        return res;
    }
};

int main()
{
    Solution s;
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    int result = s.minDiffInBST(root); //TC:O(n)  SC:O(n)

    // Print the result
    cout << result << endl;
}
/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 62__12-04-2026_Min_Difference_BST.cpp -o 62__12-04-2026_Min_Difference_BST } ; if ($?) { .\62__12-04-2026_Min_Difference_BST }
1
*/
