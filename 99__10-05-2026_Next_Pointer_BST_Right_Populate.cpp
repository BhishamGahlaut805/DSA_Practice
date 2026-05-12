/*
You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.
*/

// Definition for a Node.

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
    Node *connect(Node *root)
    {
        if (root == NULL)
            return NULL;
        // Process as done in Level order traversal

        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();

            Node *right = NULL;

            for (int i = size; i > 0; i--)
            {
                Node *curr = q.front();
                q.pop();
                curr->next = right;
                right = curr;
                // insert right node first to get right to left BFS
                if (curr->right)
                {
                    q.push(curr->right);
                }
                if (curr->left)
                {
                    q.push(curr->left);
                }
            }
        }
        return root;
    }
};

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution s;
    s.connect(root);

    // Print the next pointers for each level
    cout << "Next pointers for each level:" << endl;
    cout << "Level 1: " << (root->next ? to_string(root->next->val) : "NULL") << endl;
    cout << "Level 2: " << (root->left->next ? to_string(root->left->next->val) : "NULL") << ", "
         << (root->right->next ? to_string(root->right->next->val) : "NULL") << endl;
    cout << "Level 3: " << (root->left->left->next ? to_string(root->left->left->next->val) : "NULL") << ", "
         << (root->left->right->next ? to_string(root->left->right->next->val) : "NULL") << ", "
         << (root->right->left->next ? to_string(root->right->left->next->val) : "NULL") << ", "
         << (root->right->right->next ? to_string(root->right->right->next->val) : "NULL") << endl;

    return 0;
}

/*
TC: O(N) where N is the number of nodes in the tree, as we need to visit each node once.
SC: O(N) in the worst case (when the tree is completely unbalanced), and
O(1) in the best case (when the tree is perfectly balanced).
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 99__10-05-2026_Next_Pointer_BST_Right_Populate.cpp -o 99__10-05-2026_Next_Pointer_BST_Right_Populate } ; if ($?) { .\99__10-05-2026_Next_Pointer_BST_Right_Populate }
Next pointers for each level:
Level 1: NULL
Level 2: 3, NULL
Level 3: 5, 6, 7, NULL
*/
