/*
A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

For example, the next permutation of arr = [1,2,3] is [1,3,2].
Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
Given an array of integers nums, find the next permutation of nums.

The replacement must be in place and use only constant extra memory.
*/
/*
Strategy
We need to find the first decreasing element from the right of the list.
Then, we need to find the smallest element from the right side that is greater than the first decreasing element.
We swap these two elements
Finally we reverse the sublist from the first decreasing element to the end of the list.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int i = nums.size() - 1;
        while (i > 0 && nums[i - 1] >= nums[i])
        {
            i--;
        }
        if (i == 0)
        {
            reverse(nums.begin(), nums.end());
            return;
        }
        int j = nums.size() - 1;
        while (j >= i && nums[j] <= nums[i - 1])
        {
            j--;
        }
        swap(nums[i - 1], nums[j]);
        reverse(nums.begin() + i, nums.end());
    }
};

int main(){
Solution sol;
vector<int>nums={1,2,3};
sol.nextPermutation(nums);
for(int i:nums){
    cout<<i<<" ";
}
}

/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 13__21-03-2026_Next_Permutation.cpp -o 13__21-03-2026_Next_Permutation } ; if ($?) { .\13__21-03-2026_Next_Permutation }
1 3 2
*/
