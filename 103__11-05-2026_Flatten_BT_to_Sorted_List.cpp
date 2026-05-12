//Convert an BST into Sorted linked list

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
struct ListNode
{
    int val;
    ListNode*next;
    ListNode():val(0),next(nullptr) {}
    ListNode(int x):val(x),next(nullptr) {}
};

class Solution
{
public:
    ListNode *head = nullptr;
    ListNode *tail = nullptr;

    void inorder(TreeNode *root)
    {
        if (!root)
            return;

        inorder(root->left);

        ListNode *node = new ListNode(root->val);

        if (!head)
        {
            head = tail = node;
        }
        else
        {
            tail->next = node;
            tail = node;
        }

        inorder(root->right);
    }

    ListNode *flatten(TreeNode *root)
    {
        head = tail = nullptr;
        inorder(root);
        return head;
    }
};

int main(){
    TreeNode*root=new TreeNode(5);
    root->left=new TreeNode(3);
    root->right=new TreeNode(6);
    root->left->left=new TreeNode(2);
    root->left->right=new TreeNode(4);
    Solution s;
    ListNode*head=s.flatten(root);  //TC:O(N) SC:O(N)
    while(head){
        cout<<head->val<<" ";
        head=head->next;
    }
}
/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 103__11-05-2026_Flatten_BT_to_Sorted_List.cpp -o 103__11-05-2026_Flatten_BT_to_Sorted_List } ; if ($?) { .\103__11-05-2026_Flatten_BT_to_Sorted_List }
2 3 4 5 6
*/
