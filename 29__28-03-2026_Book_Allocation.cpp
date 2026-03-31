/*
Given an array arr[] of integers, where each element arr[i] represents the number of pages in the i-th book. You also have an integer k representing the number of students. The task is to allocate books to each student such that:

Each student receives atleast one book.
Each student is assigned a contiguous sequence of books.
No book is assigned to more than one student.
The objective is to minimize the maximum number of pages assigned to any student. In other words, out of all possible allocations, find the arrangement where the student who receives the most pages still has the smallest possible maximum.

Note: If it is not possible to allocate books to all students, return -1.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findPages(vector<int> &arr, int k)
    {

        if (k > arr.size())
            return -1;

        int st = 0, en = 0, res = -1;
        for (int i = 0; i < arr.size(); i++)
        {
            st = max(st, arr[i]);
            en += arr[i];
        }

        while (st <= en)
        {
            int mid = st + (en - st) / 2;
            if (isPossible(arr, k, mid))
            {
                res = mid;
                en = mid - 1;
            }
            else
            {
                st = mid + 1;
            }
        }
        return res;
    }
    bool isPossible(vector<int> &arr, int k, int maxPages)
    {
        int students = 1, pageSum = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            pageSum += arr[i];
            if (pageSum > maxPages)
            {
                students++;
                pageSum = arr[i];
            }
            if (students > k)
            {
                return false;
            }
        }
        return true;
    }
};

int main(){
    Solution sol;
    vector<int>arr={12,34,67,90};   //Tc:O(n*log(m)) => n=books, m=pages , SC;O(n)
   cout<< sol.findPages(arr,2);
}

/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 29__28-03-2026_Book_Allocation.cpp -o 29__28-03-2026_Book_Allocation } ; if ($?) { .\29__28-03-2026_Book_Allocation }
113
*/
/*
Approach to solve the problem:
1. **Determine the Search Space**: The minimum number of pages that can be assigned to a student is the maximum number of pages in a single book (since a student must receive at least one book). The maximum number of pages that can be assigned to a student is the total number of pages in all books (if one student gets all the books).
2. **Binary Search**: Use binary search to find the optimal maximum number of pages. For each mid value (representing a potential maximum number of pages), check if it is possible to allocate books to students such that no student gets more than mid pages.
3. **Feasibility Check**: Create a helper function `isPossible` that checks if it is possible to allocate books to students with the given maximum pages. This function will iterate through the books and keep a running total of pages assigned to the current student. If the total exceeds mid, it will move on to the next student and reset the page count. If the number of students needed exceeds k, then mid is not a valid solution.
4. **Update Search Space**: If it is possible to allocate with mid as the maximum, then we can try to find a smaller maximum by moving the end of the search space down. If it is not possible, we need to increase the start of the search space.
5. **Return Result**: The result will be the minimum maximum number of pages that can be assigned to any student after the binary search completes.
Time Complexity: O(n log m), where n is the number of books and m is the total number of pages (the search space).

*/