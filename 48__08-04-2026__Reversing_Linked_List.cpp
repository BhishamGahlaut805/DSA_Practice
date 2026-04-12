#include<bits/stdc++.h>
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
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        while (curr != nullptr)
        {
            ListNode *NextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = NextNode;
        }
        return prev;
    }
};

//insert at end of linked list

void insertAtEnd(ListNode* &head,int val){
    ListNode* newNode=new ListNode(val);
    if(head==nullptr){
        head=newNode;
        return;
    }
    ListNode* temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=newNode;
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

    ListNode *temp = head; //
    while (temp != nullptr)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }

    head = sol.reverseList(head);   // TC:O(n), SC:O(1)

    cout << "\nReversed List : ";

    temp = head;
    while (temp != nullptr)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
}
/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 48__08-04-2026__Reversing_Linked_List.cpp -o 48__08-04-2026__Reversing_Linked_List } ; if ($?) { .\48__08-04-2026__Reversing_Linked_List }
Original List : 1 2 3 4 5
Reversed List : 5 4 3 2 1
PS C:\Users\bhish\OneDrive\Deskto
*/
