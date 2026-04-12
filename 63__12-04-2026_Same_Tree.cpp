// Given the roots of two binary trees, write a function to check if they are the same or not.

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
    bool solve(TreeNode *p, TreeNode *q)
    {
        if (p == NULL && q == NULL)
        {
            return true;
        }
        if (p == NULL || q == NULL)
        {
            return false;
        }
        return p->val == q->val && solve(p->left, q->left) && solve(p->right, q->right);
    }
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        return solve(p, q);
    }
};

int main()
{
    Solution s;
    TreeNode *p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);

    TreeNode *q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);

    bool result = s.isSameTree(p, q); //TC:O(n)  SC:O(n)

    // Print the result
    cout << (result ? "true" : "false") << endl;
}
/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 63__12-04-2026_Same_Tree.cpp -o 63__12-04-2026_Same_Tree } ; if ($?) { .\63__12-04-2026_Same_Tree }
true
*/
