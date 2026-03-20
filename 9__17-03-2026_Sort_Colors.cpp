//Sort Colors of Os,1s and 2s

#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int low = 0;
        int high = nums.size() - 1;
        int mid = 0;

        while (mid <= high)
        {
            if (nums[mid] == 0)
            {
                swap(nums[mid], nums[low]);
                low++;
                mid++;
            }
            else if (nums[mid] == 1)
            {
                mid++;
            }
            else
            {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};

int main(){

    vector<int>nums={1,0,2,1,0,2,1,0,2,1,0,2};  //TC:O(n),SC:O(1)
    Solution sol;
    sol.sortColors(nums);
    for(int i:nums){
        cout<<i<<" ";
    }
}
/*
Output:
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 9__17-03-2026_Sort_Colors.cpp -o 9__17-03-2026_Sort_Colors } ; if ($?) { .\9__17-03-2026_Sort_Colors }
0 0 0 0 1 1 1 1 2 2 2 2
*/
