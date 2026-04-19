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
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>>res;
        if(!root) return res;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();

            vector<int>temp;
            for(int i=0;i<size;i++){
                TreeNode*n=q.front();
                q.pop();
                temp.push_back(n->val);

                if(n->left) q.push(n->left);
                if(n->right) q.push(n->right);
            }
            res.push_back(temp);
        }
        return res;
    }
};

int main()
{
    Solution s;
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<vector<int>> result = s.levelOrder(root); //TC:O(n)  SC:O(n)

    // Print the result
    for (const auto &level : result)
    {
        for (int val : level)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 69__17-04-2026_Level_Order_Binary_tree.cpp -o 69__17-04-2026_Level_Order_Binary_tree } ; if ($?) { .\69__17-04-2026_Level_Order_Binary_tree }
3
9 20
15 7
*/
