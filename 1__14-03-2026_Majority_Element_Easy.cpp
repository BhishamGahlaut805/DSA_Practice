// DSA Question 1- EASY - Majority Element
// Given an array nums of size n, return the majority element.The majority element is the element that appears more than ⌊n / 2⌋ times.You may assume that the majority element always exists in the array.

#include<iostream>
#include<unordered_map>
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
            if (mp[nums[i]] > (n / 2))
            {
                return nums[i];
            }
        }

        return -1;
    }
};

class Solution_Optimised    //O(1)Space
{
public:
    int majorityElement(vector<int> &nums)
    {
        int candidate = 0;
        int count = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (count == 0)
            {
                candidate = nums[i];
            }
            if (nums[i] == candidate)
            {
                count++;
            }
            else
            {
                count--;
            }
        }
        return candidate;
    }
};
int main(){
    Solution sol;
    Solution_Optimised sol1;
    vector<int>nums={1,2,2,3,4,4,4,4,4,4};
    cout<<sol.majorityElement(nums)<<endl;  //TC:O(n), SC:O(n)
    cout<<sol1.majorityElement(nums)<<endl; //TC:O(n) ,SC:O(1)

}

/*Output:
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 1__14-03-2026_Majority_Element_Easy.cpp -o 1__14-03-2026_Majority_Element_Easy } ; if ($?) { .\1__14-03-2026_Majority_Element_Easy }
4
4
*/
