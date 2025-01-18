// Time Complexity: O(N+E)
// Space complexity: O(N)+O(N)
#include "bits_stdcpp.h"
using namespace std;
vector<int> toposort(vector<int> adj[], int V)
{
    vector<int> indegree(V);
    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++; //?? how indegree is calculated?
        }
    }
    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    vector<int> topo;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for (auto it : adj[node])
        {
            indegree[it]--; ///?
            if (indegree[it] == 0)
                q.push(it);
        }
    }
    return topo;
}
int main()
{
    vector<int> adj[6];
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[3].push_back(1);
    adj[2].push_back(3);

    vector<int>topoAnswer=toposort(adj, 6);
    for(int i=0;i<6;i++)
    {
        cout<<topoAnswer[i]<<" , ";
    }

    return 0;
}