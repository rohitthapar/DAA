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
        void DFSrec(int s, vector<bool> &visited, stack<int>&st)
        {
            visited[s]=true;
            //recur for all the vertices adjacent to this vertex
            for(int i=0;i<adj[s].size();i++)
            {
                if(visited[adj[s][i]]==false)
                {
                    DFSrec(adj[s][i],visited,st);
                }
            }
            st.push(s);
        }
        void DFStopologicalSort()
        {
            vector<bool> visited(v,false);
            stack<int> st;

            for(int i=0;i<v;i++)
            {
                if(visited[i]==false)
                {
                    DFSrec(i,visited,st);
                }
            }

            if(st.size()!=v)
            {
                cout<<"Graph has cycle"<<endl;
                return;
            }
            while(!st.empty())
            {
                cout<<st.top()<<" ";
                st.pop();
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
    g1.DFStopologicalSort();
 
    directedGraph g2(5);
    g2.addEdge(1, 0);
    g2.addEdge(0, 2);
    g2.addEdge(2, 1);
    g2.addEdge(0, 3);
    g2.addEdge(3, 4);
    g2.addEdge(4, 0);
    g2.DFStopologicalSort();
 
    directedGraph g3(5);
    g3.addEdge(1, 0);
    g3.addEdge(0, 2);
    g3.addEdge(2, 1); 
    g3.addEdge(0, 3);
    g3.addEdge(3, 4);
    g3.addEdge(1, 3);
    g3.DFStopologicalSort();

    directedGraph g4(3);
    g4.addEdge(0, 1);
    g4.addEdge(1, 2);
    g4.addEdge(2, 0);
    g4.DFStopologicalSort();
    
    return 0;
}