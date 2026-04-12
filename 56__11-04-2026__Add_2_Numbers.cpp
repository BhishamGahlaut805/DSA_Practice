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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *temp = new ListNode(0);
        ListNode *tail = temp;

        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0)
        {
            int d1 = (l1 == NULL) ? 0 : l1->val;
            int d2 = (l2 == NULL) ? 0 : l2->val;
            int sum = d1 + d2 + carry;
            int digit = sum % 10;
            carry = sum / 10;

            ListNode *newNode = new ListNode(digit);
            tail->next = newNode;
            tail = tail->next;

            l1 = (l1 == NULL) ? NULL : l1->next;
            l2 = (l2 == NULL) ? NULL : l2->next;
        }
        ListNode *ans = temp->next;
        delete (temp);
        return ans;
    }
};
int main(){
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    Solution sol;
    ListNode* ans = sol.addTwoNumbers(l1, l2);  //TC:O(max(m,n))  SC:O(max(m,n))

    while(ans != nullptr){
        cout << ans->val << " ";
        ans = ans->next;
    }

}
/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 56__11-04-2026__Add_2_Numbers.cpp -o 56__11-04-2026__Add_2_Numbers } ; if ($?) { .\56__11-04-2026__Add_2_Numbers }
7 0 8
*/
