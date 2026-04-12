#include <bits/stdc++.h>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};


class Solution
{
public:
    Node *flatten(Node *head)
    {
        if (head == NULL)
        {
            return head;
        }
        Node *curr = head;
        while (curr != NULL)
        {
            if (curr->child != NULL)
            {
                Node *next = curr->next;
                curr->next = flatten(curr->child);
                curr->next->prev = curr;
                curr->child = NULL;

                while (curr->next != NULL)
                {
                    curr = curr->next;
                }
                if (next != NULL)
                {
                    curr->next = next;
                    next->prev = curr;
                }
            }
            curr = curr->next;
        }
        return head;
    }
};

int main(){

    Node* head = new Node();
    head->val = 1;
    head->next = new Node();
    head->next->val = 2;
    head->next->next = new Node();
    head->next->next->val = 3;
    head->child = new Node();
    head->child->val = 4;
    head->child->next = new Node();
    head->child->next->val = 5;

    Solution sol;
    Node* flattenedHead = sol.flatten(head); // TC: O(N) SC: O(1)

    // Print the flattened list
    Node* temp = flattenedHead;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }

}
/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 54__10-04-2026_Flatten_Linked_List.cpp -o 54__10-04-2026_Flatten_Linked_List } ; if ($?) { .\54__10-04-2026_Flatten_Linked_List }
1 4 5 2 3
*/
