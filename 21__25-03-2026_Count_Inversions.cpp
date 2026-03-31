//Count Inversions- Merge Sort
#include <bits/stdc++.h>

using namespace std;


/*
 * Complete the 'countInversions' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */
long merge(vector<int> &arr, int p, int q, int r)
{
    long ans = 0;
    int n1 = (q - p + 1);
    int n2 = r - q;
    vector<int> L(n1 + 1);
    vector<int> R(n2 + 1);
    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[p + i];
    }
    for (int i = 0; i < n2; i++)
    {
        R[i] = arr[q + i + 1];
    }

    int i = 0, j = 0, k = p;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k++] = L[i++];
        }
        else
        {
            arr[k++] = R[j++];
            ans += (n1 - i);
        }
    }
    while (i < n1)
    {
        arr[k++] = L[i++];
    }
    while (j < n2)
    {
        arr[k++] = R[j++];
    }
    return ans;
}
long MergeSort(vector<int> &arr, int p, int r)
{
    long inv = 0;
    if (p < r)
    {
        int q = p + (r - p) / 2;
        inv += MergeSort(arr, p, q);
        inv += MergeSort(arr, q + 1, r);
        inv += merge(arr, p, q, r);
    }
    return inv;
}
long countInversions(vector<int> arr)
{
    return MergeSort(arr, 0, arr.size() - 1);
}

int main()
{
vector<int>arr={3,4,5,2,1};
    cout<<countInversions(arr)<<endl;   //TC:(O(N*log(N)), SC:O(N)
}
/*
PS C:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice> cd "c:\Users\bhish\OneDrive\Desktop\DSA_PRACTICE_CPP\DSA_Practice\" ; if ($?) { g++ 21__25-03-2026_Count_Inversions.cpp -o 21__25-03-2026_Count_Inversions } ; if ($?) { .\21__25-03-2026_Count_Inversions }
7
*/
