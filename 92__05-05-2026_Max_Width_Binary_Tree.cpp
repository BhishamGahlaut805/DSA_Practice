/*
Given the root of a binary tree, return the maximum width of the given tree.

The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.

It is guaranteed that the answer will in the range of a 32-bit signed integer.*/
//  * Definition for a binary tree node.

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
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,unsigned long long>>q;
        q.push({root,0});

        unsigned long long ans=0;
        while(!q.empty()){
            int size=q.size();
            unsigned long long st=q.front().second;
            unsigned long long en=q.back().second;
            ans=max(ans,en-st+1);


            for(int i=0;i<size;i++){
                auto currNode=q.front();
                q.pop();
                if(currNode.first->left) q.push({currNode.first->left,2*currNode.second+1});
                if(currNode.first->right) q.push({currNode.first->right,2*currNode.second+2});
            }
        }
        return (int)ans;
    }
};

int main(){
    Solution sol;
    TreeNode* root=new TreeNode(1);

    root->left=new TreeNode(3);
    root->right=new TreeNode(2);
    cout<<sol.widthOfBinaryTree(root);  //TC:O(N) SC:O(N)
    return 0;
}
/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 92__05-05-2026_Max_Width_Binary_Tree.cpp -o 92__05-05-2026_Max_Width_Binary_Tree } ; if ($?) { .\92__05-05-2026_Max_Width_Binary_Tree }
2
*/

