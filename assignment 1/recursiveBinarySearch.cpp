#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int>v, int low, int high, int x)
{
    if (low>high) return -1;
    int mid=(low+high)/2;
    if (v[mid]==x) 
    {
        return mid;
    }
    else if (v[mid]>x)
    {
        binarySearch(v,low,mid-1,x);
    }
    else if (v[mid]<x)
    {
        binarySearch(v,mid+1,high,x);
    }
}

int main()
{
    int n; cin>>n;
    vector<int>v;
    for (int i=0;i<n;i++)
    {
       cin>>v[i]; 
    }
    int x; cin>>x;
    binarySearch(v,0,n-1,x);
    return 0;
}