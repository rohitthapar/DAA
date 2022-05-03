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

class directedGraph
{
    int v;
    vector<vector<int>> adj;
    
    public:
        directedGraph (int v)
        {
            this->v=v;
            adj.resize(v);
        }
        
        void addEdge(int u, int v)
        {
            adj[u].push_back(v);
        }

        void topologicalSort()
        {
            //calculate indegree
            vector<int> indegree(v,0);
            for(int i=0;i<v;i++)
            {
                for(int j=0;j<adj[i].size();j++)
                {
                    indegree[adj[i][j]]++;
                }
            }
            //create queue and add all vertices with indegree 0 to the queue
            queue<int> q;
            for(int i=0;i<v;i++)
            {
                if(indegree[i]==0)
                {
                    q.push(i);
                }
            }
            //create a vector to store the topological order
            vector<int> topologicalOrder;
            while(!q.empty())
            {
                int u=q.front();
                q.pop();
                topologicalOrder.push_back(u); //add u to the topological order
                for(int i=0;i<adj[u].size();i++)
                {
                    indegree[adj[u][i]]--; //reducing indegree of all vertices adjacent to u
                    if(indegree[adj[u][i]]==0) //if indegree of adjacent vertex becomes 0, add it to the queue
                    {
                        q.push(adj[u][i]);
                    }
                }
            }
            //check if the graph is cyclic or not
            if(topologicalOrder.size()!=v)
            {
                cout<<"Graph has cycles"<<endl; //as all the vertices haven't been added to the topological order, there must be a cycle
                return;
            }
            //print the topological order
            for(int i=0;i<topologicalOrder.size();i++)
            {
                cout<<topologicalOrder[i]<<" ";
            }
            cout<<endl;
        }
};
int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    directedGraph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.topologicalSort();
 
    directedGraph g2(5);
    g2.addEdge(1, 0);
    g2.addEdge(0, 2);
    g2.addEdge(2, 1);
    g2.addEdge(0, 3);
    g2.addEdge(3, 4);
    g2.addEdge(4, 0);
    g2.topologicalSort();
 
    directedGraph g3(5);
    g3.addEdge(1, 0);
    g3.addEdge(0, 2);
    g3.addEdge(2, 1);
    g3.addEdge(0, 3);
    g3.addEdge(3, 4);
    g3.addEdge(1, 3);
    g3.topologicalSort();

    directedGraph g4(3);
    g4.addEdge(0, 1);
    g4.addEdge(1, 2);
    g4.addEdge(2, 0);
    g4.topologicalSort();

    directedGraph g5(4);
    g5.addEdge(0, 1);
    g5.addEdge(1, 2);
    g5.addEdge(2, 3);
    g5.topologicalSort();

    return 0;
}