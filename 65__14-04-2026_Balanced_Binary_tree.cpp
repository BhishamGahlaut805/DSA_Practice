// Given a binary tree, determine if it is height-balanced.

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
    int height(TreeNode *root)
    {
        if (!root)
            return 0;
        return 1 + max(height(root->left), height(root->right));
    }
    bool isBalanced(TreeNode *root)
    {
        if (!root)
            return true;
        if (abs(height(root->left) - height(root->right)) > 1)
        {
            return false;
        }
        return isBalanced(root->left) and isBalanced(root->right);
    }
};

int main()  {
    Solution s;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    bool result = s.isBalanced(root); //TC:O(n^2)  SC:O(n)

    // Print the result
    cout << (result ? "true" : "false") << endl;
}
/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 65__14-04-2026_Balanced_Binary_tree.cpp -o 65__14-04-2026_Balanced_Binary_tree } ; if ($?) { .\65__14-04-2026_Balanced_Binary_tree }
true
*/
