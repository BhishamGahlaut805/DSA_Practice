/*
Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).

Implement the MyStack class:

void push(int x) Pushes element x to the top of the stack.
int pop() Removes the element on the top of the stack and returns it.
int top() Returns the element on the top of the stack.
boolean empty() Returns true if the stack is empty, false otherwise.
Notes:

You must use only standard operations of a queue, which means that only push to back, peek/pop from front, size and is empty operations are valid.
Depending on your language, the queue may not be supported natively. You may simulate a queue using a list or deque (double-ended queue) as long as you use only a queue's standard operations.
*/
#include <bits/stdc++.h>
using namespace std;

class MyStack
{
    // single queue solution
    // TC:O(N), SC:O(N)
    queue<int> q;

public:
    MyStack()
    {
    }

    void push(int x)
    {
        q.push(x);
        for (int i = 0; i < q.size() - 1; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    int pop()
    {
        int top_ = q.front();
        q.pop();
        return top_;
    }

    int top()
    {
        return q.front();
    }

    bool empty()
    {
        return q.empty();
    }
};
class MyStack_optimzed
{
    // using 2 queues
    // TC:O(1), SC:O(N)
    queue<int> q1;
    queue<int> q2;

public:
    MyStack_optimzed()
    {
    }

    void push(int x)
    {
        q1.push(x);
    }

    int pop()
    {
        while (q1.size() > 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int to_pop = q1.front();
        q1.pop();
        swap(q1, q2);
        return to_pop;
    }

    int top()
    {
        while (q1.size() > 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int to_top = q1.front();
        q2.push(q1.front());
        q1.pop();
        swap(q1, q2);
        return to_top;
    }

    bool empty()
    {
        return q1.empty() && q2.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

int main()
{
    MyStack *obj = new MyStack();
    obj->push(1);
    obj->push(2);
    cout << obj->top() << endl;   // 2
    cout << obj->pop() << endl;   // 2
    cout << obj->empty() << endl; // false
    return 0;
}
 /*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 77__21-04-2026_Implement_Stack_using_queue.cpp -o 77__21-04-2026_Implement_Stack_using_queue } ; if ($?) { .\77__21-04-2026_Implement_Stack_using_queue }
2
2
0
 */
