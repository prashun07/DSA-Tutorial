// shortest path in undirected graph using bfs
#include "bits_stdcpp.h"
using namespace std;
void add_edge(vector<int> adj[], int src, int dest)
{
    adj[src].push_back(dest);
    adj[dest].push_back(src);
}
void bfs(vector<int> adj[], vector<int> &dist, int src)
{
    dist[src] = 0;
    queue<int> q;
    q.push(src);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto it : adj[node])
        {
            if (dist[node] + 1 < dist[it])
            {
                dist[it] = dist[node] + 1;
                q.push(it);
            }
        }
    }
    for (int i = 0; i < dist.size(); i++)
    {
        cout <<"Path for "<<i<<"-->"<<dist[i] << " , ";
    }
}
int main()
{
    int V = 8;
    // int V;
    // cin>>V;
    vector<int> adj[V];
    vector<int>dist(V);
    for(int i=0;i<V;i++)
    {
        dist[i]=INT_MAX;
    }
    // adj[1].push_back(0);
    add_edge(adj, 0, 1);
    add_edge(adj, 0, 3);
    add_edge(adj, 1, 2);
    add_edge(adj, 3, 4);
    add_edge(adj, 3, 7);
    add_edge(adj, 4, 5);
    add_edge(adj, 4, 6);
    add_edge(adj, 4, 7);
    add_edge(adj, 5, 6);
    add_edge(adj, 6, 7);
    bfs(adj,dist,0);
    return 0;
}