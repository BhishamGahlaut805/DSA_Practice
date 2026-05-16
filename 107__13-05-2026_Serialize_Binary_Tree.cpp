#include<bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<string>S;
        string ans;
        if(!root) return "";
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
            TreeNode* top=q.front();
            q.pop();

            if(!top){
                S.push_back("#");
                continue;
            }
            else{
                S.push_back(to_string(top->val));
            }
            q.push(top->left);
             q.push(top->right);
        }
        }
        //Converting to plane string separated by comma
        for(int i=0;i<S.size();i++){
            ans+=S[i];
            if(i<S.size()-1) ans+=',';
        }
        return ans;
    }

    vector<string>split(string str){

        vector<string>ans;
        string s="";
        for(int i=0;i<str.size();i++){
            if(str[i]==','){
                ans.push_back(s);
                s="";
            }
            else{
                s+=str[i];
            }
        }
        ans.push_back(s);
        return ans;
    }
    // Decodes your encoded data to tree.
    //Performing Reverse of BFS for this
    TreeNode* deserialize(string data) {
        if(data.empty()) {
            return NULL;
        }

        vector<string>newData=split(data);  //Remove commas
        TreeNode*root=new TreeNode(stoi(newData[0]));

        queue<TreeNode*>q;
        q.push(root);

        int i=1;
        while(!q.empty() && i<newData.size()){
            TreeNode*parent=q.front();
            q.pop();

            if(i<newData.size() && newData[i]!="#")
            {
                parent->left=new TreeNode(stoi(newData[i]));
            }
            i++;
             if(i<newData.size() && newData[i]!="#")
            {
                parent->right=new TreeNode(stoi(newData[i]));
            }
            i++;

            if(parent->left) q.push(parent->left);
            if(parent->right) q.push(parent->right);
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

int main(){
    Codec ser, deser;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    string serializedData = ser.serialize(root);
    cout << "Serialized Data: " << serializedData << endl;

    TreeNode* deserializedRoot = deser.deserialize(serializedData);
    cout << "Deserialized Root Value: " << deserializedRoot->val << endl;

    return 0;
}
/*
Time complexity: O(n) where n is the number of nodes in the tree. We visit each node once during serialization and deserialization.
Space complexity: O(n) for both serialization and deserialization. In the worst case, the serialized string can be of size O(n) and the queue used during deserialization can also hold O(n) nodes in the worst case (when the tree is skewed).
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 107__13-05-2026_Serialize_Binary_Tree.cpp -o 107__13-05-2026_Serialize_Binary_Tree } ; if ($?) { .\107__13-05-2026_Serialize_Binary_Tree }
Serialized Data: 1,2,3,#,#,4,5,#,#,#,#
Deserialized Root Value: 1
*/

