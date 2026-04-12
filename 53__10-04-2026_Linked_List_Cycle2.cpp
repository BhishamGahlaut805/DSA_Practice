/*
Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

Do not modify the linked list.
*/
//Strategy: Floyd's Tortoise and Hare Algorithm
// Step1: Detect if a cycle exists using two pointers (slow and fast).
// Step2: If a cycle is detected, initialize one pointer to the head of the list and keep the other pointer at the meeting point. Move both pointers one step at a time until they meet again. The point at which they meet will be the start of the cycle.


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
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                break;
        }
        if (!fast || !fast->next)
            return nullptr;
        fast = head;
        while (fast != slow)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};

int main()
{

    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = head; // Creating a cycle

    Solution sol;
    ListNode *cycleStart = sol.detectCycle(head); // TC: O(N) SC: O(1)
    if (cycleStart)
    {
        cout << "The linked list has a cycle starting at node with value: " << cycleStart->val << endl;
    }
    else
    {
        cout << "The linked list does not have a cycle." << endl;
    }

    return 0;
}
/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 53__10-04-2026_Linked_List_Cycle2.cpp -o 53__10-04-2026_Linked_List_Cycle2 } ; if ($?) { .\53__10-04-2026_Linked_List_Cycle2 }
The linked list has a cycle starting at node with value: 1
*/