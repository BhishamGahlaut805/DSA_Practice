/*
Implement the BSTIterator class that represents an iterator over the in-order traversal of a binary search tree (BST):

BSTIterator(TreeNode root) Initializes an object of the BSTIterator class. The root of the BST is given as part of the constructor. The pointer should be initialized to a non-existent number smaller than any element in the BST.
boolean hasNext() Returns true if there exists a number in the traversal to the right of the pointer, otherwise returns false.
int next() Moves the pointer to the right, then returns the number at the pointer.
Notice that by initializing the pointer to a non-existent smallest number, the first call to next() will return the smallest element in the BST.

You may assume that next() calls will always be valid. That is, there will be at least a next number in the in-order traversal when next() is called.
*/
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
class BSTIterator {
public:
    stack<TreeNode*>s;

    BSTIterator(TreeNode* root) {
        partialInorder(root);
    }
    void partialInorder(TreeNode*root){
        while(root){
            s.push(root);
            root=root->left;
        }
    }
    int next() {
        TreeNode*top=s.top();
        s.pop();
        partialInorder(top->right);
        return top->val;
    }

    bool hasNext() {
        return !s.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
int main(){
    TreeNode*root=new TreeNode(7);
    root->left=new TreeNode(3);
    root->right=new TreeNode(15);
    root->right->left=new TreeNode(9);
    root->right->right=new TreeNode(20);
    BSTIterator* obj = new BSTIterator(root);
    cout<<obj->next()<<endl;  //TC:O(1) SC:O(H)
    cout<<obj->next()<<endl;  //TC:O(1) SC:O(H)
    cout<<obj->hasNext()<<endl;  //TC:O(1) SC:O(H)
    cout<<obj->next()<<endl;  //TC:O(1) SC:O(H)
    cout<<obj->hasNext()<<endl;  //TC:O(1) SC:O(H)
    cout<<obj->next()<<endl;  //TC:O(1) SC:O(H)
    cout<<obj->hasNext()<<endl;  //TC:O(1) SC:O(H)

}
/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 102__11-05-2026_BST_Iterator.cpp -o 102__11-05-2026_BST_Iterator } ; if ($?) { .\102__11-05-2026_BST_Iterator }
3
7
1
9
1
15
1

*/

