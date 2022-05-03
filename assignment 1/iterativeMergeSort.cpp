#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
#include<stack>
#include<set>
#include<cmath>
#include<string>
#include<climits>
#include<unordered_map>
#include<unordered_set>
#include<iomanip>
#include<bitset>
using namespace std;
typedef long long ll;

void merge (vector<int> &arr, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    //create temp arrays 
    vector<int> L(n1);
    vector<int> R(n2);
 
    //Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
    // Merge the temp arrays back into arr[l..r]
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    // Copy the remaining elements of L[]
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    // Copy the remaining elements of R[]
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int> &arr)
{
    int n = arr.size();
    int currentSize; 
    int leftStart;
    for (currentSize = 1; currentSize < n; currentSize = 2*currentSize)
    {
        for (leftStart = 0; leftStart < n-1; leftStart += 2*currentSize)
        {
            int mid = leftStart + currentSize - 1;
            int rightEnd = min(leftStart + 2*currentSize - 1, n-1);
            merge(arr, leftStart, mid, rightEnd);
        }
    }
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    mergeSort(arr);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}