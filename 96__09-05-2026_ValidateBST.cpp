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
    bool solve(TreeNode *root, long long low, long long high)
    {
        if (!root)
            return true;

        if (root->val <= low || root->val >= high)
            return false;
        return solve(root->left, low, root->val) && solve(root->right, root->val, high);
    }
    bool isValidBST(TreeNode *root)
    {
        return solve(root, LLONG_MIN, LLONG_MAX);
    }
};
int main()
{
    Solution sol;
    TreeNode *root = new TreeNode(2);

    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    cout << sol.isValidBST(root); //TC:O(N) SC:O(H)

}
/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 96__09-05-2026_ValidateBST.cpp -o 96__09-05-2026_ValidateBST } ; if ($?) { .\96__09-05-2026_ValidateBST }
1
*/
