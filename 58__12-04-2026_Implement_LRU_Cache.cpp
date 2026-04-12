#include <bits/stdc++.h>
using namespace std;

class LRUCache
{

public:
    class Node
    {
    public:
        int key;
        int val;
        Node *prev;
        Node *next;

        Node(int k, int v) : key(k), val(v) {}
    };

    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);

    int cap;
    unordered_map<int, Node *> m;

    LRUCache(int capacity)
    {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    void addNode(Node *newNode)
    {
        Node *temp = head->next;

        newNode->next = temp;
        newNode->prev = head;

        head->next = newNode;
        temp->prev = newNode;
    }
    void deleteNode(Node *delNode)
    {
        Node *prevNode = delNode->prev;
        Node *nextNode = delNode->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    int get(int key)
    {
        if (m.find(key) != m.end())
        {
            Node *resNode = m[key];
            int ans = resNode->val;

            // Return the value by making it MRU in doubly ll
            m.erase(key);
            deleteNode(resNode);
            addNode(resNode);
            m[key] = head->next;
            return ans;
        }
        return -1;
    }

    void put(int key, int value)
    {
        // Key already exists-- Make it MRU
        if (m.find(key) != m.end())
        {
            Node *curr = m[key];
            m.erase(key);
            deleteNode(curr);
        }
        // Delete the LRU data
        if (m.size() == cap)
        {
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new Node(key, value));
        m[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

 int main()
{    LRUCache *cache = new LRUCache(2); // Cache capacity is 2  //TC:O(1)  SC:O(capacity)

    cache->put(1, 1); // Cache is {1=1}
    cache->put(2, 2); // Cache is {1=1, 2=2}

    cout << cache->get(1) << endl; // Returns 1, Cache is {2=2, 1=1}

    cache->put(3, 3); // Evicts key 2, Cache is {1=1, 3=3}

    cout << cache->get(2) << endl; // Returns -1 (not found)

    cache->put(4, 4); // Evicts key 3, Cache is {1=1, 4=4}

    cout << cache->get(3) << endl; // Returns -1 (not found)
    cout << cache->get(4) << endl; // Returns 4

    return 0;
}
/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 58__12-04-2026_Implement_LRU_Cache.cpp -o 58__12-04-2026_Implement_LRU_Cache } ; if ($?) { .\58__12-04-2026_Implement_LRU_Cache }
1
-1
3
4
*/
