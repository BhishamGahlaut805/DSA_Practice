// Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.
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
    unordered_map<int, int> inorderIndex;

public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        for (int i = 0; i < inorder.size(); i++)
        {
            inorderIndex[inorder[i]] = i;
        }
        int n = postorder.size();
        int postindex = n - 1;
        return solve(inorder, postorder, 0, n - 1, postindex);
    }

    TreeNode *solve(vector<int> &inorder, vector<int> &postorder, int instart, int inend, int &postindex)
    {
        if (instart > inend)
        {
            return NULL;
        }
        int rootval = postorder[postindex--];
        TreeNode *root = new TreeNode(rootval);

        int idx = inorderIndex[rootval];

        // creating the right branch first as we have to traverse backward in case of postOrder
        root->right = solve(inorder, postorder, idx + 1, inend, postindex);
        root->left = solve(inorder, postorder, instart, idx - 1, postindex);

        return root;
    }
};
int main()
{
    Solution sol;
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};

    TreeNode *root = sol.buildTree(inorder, postorder); // TC:O(N) SC:O(N)
    cout << "Root Value: " << root->val << endl; // Output the value of the root node

    return 0;
}
/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 76__20-04-2026_Construct_BST2.cpp -o 76__20-04-2026_Construct_BST2 } ; if ($?) { .\76__20-04-2026_Construct_BST2 }
Root Value: 3
*/

