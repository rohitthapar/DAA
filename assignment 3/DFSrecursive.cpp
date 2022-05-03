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


class undirectedGraph
{
    int v;
    vector<vector<int>> adj;
    
    public:
        undirectedGraph (int v)
        {
            this->v=v;
            adj.resize(v);
        }
        
        void addEdge(int u, int v)
        {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        void DFSrec(int s, vector<bool>&visited)
        {
            visited[s]=true;
            cout<<s<<" ";
            for(int i=0;i<adj[s].size();i++)
            {
                if(!visited[adj[s][i]])
                {
                    DFSrec(adj[s][i],visited);
                }
            }
        }
        void DFS(int s)
        {
            vector<bool> visited(v,false);
            DFSrec(s,visited);
        }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int v;
    cin>>v; //number of vertices
    undirectedGraph g(v);
    int e;
    cin>>e; //number of edges
    for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v);
    }
    int s; //source vertex
    cin>>s;
    g.DFS(s);
    return 0;
}