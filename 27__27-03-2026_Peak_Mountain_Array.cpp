/*
You are given an integer mountain array arr of length n where the values increase to a peak element and then decrease.

Return the index of the peak element.

Your task is to solve it in O(log(n)) time complexity.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int st=0;
        int en=arr.size()-1;
        while(st<en){
            int mid=st+(en-st)/2;
            if(arr[mid]>arr[mid+1]){
                en=mid;
            }
            else{
                st=mid+1;
            }
        }
        return st;
    }
};

int main(){

    Solution sol;
    vector<int>nums={0,10,5,2};
    cout<<sol.peakIndexInMountainArray(nums);   //TC:O(log(N)), SC;O(1)
}
/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 27__27-03-2026_Peak_Mountain_Array.cpp -o 27__27-03-2026_Peak_Mountain_Array } ; if ($?) { .\27__27-03-2026_Peak_Mountain_Array }
1
*/

