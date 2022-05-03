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

        void BFS(int s)
        {
            vector<bool> visited(v,false);
            queue<int> q;
            q.push(s);
            visited[s]=true;
            while(!q.empty())
            {
                int u=q.front();
                q.pop();
                cout<<u<<" ";
                for(int i=0;i<adj[u].size();i++)
                {
                    if(!visited[adj[u][i]])
                    {
                        q.push(adj[u][i]);
                        visited[adj[u][i]]=true;
                    }
                }
            }
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
    g.BFS(s);
    return 0;
}