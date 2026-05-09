/*
A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any non-empty path.
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
    int dfs(TreeNode *root, int &maximum)
    {

        if (!root)
            return 0;
        int leftsum = max(0, dfs(root->left, maximum));
        int rightsum = max(0, dfs(root->right, maximum));
        maximum = max(maximum, leftsum + rightsum + root->val);
        return root->val + max(leftsum, rightsum);
    }
    int maxPathSum(TreeNode *root)
    {
        int maximum = INT_MIN;
        dfs(root, maximum);
        return maximum;
    }
};

int main()
{
    Solution sol;
    TreeNode *root = new TreeNode(-10);

    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    cout << sol.maxPathSum(root); //TC:O(N) SC:O(H)
    return 0;
}
/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 94_07-05-2026_Maximum_Path_Sum.cpp -o 94_07-05-2026_Maximum_Path_Sum } ; if ($?) { .\94_07-05-2026_Maximum_Path_Sum }
42
*/

