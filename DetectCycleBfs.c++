#include"bits_stdcpp.h"
using namespace std;
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
bool cycleBfs(vector<int>adj[],vector<int>&visited,int src)
{ queue<pair<int,int>> q;
    q.push({src,-1});
    visited[src] = true;
    while (!q.empty())
    {
        int node = q.front().first;
        int parent=q.front().second;
        q.pop();
        cout << node << " ,";
        for (int i = 0; i < adj[node].size(); i++)
        {
            if (!visited[adj[node][i]])
            {
                visited[adj[node][i]] = true;
                q.push({adj[node][i],node});
            }
            else if(parent!=adj[node][i])
            return true;
        }
    }
    return false;
}
bool isCycle(vector<int>adj[],int V){
    vector<bool>visited(V+1);
    for(int i=0;i<=V;i++)
    {
        visited[i]=false;
    }
    for(int i=0;i<V+1;i++)
    {if(!visited[i]){
        if(cycleBfs)
      return true;
    }
    }
    return false;
}
int main()
{
//undirected graph
    int V = 5;
    vector<int> adj[V + 1];
       addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,2,3);
    addEdge(adj,1,3);
    addEdge(adj,2,4);
    cout<<"is there cycle in graph? "<<endl;
    if(isCycle(adj,V))
    cout<<"Yes!!"<<endl;
    else
    cout<<"NO!!"<<endl;
    return 0;
}
//Time complexity : O{N+E}
//Space Complexity:O(N+E)+O(N)+O(N);