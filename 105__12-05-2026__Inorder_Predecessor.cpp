#include <bits/stdc++.h>
using namespace std;
// Finding the inorder predecessor of a given node
// Case1: The Node has a left subtree-> return the rightmost node of right subtree
/*Case 2: if no left subtree : The predecessor is one of its ancestors
Start from the root of the tree, if the value of the current node is smaller than target value : current node can be predecessor and move right ; otherwise move to the left

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
    TreeNode *inorderPred(TreeNode *root, TreeNode *target)
    {
        TreeNode *ans = NULL;
        // Case 1 left subtree Exists
        if (target->left != NULL)
        {
            // return rightmost node of right subtree
            TreeNode *curr = target;
            while (curr->right != NULL)
            {
                curr = curr->right;
            }
            return curr;
        }
        // Case2 : NO left Subtree exists
        else
        {

            TreeNode *curr = root;
            while (curr != NULL)
            {
                if (curr->val < target->val)
                {
                    // this can be inorder successor
                    ans = curr;
                    curr = curr->right;
                }
                else if (curr->val < target->val)
                {
                    curr = curr->left;
                }
                else
                {
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
int main()
{
    TreeNode *root = new TreeNode(7);
    root->left = new TreeNode(3);
    TreeNode *node = new TreeNode(15);
    root->right = node;
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);
    Solution sol;
    TreeNode *ans = sol.inorderPred(root, node);
    cout << ans->val << endl;
}
/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 105__12-05-2026__Inorder_Predecessor.cpp -o 105__12-05-2026__Inorder_Predecessor } ; if ($?) { .\105__12-05-2026__Inorder_Predecessor }
20
*/
