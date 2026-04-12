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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *final = (ListNode *)malloc(sizeof(ListNode));
        ListNode *new1 = new ListNode();
        final = new1;

        if (list1 == NULL)
        {
            return list2;
        }
        if (list2 == NULL)
        {
            return list1;
        }
        while (list1 != NULL && list2 != NULL)
        {
            if (list1->val > list2->val)
            {
                final->next = list2;
                final = final->next;
                list2 = list2->next;
            }
            else
            {
                final->next = list1;
                final = final->next;
                list1 = list1->next;
            }
        }
        if (list2 != NULL)
        {
            final->next = list2;
            final = final->next;
            list2 = list2->next;
        }
        if (list1 != NULL)
        {
            final->next = list1;
            final = final->next;
            list1 = list1->next;
        }
        return new1->next;
    }
};

int main(){
    ListNode*head1=new ListNode(1);
    ListNode*head2=new ListNode(2);
    ListNode*head3=new ListNode(5);

    head1->next=head2;
    head2->next=head3;
    head3->next=nullptr;

    ListNode *head11 = new ListNode(3);
    ListNode *head21 = new ListNode(4);

    head11->next = head21;
    head21->next =nullptr;

   Solution sol;
    ListNode*ans=sol.mergeTwoLists(head1,head11);
    while(ans!=nullptr){
        cout<<ans->val<<" ";
        ans=ans->next;
    }
}
/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 50__09-04-2026__Merge_Sorted_Lists.cpp -o 50__09-04-2026__Merge_Sorted_Lists } ; if ($?) { .\50__09-04-2026__Merge_Sorted_Lists }
1 2 3 4 5
*/


