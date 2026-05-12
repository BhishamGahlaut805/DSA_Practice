#include <bits/stdc++.h>
using namespace std;
/*
Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.
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

class Solution
{
public:
    TreeNode *findMin(TreeNode *root)
    {
        while (root->left != NULL)
            root = root->left;

        return root;
    }

    TreeNode *deleteNode(TreeNode *root, int key)
    {

        if (root == NULL)
            return NULL;

        // Search
        if (key < root->val)
        {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->val)
        {
            root->right = deleteNode(root->right, key);
        }

        // Found node
        else
        {

            // Case 1: No child
            if (root->left == NULL && root->right == NULL)
            {
                delete root;
                return NULL;
            }

            // Case 2: One child
            else if (root->left == NULL)
            {
                TreeNode *temp = root->right;
                delete root;
                return temp;
            }

            else if (root->right == NULL)
            {
                TreeNode *temp = root->left;
                delete root;
                return temp;
            }

            // Case 3: Two children
            else
            {
                TreeNode *succ = findMin(root->right);

                // Copy successor value
                root->val = succ->val;

                // Delete successor
                root->right = deleteNode(root->right, succ->val);
            }
        }

        return root;
    }
};

int main(){

    TreeNode *root = new TreeNode(7);
    root->left = new TreeNode(3);
    TreeNode *node = new TreeNode(15);
    root->right = node;
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);
    Solution sol;
    TreeNode*ans=sol.deleteNode(root,9);    //TC:O(N), SC:O(1)
    while(ans->left!=NULL){
        cout<<ans->val<<" ";
        ans=ans->left;
    }

}
/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 106__12-05-2026__BST_Deletion.cpp -o 106__12-05-2026__BST_Deletion } ; if ($?) { .\106__12-05-2026__BST_Deletion }
7
*/

