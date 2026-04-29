/*

You are part of a university admissions office and need to keep track of the kth highest test score from applicants in real-time. This helps to determine cut-off marks for interviews and admissions dynamically as new applicants submit their scores.

You are tasked to implement a class which, for a given integer k, maintains a stream of test scores and continuously returns the kth highest test score after a new score has been submitted. More specifically, we are looking for the kth highest score in the sorted list of all scores.

Implement the KthLargest class:

KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of test scores nums.
int add(int val) Adds a new test score val to the stream and returns the element representing the kth largest element in the pool of test scores so far.
*/

#include <bits/stdc++.h>
using namespace std;

class KthLargest
{
    int num;
    priority_queue<int, vector<int>, greater<int>> pq;

public:
    KthLargest(int k, vector<int> &nums)
    {
        num = k;
        for (auto ele : nums)
        {
            pq.push(ele);
            if (pq.size() > k)
            {
                pq.pop();
            }
        }
    }

    int add(int val)
    {
        pq.push(val);
        if (pq.size() > num)
        {
            pq.pop();
        }
        return pq.top();
    }
};

int main(){
    int k = 3;
    vector<int> nums = {4, 5, 8, 2};
    KthLargest* obj = new KthLargest(k, nums);  //TC: O(n log k) where n is the number of elements in nums, SC: O(k)
    cout << obj->add(3) << endl; // returns 4
    cout << obj->add(5) << endl; // returns 5
    cout << obj->add(10) << endl; // returns 5
    cout << obj->add(9) << endl; // returns 8
    cout << obj->add(4) << endl; // returns 8
    return 0;


}
/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 85__28-04-2026_Kth_Largest_BST.cpp -o 85__28-04-2026_Kth_Largest_BST } ; if ($?) { .\85__28-04-2026_Kth_Largest_BST }
4
5
5
8
8


*/