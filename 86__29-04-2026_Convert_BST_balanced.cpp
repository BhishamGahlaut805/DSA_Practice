// Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.
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
private:
    TreeNode *helper(vector<int> &nums, int left, int right)
    {
        if (left > right)
        {
            return nullptr;
        }
        int mid = left + (right - left) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = helper(nums, left, mid - 1);
        root->right = helper(nums, mid + 1, right);
        return root;
    }

public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return helper(nums, 0, nums.size() - 1);
    }
};

int main()
{
    vector<int> nums = {-10, -3, 0, 5, 9};
    Solution sol;
    TreeNode *root = sol.sortedArrayToBST(nums); // TC: O(n), SC: O(n)

    for (int i = 0; i < nums.size(); i++)
    {
        cout << root->val << " ";
        root = root->right;
    }
    return 0;
}
/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 86__29-04-2026_Convert_BST_balanced.cpp -o 86__29-04-2026_Convert_BST_balanced } ; if ($?) { .\86__29-04-2026_Convert_BST_balanced }
0 5 9
*/
