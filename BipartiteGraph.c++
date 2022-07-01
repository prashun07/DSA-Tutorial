#include <bits/stdc++.h>
using namespace std;
//A graph with two adjacents nodes having different coloring is called bipartite graph
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool bfs(vector<int> adj[], vector<int>&visited,int src)
{
   
    queue<int> q;
    q.push(src);
    visited[src] = 0; //color the first node with 0
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout <<"{ "<< node << " , "<<visited[node]<<" }"<<endl;
        for (int i = 0; i < adj[node].size(); i++)
        {
            if (visited[adj[node][i]]==-1)
            {
                visited[adj[node][i]] = 1-visited[node]; //if node is not colored then color it with opp. of parent
                q.push(adj[node][i]);
            }
            else if(visited[adj[node][i]]==visited[node])
            return false; //if node is visited earlier and have same color as parent that means it is not bipartite graph
            
        }
    }
    return true;
}

int main()
{
    int V = 6;
    vector<int>visited(V+1);
    //Visited array is here used to track the color of adjacent nodes, fill the visited node with -1
    for(int i=0;i<=V;i++)
    {
        visited[i]=-1;
    }
    vector<int> adj[V + 1];
   addEdge(adj,0,1);
    addEdge(adj,1,2);
    addEdge(adj,1,4);
    addEdge(adj,1,5);
    addEdge(adj,2,3);
    addEdge(adj,3,4);
    addEdge(adj,3,5);
    //This piece of code check every unconnected components in a graph, when ever we found an unvisited node we apply bfs there.
for(int i=0;i<V;i++)
{ if(visited[i]==-1)
   { if(bfs(adj,visited,i))
    {
        cout<<"Bipartite Graph"<<endl;
    }
    else
    cout<<"Not Bipartite Graph"<<endl;
   }
}
  
    return 0;
}
//Time Complexity : O(N+E)
//Space Complexity : O(N+E) + O(N) + O(N) 