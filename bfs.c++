#include "bits_stdcpp.h"
using namespace std;
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void printadj(vector<int> adj[], int V)
{
    cout << "adj is ...." << endl;
    for (int i = 0; i < V; i++)
    {
        cout << "Edge from " << i << ":";
        for (auto j : adj[i])
        {
            cout << "-> " << j << ends;
        }
        cout << endl;
    }
}
void bfs(vector<int> adj[], vector<bool>&visited,int src)
{
    // bool visited[V + 1];
    // for (int i = 0; i <= V; i++)
    // {
    //     visited[i] = false;
    // }
    queue<int> q;
    q.push(src);
    visited[src] = true;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ,";
        for (int i = 0; i < adj[node].size(); i++)
        {
            if (!visited[adj[node][i]])
            {
                visited[adj[node][i]] = true;
                q.push(adj[node][i]);
            }
        }
    }
}

int main()
{
    int V = 10;
    vector<bool>visited(V+1);
    for(int i=0;i<=V;i++)
    {
        visited[i]=false;
    }
    vector<int> adj[V + 1];
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 4);
    addEdge(adj, 2, 5);
    addEdge(adj, 3, 5);
    addEdge(adj, 4, 5);
    addEdge(adj, 4, 6);
    addEdge(adj, 5, 6);
    addEdge(adj,7,8);
    addEdge(adj,8,9);
    addEdge(adj,9,10);
    addEdge(adj,10,7);
    //This piece of code check every unconnected components in a graph, when ever we found an unvisited node we apply bfs there.
for(int i=1;i<=V;i++)
{ if(!visited[i])
  bfs(adj,visited,i);
}
  
    return 0;
}
//Time Complexity : O(N+E)
//Space Complexity : O(N+E) + O(N) + O(N) 