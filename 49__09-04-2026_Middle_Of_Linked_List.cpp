#include <bits/stdc++.h>
using namespace std;

//  * Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
// insert at end of linked list

void insertAtEnd(ListNode *&head, int val)
{
    ListNode *newNode = new ListNode(val);
    if (head == nullptr)
    {
        head = newNode;
        return;
    }
    ListNode *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}
int main()
{

    Solution sol;
    ListNode *head = nullptr;

    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);
    insertAtEnd(head, 4);
    insertAtEnd(head, 5);

    cout << "Original List : ";

    ListNode *temp = head;
    while (temp != nullptr)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    ListNode*res=sol.middleNode(head);  //TC:O(N), SC:O(1)
    cout<<"middle of Linked list node is : "<<res->val<<endl;
}

/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 49__09-04-2026_Middle_Of_Linked_List.cpp -o 49__09-04-2026_Middle_Of_Linked_List } ; if ($?) { .\49__09-04-2026_Middle_Of_Linked_List }
Original List : 1 2 3 4 5 middle of Linked list node is : 3
*/

