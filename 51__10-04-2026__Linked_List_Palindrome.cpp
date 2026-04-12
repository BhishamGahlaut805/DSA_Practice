// Given the head of a singly linked list, return true if it is a palindrome or false otherwise.
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

 //Step1: Find the Middle of the Linked List
 //Step2: Reverse the second half of the linked list
 //step3: compare the first and second half elements
class Solution {
public:
    bool isPalindrome(ListNode* head) {
     ListNode*slow=head;
     ListNode*fast=head;
     while(fast!=nullptr && fast->next != nullptr){
        slow=slow->next;
        fast=fast->next->next;
     }
     ListNode*prev=nullptr;
     while(slow!=nullptr){
        ListNode*temp=slow->next;
        slow->next=prev;
        prev=slow;
        slow=temp;
     }
     ListNode*first=head;
     ListNode*second=prev;

    while(second!=nullptr){
        if(first->val!=second->val){
            return false;

        }
        first=first->next;
        second=second->next;
    }
    return true;
    }
};

int main(){

    ListNode*head=new ListNode(1);
    head->next=new ListNode(2);
    head->next->next=new ListNode(2);
    head->next->next->next=new ListNode(1);
    Solution sol;
    if(sol.isPalindrome(head)){ //TC: O(N) SC: O(1)
        cout<<"The linked list is a palindrome."<<endl;
    }
    else{
        cout<<"The linked list is not a palindrome."<<endl;
    }
}
/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 51__10-04-2026__Linked_List_Palindrome.cpp -o 51__10-04-2026__Linked_List_Palindrome } ; if ($?) { .\51__10-04-2026__Linked_List_Palindrome }
The linked list is a palindrome.
*/
