/*
Given a 2D array of characters grid of size m x n, you need to find if there exists any cycle consisting of the same value in grid.

A cycle is a path of length 4 or more in the grid that starts and ends at the same cell. From a given cell, you can move to one of the cells adjacent to it - in one of the four directions (up, down, left, or right), if it has the same value of the current cell.

Also, you cannot move to the cell that you visited in your last move. For example, the cycle (1, 1) -> (1, 2) -> (1, 1) is invalid because from (1, 2) we visited (1, 1) which was the last visited cell.

Return true if any cycle of the same value exists in grid, otherwise, return false.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dfs(int i,int j,int pi,int pj,vector<vector<char>>&grid,vector<vector<int>>&visited,int r,int c){
        visited[i][j]=1;
        //move up
        if((i-1)>=0 && grid[i-1][j]==grid[i][j]){
            if(visited[i-1][j]==0){
                if(dfs(i-1,j,i,j,grid,visited,r,c)) return 1;
            }
            else if(i-1!=pi || j!=pj){
                return 1;
            }
        }
        //move down
        if((i+1)<r && grid[i+1][j]==grid[i][j]){
            if(visited[i+1][j]==0){
                if(dfs(i+1,j,i,j,grid,visited,r,c)) return 1;
            }
            else if(i+1!=pi || j!=pj){
                return 1;
            }
        }

        //move left
        if((j-1)>=0 && grid[i][j-1]==grid[i][j]){
            if(visited[i][j-1]==0){
                if(dfs(i,j-1,i,j,grid,visited,r,c)) return 1;
            }
            else if(i!=pi || j-1!=pj){
                return 1;
            }
        }

         //move right
        if((j+1)<c && grid[i][j+1]==grid[i][j]){
            if(visited[i][j+1]==0){
                if(dfs(i,j+1,i,j,grid,visited,r,c)) return 1;
            }
            else if(i!=pi || j+1!=pj){
                return 1;
            }
        }
        return 0;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        vector<vector<int>>visited(rows,vector<int>(cols,0));

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(visited[i][j]==0){
                    int temp=dfs(i,j,-1,-1,grid,visited,rows,cols);
                    if(temp==1){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

int main(){
    Solution s;
    vector<vector<char>>grid={{'a','a','a','a'},{'a','b','b','a'},{'a','b','b','a'},{'a','a','a','a'}};
    cout<<s.containsCycle(grid)<<endl;  //TC:O(m*n) SC:O(m*n)
    return 0;
}
/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 116__22-05-2026_Detect_Cycle_DFS.cpp -o 116__22-05-2026_Detect_Cycle_DFS } ; if ($?) { .\116__22-05-2026_Detect_Cycle_DFS }
1
*/
