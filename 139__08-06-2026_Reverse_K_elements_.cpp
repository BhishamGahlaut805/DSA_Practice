/*
Given an integer k and a queue of integers, we need to reverse the order of the first k elements of the queue, leaving the other elements in the same relative order.

Only following standard operations are allowed on queue.

enqueue(x) : Add an item x to rear of queue
dequeue() : Remove an item from front of queue
size() : Returns number of elements in queue.
front() : Finds front item.
Note: The above operations represent the general processings. In-built functions of the respective languages can be used to solve the problem.

"If the size of queue is smaller than the given k , then return the original queue."
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    queue<int> reverseFirstK(queue<int> q, int k)
    {
        // code here
        if (q.size() < k)
        {
            return q;
        }
        int n = q.size();
        stack<int> stk;
        for (int i = 0; i < k; i++)
        {
            stk.push(q.front());
            q.pop();
        }
        for (int i = 0; i < k; i++)
        {
            q.push(stk.top());
            stk.pop();
        }

        for (int i = 0; i < (n - k); i++)
        {
            int ele = q.front();
            q.pop();
            q.push(ele);
        }
        return q;
    }
};

int main()
{
    int n, k;
    cin >> n >> k;
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        q.push(x);
    }
    Solution ob;
    queue<int> result = ob.reverseFirstK(q, k);
    while (!result.empty())
    {
        cout << result.front() << " ";
        result.pop();
    }
    cout << endl;
    return 0;
}
/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 139__08-06-2026_Reverse_K_elements_.cpp -o 139__08-06-2026_Reverse_K_elements_ } ; if ($?) { .\139__08-06-2026_Reverse_K_elements_ }
6 2
1 2 3 4 5 6
2 1 3 4 5 6
*/
