#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int>v, int x)
{
    int low=0;
    int high=v.size()-1;
    int mid;
    while(high>=low)
    {
        mid=(high+low)/2;
        if (v[mid]==x)
        {
            return mid;
        }
        else if (v[mid]>x)
        {
            high=mid-1;
        }
        else if (v[mid]<x)
        {
            low=mid+1;
        }
    }
    return -1;
}
int main()
{
    int n; cin>>n;
    vector<int> v;
    for (int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    int x; cin>>x;
    binarySearch(v,x);
    return 0;
}