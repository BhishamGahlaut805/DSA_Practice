/*
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
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
public:
    bool solve(TreeNode *n1, TreeNode *n2)
    {
        if (n1 == NULL && n2 == NULL)
        {
            return true;
        }
        if (n1 == NULL || n2 == NULL)
        {
            return false;
        }
        return n1->val == n2->val && solve(n1->left, n2->right) && solve(n1->right, n2->left);
    }
    bool isSymmetric(TreeNode *root)
    {
        return solve(root->left, root->right);
    }
};
int main()
{
    Solution s;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    bool result = s.isSymmetric(root); //TC:O(n)  SC:O(n)

    // Print the result
    cout << (result ? "true" : "false") << endl;
}
/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 61__12-04-2026_Symmetric_tree.cpp -o 61__12-04-2026_Symmetric_tree } ; if ($?) { .\61__12-04-2026_Symmetric_tree }
true
*/
