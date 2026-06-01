/*
Given an n x n matrix where each of the rows and columns is sorted in ascending order, return the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

You must find a solution with a memory complexity better than O(n2).
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        if(n==1)return matrix[0][0];

        int left=matrix[0][0];
        int right=matrix[n-1][n-1];
        while(left<right){
            int mid=left+(right-left)/2;
            int st=0;
            int en=n-1;

            for(auto row:matrix){
                while(en>=0 and row[en]>mid){
                    en--;
                }
                st+=en+1;
            }
            if(st<k){
                left=mid+1;
            }
            else{
                right=mid;
            }
        }
        return left;
    }
};

int main(){
    Solution s;
    vector<vector<int>> matrix={{1,5,9},{10,11,13},{12,13,15}}; //TC:O(nlog(max-min)) SC:O(1)
    int k=8;
    cout<<s.kthSmallest(matrix,k)<<endl;
    return 0;
}
/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 130__01-06-2026_Search_In_Sorted_Matrix.cpp -o 130__01-06-2026_Search_In_Sorted_Matrix } ; if ($?) { .\130__01-06-2026_Search_In_Sorted_Matrix }
13
*/
