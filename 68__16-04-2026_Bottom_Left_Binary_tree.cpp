// Given the root of a binary tree, return the leftmost value in the last row of the tree.
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
    int findBottomLeftValue(TreeNode *root)
    {
        int ans = 0;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int count = q.size();
            for (int i = 0; i < count; i++)
            {
                TreeNode *curr = q.front();
                q.pop();
                if (i == 0)
                {
                    ans = curr->val;
                }
                if (curr->left != NULL)
                {
                    q.push(curr->left);
                }
                if (curr->right != NULL)
                {
                    q.push(curr->right);
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->left->right->left = new TreeNode(7);

    int result = s.findBottomLeftValue(root); //TC:O(n)  SC:O(n)

    // Print the result
    cout << "Bottom Left Value: " << result << endl;

    return 0;
}

/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 68__16-04-2026_Bottom_Left_Binary_tree.cpp -o 68__16-04-2026_Bottom_Left_Binary_tree } ; if ($?) { .\68__16-04-2026_Bottom_Left_Binary_tree }
Bottom Left Value: 7
*/

