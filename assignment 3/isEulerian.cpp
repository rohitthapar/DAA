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

        void DFS(int s, vector<bool>&visited)
        {
            //vector<bool> visited(v,false);
            stack<int> st;
            st.push(s);
            visited[s]=true;
            while(!st.empty())
            {
                int u=st.top();
                st.pop();
                //cout<<u<<" ";
                for(int i=adj[u].size()-1;i>=0;i--)
                {
                    if(!visited[adj[u][i]])
                    {
                        st.push(adj[u][i]);
                        visited[adj[u][i]]=true;
                    }
                }
            }
        }
        bool isConnected()
        {
            vector<bool> visited(v,false);
            int i;

            //find a vertex with a non zero degree
            for (i = 0; i < v; i++)
            {
                if (adj[i].size() != 0)
                     break;
            }
            if (i == v) //if there are no edges, return true
                return true;


            DFS(i,visited);
            for(int i=0;i<v;i++)
            {
                if(!visited[i] && adj[i].size()!=0) //this means that there are vertices with non zero degree which haven't been traversed
                    return false;
            }
            return true;
        }
        int isEulerian()
        {
            if (isConnected() == false)
                return 0;
 
            // Count vertices with odd degree
            int odd = 0;
            for (int i = 0; i < v; i++)
                if (adj[i].size() & 1)
                    odd++;
        
            
            if (odd > 2)
                return 0;
        
            
            return (odd)? 1 : 2;
        }
};
void test(undirectedGraph &g)
{
    int res = g.isEulerian();
    if (res == 0)
        cout << "graph is not Eulerian\n";
    else if (res == 1)
        cout << "graph has a Euler path\n";
    else
        cout << "graph has a Euler cycle\n";
}
int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    undirectedGraph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    test(g1);
 
    undirectedGraph g2(5);
    g2.addEdge(1, 0);
    g2.addEdge(0, 2);
    g2.addEdge(2, 1);
    g2.addEdge(0, 3);
    g2.addEdge(3, 4);
    g2.addEdge(4, 0);
    test(g2);
 
    undirectedGraph g3(5);
    g3.addEdge(1, 0);
    g3.addEdge(0, 2);
    g3.addEdge(2, 1);
    g3.addEdge(0, 3);
    g3.addEdge(3, 4);
    g3.addEdge(1, 3);
    test(g3);

    undirectedGraph g4(3);
    g4.addEdge(0, 1);
    g4.addEdge(1, 2);
    g4.addEdge(2, 0);
    test(g4);
    return 0;
}