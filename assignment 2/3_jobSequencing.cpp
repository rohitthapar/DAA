#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
#define MAX 100

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

int main()
{
    vector<job> jobs;
    
}