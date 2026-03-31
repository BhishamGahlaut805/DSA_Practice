#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    string minWindow(string s, string t) {
        if(s.length()<t.length()) return "";
        unordered_map<char,int>charCount;
        for(char ch:t){
            charCount[ch]++;
        }

        int targetCharsRemaining=t.length();
        int minWindow[2]={0,INT_MAX};
        int startIndex=0;

        for(int endIndex=0;endIndex<s.length();endIndex++){
            char ch=s[endIndex];
            if(charCount.find(ch)!=charCount.end() && charCount[ch]>0){
                targetCharsRemaining--;
            }
            charCount[ch]--;

            if(targetCharsRemaining==0){
                while(true){
                    char charAtStart=s[startIndex];
                    if(charCount.find(charAtStart)!=charCount.end() && charCount[charAtStart]==0){

                        break;
                    }
                    charCount[charAtStart]++;
                    startIndex++;

                }

                if(endIndex-startIndex<minWindow[1]-minWindow[0]){
                    minWindow[0]=startIndex;
                    minWindow[1]=endIndex;

                }
                charCount[s[startIndex]]++;
                targetCharsRemaining++;
                startIndex++;

            }
        }
        return minWindow[1]>=s.length() ? "" : s.substr(minWindow[0],minWindow[1]-minWindow[0]+1);

    }
};

int main(){
    Solution sol;
    string s = "ADOBECODEBANC";
    string t="ABC";
    cout << sol.minWindow(s, t); // TC:O(S+T),SC:O(S+T)
}

/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 38__30-03-2026_Minimum_Sliding_Window.cpp -o 38__30-03-2026_Minimum_Sliding_Window } ; if ($?) { .\38__30-03-2026_Minimum_Sliding_Window }
BANC
*/

