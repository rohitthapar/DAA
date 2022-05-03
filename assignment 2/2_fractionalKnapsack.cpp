#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//class showing the knapsack of each element
class knapsack{
    public:
        int value, weight;
};

//comparision function to sort the vector
bool myCompare(knapsack p1, knapsack p2)
{
    return p1.value/p1.weight>p2.value/p2.weight;
}

void fractionalKnapsack(vector<knapsack>v, int capacity)
{
    sort(v.begin(),v.end(),myCompare); //sorting the vector as per the value of each element
    int value=0; //value of the knapsack
    vector<knapsack>solution; //solution vector
    for (int i=0;i<v.size();i++)
    {
        if (v[i].weight<=capacity)
        {
            capacity-=v[i].weight;
            value+=v[i].value;
            solution.push_back(v[i]);

        }
        else
        {
            value+=(v[i].value/v[i].weight)*capacity;
            capacity=0;
            solution.push_back({v[i].value,(v[i].value/v[i].weight)*capacity});
        }
    }

    //printing the result
    cout<<"The maximum value of the knapsack is: "<<value<<endl;
    cout<<"Elements of knapsack"<<endl;
    for (int i = 0; i < solution.size(); i++)
    {
        cout<<solution[i].value<<" "<<solution[i].weight<<endl;
    }
}

int main()
{
    int n; cin>>n;
    vector<knapsack>v;
    for (int i=0; i<n; i++)
    {
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }
    int capacity;
    cin>>capacity;
    fractionalKnapsack(v,capacity);
    return 0;
}