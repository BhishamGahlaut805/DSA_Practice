/*
Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.

A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be considered as a subtree of itself.
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

class Solution {
public:
    bool isIdentical(TreeNode*root,TreeNode*subRoot){
        if(root==NULL && subRoot==NULL){
            return true;
        }
        if(root==NULL || subRoot==NULL){
            return false;
        }
         return root->val==subRoot->val && isIdentical(root->left,subRoot->left) && isIdentical(root->right,subRoot->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL || subRoot==NULL){
            return false;
        }
        if(root->val==subRoot->val && isIdentical(root,subRoot)){
            return true;
        }
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
};

int main()  {
    Solution s;
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);

    TreeNode *subRoot = new TreeNode(4);
    subRoot->left = new TreeNode(1);
    subRoot->right = new TreeNode(2);

    bool result = s.isSubtree(root, subRoot); //TC:O(m*n)  SC:O(n)

    // Print the result
    cout << (result ? "true" : "false") << endl;
}
/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 66__15-04-2026__SubTree_Of_AnotherTree.cpp -o 66__15-04-2026__SubTree_Of_AnotherTree } ; if ($?) { .\66__15-04-2026__SubTree_Of_AnotherTree }
true
*/
