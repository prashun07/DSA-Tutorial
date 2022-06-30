#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void dfs(vector<int>adj[],vector<bool>&visited,int src)
{
  
     visited[src]=true;
     cout<<src<<" ,";

     for(int i=0;i<adj[src].size();i++)
     { if(visited[adj[src][i]]==false)
      dfs(adj,visited,adj[src][i]);
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
    for(int i=1;i<V+1;i++)
   { if(visited[i]==false)
    dfs(adj,visited,i);
   }

}