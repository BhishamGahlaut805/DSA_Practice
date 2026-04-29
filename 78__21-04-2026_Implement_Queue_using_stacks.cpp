#include<bits/stdc++.h>
using namespace std;
class MyQueue
{
private:
    queue<int> ip;
    queue<int> op;

public:
    MyQueue()
    {
    }

    void push(int x)
    {
        ip.push(x);
    }

    int pop()
    {
        peek();
        int val = op.front();
        op.pop();
        return val;
    }

    int peek()
    {
        if (op.empty())
        {
            while (!ip.empty())
            {
                op.push(ip.front());
                ip.pop();
            }
        }
        return op.front();
    }

    bool empty()
    {
        return ip.empty() and op.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

 int main()
 {
     MyQueue* obj = new MyQueue();  //TC:O(1), SC:O(N)
     obj->push(1);
     obj->push(2);
     cout << obj->peek() << endl; // return 1
     cout << obj->pop() << endl;  // return 1
     cout << obj->empty() << endl; // return false
     return 0;
 }

 /*

PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 78__21-04-2026_Implement_Queue_using_stacks.cpp -o 78__21-04-2026_Implement_Queue_using_stacks } ; if ($?) { .\78__21-04-2026_Implement_Queue_using_stacks }
1
1
0
 */

 