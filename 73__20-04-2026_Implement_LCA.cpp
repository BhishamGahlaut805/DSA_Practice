/*
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”
*/
#include <bits/stdc++.h>
using namespace std;

//  * Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL || root==p || root==q) return root;

        TreeNode*left=lowestCommonAncestor(root->left,p,q);
        TreeNode*right=lowestCommonAncestor(root->right,p,q);

        if(left!=NULL && right!=NULL) return root;
         return left==NULL?right:left;
    }
};

int main(){

    Solution sol;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    TreeNode* p = root->left; // Node with value 2
    TreeNode* q = root->right; // Node with value 3

   TreeNode*ans= sol.lowestCommonAncestor(root,p,q);    //TC:O(N) SC:O(N)
   cout<<"LCA of "<<p->val<<" and "<<q->val<<" is: "<<ans->val<<endl;

    return 0;
}

/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 73__20-04-2026_Implement_LCA.cpp -o 73__20-04-2026_Implement_LCA } ; if ($?) { .\73__20-04-2026_Implement_LCA }
LCA of 2 and 3 is: 1
*/


