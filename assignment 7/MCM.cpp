#include<iostream>
#include<climits>
using namespace std;

int MCM(int arr[], int n)
{
    //matrix chain mnultiplication
    int dp[100][100];
    for (int i = 1; i < n; i++)
        dp[i][i] = 0;
    for (int gap = 2; gap < n; gap++)
    {
        for (int i = 1; i < n - gap + 1; i++)
        {
            int j = i + gap - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++)
            {

                int q = dp[i][k] + dp[k + 1][j]
                    + arr[i - 1] * arr[k] * arr[j];
                if (q < dp[i][j])
                    dp[i][j] = q;
            }
        }
    }
 
    return dp[1][n - 1];
}

int main()
{
    int n;
    cin>>n;
    int arr[100];
    for (int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"minimum number of multiplications"<<MCM(arr,n);
}