//undirected graph
// Time Complexity: O(N)

// Space Complexity: O(N)


#include"bits_stdcpp.h"
using namespace std;
// void addEdge(vector<int> adj[], int u, int v)
// {
//     adj[u].push_back(v);
//     adj[v].push_back(u);
// }
bool dfs(vector<int>adj[],vector<bool>&visited,int src,int parent)
{
  
     visited[src]=true;
    //  cout<<src<<" ,";

     for(int i=0;i<adj[src].size();i++)
     { if(visited[adj[src][i]]==false)
      dfs(adj,visited,adj[src][i],src);
      else if(parent!=adj[src][i])
      return true;
     }
return false;
}

bool isCycle(vector<int>adj[],int V)
{ vector<bool>visited(V+1);
for(int i=0;i<=V;i++)
{
    visited[i]=false;
}
for(int i=1;i<V+1;i++)
{
     if(!visited[i])
     {
        if(dfs(adj,visited,i,-1))
         return true;
     }

}
return false;
}
int main()
{
    int V = 5;
  int E = 5;
  vector < int > adj[V];

  adj[0].push_back(1);
  adj[1].push_back(0);

  adj[1].push_back(2);
  adj[2].push_back(1);

  adj[1].push_back(4);
  adj[4].push_back(1);

  adj[4].push_back(3);
  adj[3].push_back(4);

  adj[2].push_back(3);
  adj[3].push_back(2);
cout<<"Is cycle present in graph?"<<endl;
if(isCycle(adj,V))
 cout<<"Yes!"<<endl;
 else
 cout<<"No!!"<<endl;
 return 0;
}