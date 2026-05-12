// Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.
//Definition for a binary tree node.
#include <bits/stdc++.h>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    void inorder(TreeNode*root, int&ans,int&k){
        if(!root){
            return;
        }
            inorder(root->left,ans,k);
            k--;
            if(k==0){
                ans=root->val;
            }
            if(k<=0) return;
            inorder(root->right,ans,k);

    }
    int kthSmallest(TreeNode* root, int k) {
        int ans;
        inorder(root,ans,k);
        return ans;
    }
};

int main(){
    TreeNode*root=new TreeNode(3);
    root->left=new TreeNode(1);
    root->right=new TreeNode(4);
    root->left->right=new TreeNode(2);
    int k=1;
    Solution s;
    cout<<s.kthSmallest(root,k)<<endl;  //TC:O(N) SC:O(H)
}
/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 97__10-05-2026_KthSmallest_BST.cpp -o 97__10-05-2026_KthSmallest_BST } ; if ($?) { .\97__10-05-2026_KthSmallest_BST }
1
*/
