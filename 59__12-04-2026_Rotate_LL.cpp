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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head)
            return head;

        int length = 1;
        ListNode *temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
            length++;
        }
        int pos = k % length;
        if (pos == 0)
            return head;

        ListNode *curr = head;
        for (int i = 0; i < length - pos - 1; i++)
        {
            curr = curr->next;
        }
        ListNode *newHead = curr->next;
        curr->next = nullptr;
        temp->next = head;
        return newHead;
    }
};

int main()
{
    Solution s;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 2;
    ListNode *newHead = s.rotateRight(head, k); //TC:O(n)  SC:O(1)

    // Print the rotated list
    ListNode *temp = newHead;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}
/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 59__12-04-2026_Rotate_LL.cpp -o 59__12-04-2026_Rotate_LL } ; if ($?) { .\59__12-04-2026_Rotate_LL }
4 5 1 2 3
*/
