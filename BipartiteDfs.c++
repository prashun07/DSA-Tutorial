#include <bits/stdc++.h>
using namespace std;
// Time Complexity: O(V + E), since in its whole, it is a DFS implementation, V – vertices; E – edges;
//
// Space Complexity: O(V), because, apart from the graph, we maintain a color array.
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
bool dfs(vector<int> adj[], vector<int> &visited, int src)
{
    cout << "{ " << src << " , " << visited[src] << " }" << endl;

    for (int i = 0; i < adj[src].size(); i++)
    {
        if (visited[adj[src][i]] == -1)
        {
            visited[adj[src][i]] = 1 - visited[src];
            dfs(adj, visited, adj[src][i]);
        }
        else if (visited[adj[src][i]] == visited[src])
            return false;
    }
    return true;
}
int main()
{
    int V = 6;
    vector<int> visited(V);
    // Visited array is here used to track the color of adjacent nodes, fill the visited node with -1
    for (int i = 0; i < V; i++)
    {
        visited[i] = -1;
    }
    vector<int> adj[V + 1];
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 4);
    addEdge(adj, 1, 5);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 3, 5);

    for (int i = 0; i < V; i++)
    {
        if (visited[i] == -1)
        {
            visited[0] = 0;//Important to mark one node earlier.
            if (dfs(adj, visited, i))
            {
                cout << "Bipartite Graph" << endl;
            }
            else
                cout << "Not Bipartite Graph" << endl;
        }
    }
    return 0;
}
