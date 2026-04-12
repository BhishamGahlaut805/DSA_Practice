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
public:
    void solve(TreeNode *root, vector<int> &ans)
    {
        if (root != NULL)
        {
            solve(root->left, ans);
            ans.push_back(root->val);
            solve(root->right, ans);
        }
    }
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        solve(root, ans);
        return ans;
    }
};

int main(){
    Solution s;
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    vector<int> result = s.inorderTraversal(root); //TC:O(n)  SC:O(n)

    // Print the result
    for (int val : result)
    {
        cout << val << " ";
    }
}
/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 60__12-04-2026_BST_Traversals.cpp -o 60__12-04-2026_BST_Traversals } ; if ($?) { .\60__12-04-2026_BST_Traversals }
1 3 2
*/
