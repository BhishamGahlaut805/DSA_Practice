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
//Solution approach:
/*
Step1: Traverse the linked list until you reach the left position. Keep track of the previous node (prev) and the current node (curr) at the left position.
Step2: Reverse the sublist from left to right. Use three pointers: prev, curr, and next. Iterate through the sublist, reversing the next pointers of the nodes until you reach the right position.
Step3: Connect the reversed sublist back to the original list. If left is 1, update the head of the list to the new head of the reversed sublist. Otherwise, connect the previous node (prev) to the new head of the reversed sublist and connect the tail of the reversed sublist to the next node after right.
Step4: Return the head of the modified linked list.
*/
class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (!head || left == right)
        {
            return head;
        }
        int i = 1;
        ListNode *temp = head;
        while (i < left)
        {
            temp = temp->next;
            i++;
        }

        ListNode *prev = NULL;
        ListNode *curr = temp;
        while (curr != NULL && i <= right)
        {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            i++;
        }
        if (left == 1)
        {
            head->next = curr;
            return prev;
        }
        temp = head;
        i = 1;
        while (i < left - 1)
        {
            temp = temp->next;
            i++;
        }

        temp->next->next = curr;
        temp->next = prev;
        return head;
    }
};
int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int left = 2, right = 4;

    Solution sol;
    ListNode *ans = sol.reverseBetween(head, left, right); //TC:O(n)  SC:O(1)

    while (ans != nullptr)
    {
        cout << ans->val << " ";
        ans = ans->next;
    }
}
/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 57__11-04-2026_Reverse_Linked_List2.cpp -o 57__11-04-2026_Reverse_Linked_List2 } ; if ($?) { .\57__11-04-2026_Reverse_Linked_List2 }
1 4 3 2 5
*/
