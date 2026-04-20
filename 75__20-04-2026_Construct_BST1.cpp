// Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.
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

private:
    int preorderIndex = 0;
    unordered_map<int, int> inorderIndexMap;

    TreeNode *constructTree(vector<int> &preOrder, int left, int right)
    {
        if (left > right)
        {
            return nullptr;
        }
        int rootValue = preOrder[preorderIndex++];
        TreeNode *root = new TreeNode(rootValue);
        int rootIndex = inorderIndexMap[rootValue];

        root->left = constructTree(preOrder, left, rootIndex - 1);
        root->right = constructTree(preOrder, rootIndex + 1, right);
        return root;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        for (int i = 0; i < inorder.size(); i++)
        {
            inorderIndexMap[inorder[i]] = i;
        }
        return constructTree(preorder, 0, inorder.size() - 1);
    }
};

int main()
{
    Solution sol;
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    TreeNode *root = sol.buildTree(preorder, inorder); // TC:O(N) SC:O(N)
    cout << "Root Value: " << root->val << endl; // Output the value of the root node

    return 0;
}
/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 75__20-04-2026_Construct_BST1.cpp -o 75__20-04-2026_Construct_BST1 } ; if ($?) { .\75__20-04-2026_Construct_BST1 }
Root Value: 3
*/

