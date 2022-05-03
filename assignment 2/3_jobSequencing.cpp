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

class job
{
    public:
        char id;
        int deadline, profit;
};

bool myCompare(job j1, job j2)
{
    return j1.profit>j2.profit;
}

void jobSequencing(vector<job> jobs)
{
    sort(jobs.begin(), jobs.end(), myCompare);
    int n = jobs.size();
    vector<bool> slots(n, false);
    vector<int> result(n);
    int maxProfit = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=min(n, jobs[i].deadline)-1; j>=0; j--)
        {
            if (slots[j] == false)
            {
                slots[j] = true;
                result[j]=i;
                maxProfit += jobs[i].profit;
                break;
            }
        }
    }
    //sequence of jobs
    for(int i=0; i<n; i++)
    {
        if (slots[i])
            cout<<jobs[result[i]].id<<" ";
    }
    //maximum profit
    cout<<"\n"<<maxProfit;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<job> jobs;
    int n;
    cin>>n;
    char id;
    int deadline, profit;
    while(n--)
    {
        cin>>id>>deadline>>profit;
        job j;
        j.id = id;
        j.deadline = deadline;
        j.profit = profit;
        jobs.push_back(j);
    }
    jobSequencing(jobs);
    return 0;    
}