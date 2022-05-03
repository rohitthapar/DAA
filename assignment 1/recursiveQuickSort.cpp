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

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

// function to rearrange array (find the partition point)
int partition(vector<int>&array, int low, int high) 
{    
    int pivot = array[high];
    int i = (low - 1); // index of smaller element
    for (int j = low; j <= high - 1; j++) 
    {
        // If current element is smaller than or
        // equal to pivot
        if (array[j] <= pivot) 
        {
            i++; // increment index of smaller element
            swap(array[i], array[j]);
        }
    }
    swap(array[i + 1], array[high]);
    return (i + 1);
}

void quickSort(vector<int>&array, int low, int high) 
{
  if (low < high) {
      
    // find the pivot element such that elements smaller than pivot are on left of pivot and elements greater than pivot are on righ of pivot
    int pi = partition(array, low, high);

    // recursive call on the left of pivot
    quickSort(array, low, pi - 1);

    // recursive call on the right of pivot
    quickSort(array, pi + 1, high);
  }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin>>n;
    vector <int> v(n);
    for (int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    cout << "Unsorted Array:"<<endl;
    for (int i=0;i<n;i++)
    {
        cout<<v[i]<<" ";
    }
    // perform quicksort on the given array
    quickSort(v, 0, n - 1);
    cout << "Sorted array in ascending order: \n";
    for (int i=0;i<n;i++)
    {
        cout<<v[i]<<" ";
    }
    return 0;
}