#include<bits/stdc++.h>
using namespace std;
//Finding the inorder sucessor of a given node
//Case1: The Node has a right subtree-> return the leftmost node of right subtree
/*Case 2: if no right subtree : The successor is one of its ancestors
Start from the root of the tree, if the value of the current node is greater than target value : current node can be successor and move left ; otherwise move to the right

*/
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
    TreeNode* inorderSuccessor(TreeNode*root,TreeNode*target){
        TreeNode*ans=NULL;
        //Case 1 right subtree Exists
        if(target->right!=NULL){
            //return leftmost node of right subtree
            TreeNode*curr=target;
            while(curr->left!=NULL){
                curr=curr->left;
            }
            return curr;
        }
        //Case2 : NO right Subtree exists
        else{

            TreeNode*curr=root;
            while(curr!=NULL){
                if(curr->val > target->val){
                    //this can be inorder successor
                    ans=curr;
                    curr=curr->left;
                }
                else if(curr->val < target->val){
                    curr=curr->right;
                }
                else {
                    break;
                }
            }
        }
        return ans;
    }
};
/*
Time Complexity : O(h)= For a balanced BST
O(N)= for skewed BST
*/
int main(){
    TreeNode *root = new TreeNode(7);
    root->left = new TreeNode(3);
    TreeNode *node = new TreeNode(15);
    root->right = node;
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);
    Solution sol;
    TreeNode*ans=sol.inorderSuccessor(root,node);
    cout<<ans->val<<endl;

}
/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 104__12-05-2026_Inorder_Successor_BST.cpp -o 104__12-05-2026_Inorder_Successor_BST } ; if ($?) { .\104__12-05-2026_Inorder_Successor_BST }
9
*/
