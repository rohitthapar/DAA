#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> &v,int m,int l,int r)
{
  vector<int> arr;

	int i = l;
	int j = m + 1;

	while (i <= m && j <= r) {

		if (v[i] <= v[j]) {
			arr.push_back(v[i]);
			++i;
		}
		else {
			arr.push_back(v[j]);
			++j;
		}

	}

	while (i <= m) {
		arr.push_back(v[i]);
		++i;
	}

	while (j <= r) {
		arr.push_back(v[j]);
		++j;
	}

	for (int i = l; i <= r; ++i)
		v[i] = arr[i - l];

}


void mergeSort(vector<int> &v, int l, int r)
{
    if (l<r)
    {
        int m= (l + r)/2;
        mergeSort(v,l,m);
        mergeSort(v,m+1,r);
        merge(v,m,l,r);
    }
}

int main()
{
    int n; 
    cin>>n;
    vector<int> v(n);
    for (int i=0;i<n;i++)
    {
        cin>>v[i];
    }

    cout<<"Array before sorting"<<endl;
    for (int i = 0; i < n; ++i) {
		cout << v[i] << ' ';
	}
    cout<<endl;
    mergeSort(v,0,n-1);
    cout<<"Array after sorting"<<endl;
    for (int i = 0; i < n; ++i) {
		cout << v[i] << ' ';
	}
    return 0;
}