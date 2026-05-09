/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.
*/
#include <bits/stdc++.h>
using namespace std;
class MinStack
{
    vector<vector<int>> st;

public:
    MinStack()
    {
    }

    void push(int val)
    {
        int min_val = getMin();
        if (st.empty() || min_val > val)
        {
            min_val = val;
        }
        st.push_back({val, min_val});
    }

    void pop()
    {
        st.pop_back();
    }

    int top()
    {
        return st.empty() ? -1 : st.back()[0];
    }

    int getMin()
    {
        return st.empty() ? -1 : st.back()[1];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

 int main(){
    MinStack* obj = new MinStack();
    obj->push(-2);
    obj->push(0);
    obj->push(-3);
    cout << obj->getMin() << endl; // return -3
    obj->pop();
    cout << obj->top() << endl; // return 0
    cout << obj->getMin() << endl; // return -2
    return 0;
 }
 /*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 87__30-04-2026_Implement_Min_Stack.cpp -o 87__30-04-2026_Implement_Min_Stack } ; if ($?) { .\87__30-04-2026_Implement_Min_Stack }
-3
0
-2
 */
