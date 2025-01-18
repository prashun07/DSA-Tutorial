/*
Articulation point is a node in graph, which if removed from the graph then it disconnect  the graph,means if you 
remove a node from graph and it form two different sets then that node is called articulation point.

this implementation is same expect take modification in condition to check articulation point.
 condition is:low[child] >= high[i] && parent!=-1
 we use array hash to store the articulation point, to avoid repeated printing of node.

*/
#include "bits_stdcpp.h"
using namespace std;
void dfs(int i, int parent, int &timer, vector<bool> &visited, vector<int> &low, vector<int> &high, 
vector<int> adj[],vector<int>&isArticulation)
{
    visited[i] = true;
    low[i] = high[i] = timer++;
    int countofChild=0;
    for (auto child : adj[i])
    {
        if (parent == child)
            continue;
        if (!visited[child])
        {
            dfs(child, i, timer, visited, low, high, adj,isArticulation);
            low[i] = min(low[i], low[child]);
            countofChild++;
            if (low[child] >= high[i] && parent!=-1)
                 isArticulation[i]=1;
                // cout << "{" << i << "<---->" << child << "}," << endl;
        }
        else
            low[i] = min(low[i], low[child]);
    }
    if(parent==-1 && countofChild>1)
     isArticulation[i]=1;
}

int main()
{
    int n = 5;
    vector<int> adj[n];
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[0].push_back(3);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[2].push_back(0);
    adj[3].push_back(0);
    adj[3].push_back(4);
    adj[4].push_back(3);

    vector<bool> visited(n + 1, false); // check visited node
    int timer = 0;                      // for adding timer to node
    vector<int> low(n, -1);             // Lowest time to reach the node among all the path
    vector<int> dist(n, -1);            // distance to reach there in first attempt
    vector<int>isArticulation(n,-1);
    for (int i = 0; i < n; i++)
    { // to check all components in the graph
        if (!visited[i])
            dfs(i, -1, timer, visited, low, dist, adj,isArticulation);
    }
    for(int i=0;i<n;i++)
    {
        if(isArticulation[i]==1)
        cout<<i<<endl;
    }
}