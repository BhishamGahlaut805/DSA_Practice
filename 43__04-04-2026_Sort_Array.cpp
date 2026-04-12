#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void Merge(vector<int> &nums, int p, int q, int r)
    {
        int n1 = q - p + 1;
        int n2 = r - q;
        vector<int> L(n1);
        vector<int> R(n2);

        // Fill the left half
        for (int i = 0; i < n1; i++)
        {
            L[i] = nums[p + i];
        }

        // Fill the right half
        for (int j = 0; j < n2; j++)
        {
            R[j] = nums[q + 1 + j];
        }

        // Merge the two halves back into nums
        int i = 0; // Initial index of first sub-array
        int j = 0; // Initial index of second sub-array
        int k = p; // Initial index of merged sub-array

        while (i < n1 && j < n2)
        {
            if (L[i] <= R[j])
            {
                nums[k] = L[i];
                i++;
            }
            else
            {
                nums[k] = R[j];
                j++;
            }
            k++;
        }

        // Copy the remaining elements of L, if there are any
        while (i < n1)
        {
            nums[k] = L[i];
            i++;
            k++;
        }

        // Copy the remaining elements of R, if there are any
        while (j < n2)
        {
            nums[k] = R[j];
            j++;
            k++;
        }
    }

    void MergeSort(vector<int> &nums, int p, int r)
    {
        if (p < r)
        {
            int q = p + (r - p) / 2; // Avoids overflow
            MergeSort(nums, p, q);
            MergeSort(nums, q + 1, r);
            Merge(nums, p, q, r);
        }
    }

    vector<int> sortArray(vector<int> &nums)
    {
        int n = nums.size();
        if (n > 0)
        {
            MergeSort(nums, 0, n - 1);
        }
        return nums;
    }
};

int main(){

    Solution sol;
    vector<int>nums={5,3,2,7};
   nums= sol.sortArray(nums);   //TC:O(N*log(N)), SC:O(N)
   
    for(auto i:nums){
        cout<<i<<" ";
    }
}
/*

PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 43__03-04-2026_Sort_Array.cpp -o 43__03-04-2026_Sort_Array } ; if ($?) { .\43__03-04-2026_Sort_Array }
2 3 5 7
*/

