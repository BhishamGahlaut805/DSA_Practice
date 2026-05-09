/*
There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to its next (i + 1)th station. You begin the journey with an empty tank at one of the gas stations.

Given two integer arrays gas and cost, return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1. If there exists a solution, it is guaranteed to be unique.
*/

#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int TotalGas = 0;
        int TotalCost = 0;
        for (int i = 0; i < gas.size(); i++)
        {
            TotalGas += gas[i];
            TotalCost += cost[i];
        }
        if (TotalGas < TotalCost)
        {
            return -1;
        }
        int startingIdx = 0;
        int CurrentGas = 0;
        for (int i = 0; i < gas.size(); i++)
        {
            CurrentGas += gas[i] - cost[i];
            if (CurrentGas < 0)
            {
                CurrentGas = 0;
                startingIdx = i + 1;
            }
        }
        return startingIdx;
    }
};

int main()
{
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};
    Solution sol;
    cout << sol.canCompleteCircuit(gas, cost) << endl; // TC: O(n), SC: O(1)
    return 0;
}
/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 88__01-05-2026_Gas_Station.cpp -o 88__01-05-2026_Gas_Station } ; if ($?) { .\88__01-05-2026_Gas_Station }
3
*/


