#include <bits/stdc++.h>
using namespace std;

//  * Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution
{
    void preorder(TreeNode *node, vector<TreeNode *> &nodes)
    {
        if (!node)
            return;
        nodes.push_back(node);
        preorder(node->left, nodes);
        preorder(node->right, nodes);
    }

public:
    void flatten(TreeNode *root)
    {
        if (!root)
            return;
        vector<TreeNode *> nodes;
        preorder(root, nodes);
        for (int i = 0; i < nodes.size() - 1; i++)
        {
            nodes[i]->left = nullptr;
            nodes[i]->right = nodes[i + 1];
        }
    }
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution_optimized
{
public:
    void flatten(TreeNode *root)
    {
        // in-place optimized approach for O(1) Space and O(N) time complexity
        TreeNode *current = root;
        while (current)
        {
            if (current->left)
            {
                TreeNode *temp = current->left;
                while (temp->right != NULL)
                {
                    temp = temp->right;
                }
                temp->right = current->right;
                current->right = current->left;
                current->left = NULL;
            }
            current = current->right;
        }
    }
};

int main()
{
    Solution sol;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);

    sol.flatten(root); // TC:O(N) SC:O(N)

    // Print the flattened tree
    TreeNode *current = root;
    while (current)
    {
        cout << current->val << " ";
        current = current->right;
    }
    cout << endl;

    return 0;
}
/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 91__04-05-2026_Flatten_BT.cpp -o 91__04-05-2026_Flatten_BT } ; if ($?) { .\91__04-05-2026_Flatten_BT }
1 2 3 4 5 6
*/
