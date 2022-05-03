#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int value[100];
    int weight[100];
    int capacity;
    cin>>capacity;
    for(int i=0;i<n;i++)
    {
        cin>>value[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>weight[i];
    }
    int dp[100][100];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=capacity;j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j]=0;
            }
            else if(weight[i-1]<=j)
            {
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-weight[i-1]]+value[i-1]);
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    for (int i=0;i<=n;i++)
    {
        for (int j=0;j<=capacity;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<dp[n][capacity];

    //backtrack to find the weights used
    cout<<endl;
    cout<<"weights used"<<endl;
    for (int i=n;i>0;i--)
    {
        if(dp[i][capacity]==dp[i-1][capacity])
        {
            continue;
        }
        else
        {
            if(dp[i][capacity]==dp[i-1][capacity-weight[i-1]]+value[i-1])
            {
                cout<<weight[i-1]<<" ";
                capacity=capacity-weight[i-1];
            }
        }
    }
}