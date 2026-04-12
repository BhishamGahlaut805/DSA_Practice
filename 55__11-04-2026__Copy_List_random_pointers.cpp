/*
A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

Return the head of the copied linked list.

The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
Your code will only be given the head of the original linked list.
*/
/*
//Apprach: Using HashMap
1. Create a hash map to store the mapping between original nodes and their corresponding copied nodes.
2. Traverse the original linked list and for each node, create a new node with the same value and store the mapping in the hash map.
3. Traverse the original linked list again and for each node, set the next and random pointers of the corresponding copied node using the hash map.
*/
#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        unordered_map<Node *, Node *> hashMap;
        Node *cur = head;

        while (cur != nullptr)
        {
            hashMap[cur] = new Node(cur->val);
            cur = cur->next;
        }
        cur = head;

        while (cur != NULL)
        {
            Node *copy = hashMap[cur];
            copy->next = hashMap[cur->next];
            copy->random = hashMap[cur->random];
            cur = cur->next;
        }
        return hashMap[head];
    }
};

int main(){

    Node* head = new Node(1);
    head->next = new Node(2);
    head->random = head->next;

    Solution sol;
    sol.copyRandomList(head);   //TC:O(n)  SC:O(n)

    while(head != nullptr){
        cout << head->val << " ";
        head = head->next;
    }

}
/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 55__11-04-2026__Copy_List_random_pointers.cpp -o 55__11-04-2026__Copy_List_random_pointers } ; if ($?) { .\55__11-04-2026__Copy_List_random_pointers }
1 2
*/
