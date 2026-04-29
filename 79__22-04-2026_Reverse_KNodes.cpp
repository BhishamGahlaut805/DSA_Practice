#include <bits/stdc++.h>
using namespace std;

//  * Definition for singly-linked list.
 struct ListNode {
     int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (!head)
            return NULL;

        ListNode *tail = head;
        for (int i = 0; i < k; i++)
        {
            if (!tail)
                return head;
            tail = tail->next;
        }
        ListNode *newHead = reverse(head, tail);
        head->next = reverseKGroup(tail, k);
        return newHead;
    }
    ListNode *reverse(ListNode *start, ListNode *end)
    {
        ListNode *prev = NULL;

        while (start != end)
        {
            ListNode *next = start->next;
            start->next = prev;
            prev = start;
            start = next;
        }
        return prev;
    }
};

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 2;
    Solution sol;
    ListNode *newHead = sol.reverseKGroup(head, k); //TC:O(N), SC:O(N/k) due to recursion stack

    // Print the reversed list
    ListNode *current = newHead;
    while (current)
    {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;

    return 0;
}
/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 79__22-04-2026_Reverse_KNodes.cpp -o 79__22-04-2026_Reverse_KNodes } ; if ($?) { .\79__22-04-2026_Reverse_KNodes }
2 1 4 3 5
*/
