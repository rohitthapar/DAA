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
typedef unsigned long long ll;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin>>T;
    while(T--)
    {
        ll n, h, w, high, low, mid, side;
        cin>>n>>h>>w;
        high=max(h,w)*n;
        low=0;
        while (high>=low)
        {
            mid=(low+high)/2;
            if ((mid/h)*(mid/w)>=n)
            {
                side=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        cout<<side<<endl;

    }
    return 0;
}