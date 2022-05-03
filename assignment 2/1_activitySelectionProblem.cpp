#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
using namespace std;

bool myCompare(pair<int,int>p1, pair<int,int>p2)
{
    //to sort activities in ascencind order of finish time
    return (p1.second<p2.second); 
}

void activitySelection(vector<pair<int,int>>v)
{
    if(v.size()==0)
    {
        cout<<"no activites given"<<endl; 
        return;
    } 


    sort(v.begin(), v.end(), myCompare); //sort activities in ascending order of their finish time
    
    vector<pair<int,int>> solution; //solution vector
    
    solution.push_back(v[0]); //pushing the first activity to the solution vecotr
  
    int res=1; //number of activities that can be done
    for (int i=1;i<v.size();i++)
    {
        if (v[i].first>solution.back().second) //checking if the current activity current overlaps the last activity
        {
            solution.push_back(v[i]); //if it doesn't overlap, it is added to the solution
            res++;
        }             
    }

    //printing the solution
    cout<<"The number of activities that can be done is: "<<res<<endl;
    cout<<"The activites are:"<<endl;
    for (int i=0;i<solution.size();i++)
    {
        cout<<solution[i].first<<" "<<solution[i].second<<endl;
    }
}

int main()
{
    vector<pair<int,int>> v;
    int n; cin>>n;
    int a,b;
    for (int i=0;i<n;i++)
    {
        cin>>a>>b;
        v.push_back(make_pair(a,b));
    }
    activitySelection(v);

    return 0;
}