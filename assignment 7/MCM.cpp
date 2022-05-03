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

int matrixChainMultiplication(vector<int>p)
{
    int n=p.size();
    vector<vector<int>>dp(n,vector<int>(n,0));
     
    //0th row and 0th colomn is always unused
    //lower triangular matrix is 0
    for(int i=1;i<n;i++)
    {
        dp[i][i]=0;
    }
    for (int l = 2; l < n; l++)
    {
        for (int i = 1; i < n - l + 1; i++)
        {
            int j = i + l - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++)
            {
                int q = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < dp[i][j])
                    dp[i][j] = q;
            }
        }
    }
    return dp[1][n-1];
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin>>n;
    vector<int>p(n);
    for(int i=0;i<n;i++)
    {
        cin>>p[i];
    }
    cout<<"Minimum number of multiplications is "<<matrixChainMultiplication(p);    

    return 0;
}