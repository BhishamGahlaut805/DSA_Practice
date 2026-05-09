//binary tree zig zag level order traversal
#include <bits/stdc++.h>
using namespace std;

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
    void levelorder(TreeNode *root, vector<vector<int>> &ans)
    {
        if (!root)
            return;
        queue<TreeNode *> q;

        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            vector<int> temp;
            for (int i = 0; i < size; i++)
            {
                auto top = q.front();
                q.pop();
                temp.push_back(top->val);
                if (top->left)
                    q.push(top->left);
                if (top->right)
                    q.push(top->right);
            }
            ans.push_back(temp);
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        levelorder(root, ans);
        int i = 0;
        for (auto &row : ans)
        {
            if (i % 2 != 0)
                reverse(row.begin(), row.end());
            i++;
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    vector<vector<int>> ans = sol.zigzagLevelOrder(root);   //TC:O(N) SC:O(N)
    for (auto &row : ans)
    {
        for (auto &col : row)
            cout << col << " ";
        cout << endl;
    }
    return 0;
}
/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 93__06-05-2026_Zig_Zag_BT.cpp -o 93__06-05-2026_Zig_Zag_BT } ; if ($?) { .\93__06-05-2026_Zig_Zag_BT }
1
3 2
4 5 6 7
*/

