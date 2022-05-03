#include<iostream>
#include<vector>
using namespace std;


void mergeSort(vector<int>v, int l, int m, int r)
{
    int n1=(m-l)+1;
    int n2=r-(m+1)+1;
    vector<int> v1(r-l+1);
    int i=l,j=m+1,k=0;
    while(i<=m && j<=r)
    {
        if (v[i]<v[j])
        {
            v1[k]=v[i];
            i++;
        }
        else
        {
            v1[k]=v[j];
            j++;
        }
        k++;
    }
    while(i<=m)
    {
        v1[k]=v[i];
        i++;
        k++;
    }
    while(j<=r)
    {
        v1[k]=v[j];
        j++;
        k++;
    }
    for (int i=0;i<v1.size();i++)
    {
        v[l+i]=v1[i];
    }
}
void merge (vector<int> v,int l, int r)
{
    if (l<r)
    {
        int m=(r+(r-l))/2;
        merge(v,l,m);
        merge(v,m+1,r);
        mergeSort(v,l,m,r);   
    }
}

int main()
{
    int n; cin>>n;
    vector<int> v;
    int a;
    for (int i=0;i<n;i++)
    {
        cin>>a;
        v.push_back(a);
    }
    merge(v,0,n-1);
    for (int i=0;i<n;i++)
    {
        cout<<v[i]<<" ";
    }
    return 0;
}