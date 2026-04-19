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
    int maxLevelSum(TreeNode *root)
    {
        int level = 1, sum = INT_MIN, ans = 0;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            int temp = 0;
            for (int i = 0; i < size; i++)
            {
                TreeNode *n = q.front();
                q.pop();
                temp += n->val;
                if (n->left)
                    q.push(n->left);
                if (n->right)
                    q.push(n->right);
            }

            if (temp > sum)
            {
                ans = level;
                sum = temp;
            }
            level++;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(7);
    root->right = new TreeNode(0);

    int result = s.maxLevelSum(root); //TC:O(n)  SC:O(n)

    cout << "The level with the maximum sum is: " << result << endl;

    return 0;
}

/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 70__17-04-2026__Max_Level_Sum.cpp -o 70__17-04-2026__Max_Level_Sum } ; if ($?) { .\70__17-04-2026__Max_Level_Sum }
The level with the maximum sum is: 2
*/


