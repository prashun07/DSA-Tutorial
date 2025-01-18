/*
Think about the reaching time on every node in first attempt and in minimum time.
we will do dfs(i) on a node and mark the time taken to reach there, at first we mark both dist[i] and low[i] with same value.
then we will go to the all adjacent node of the i, suppose adjacent is node 'child', now if
child node is parent we will continue the loop ,
if child is not visited the will call dfs on c,->
   ->-> when the dfs call is over here we will take minimun time taken to reach ith node from node child.
   ---> check the condition for the bridge, if(low[child]>high[i]) then it is bridge.
   ----see,'child' is child node or adjacent node of i, so if edge between 'child' node and 'i' node is bridge
    then there is only one path to reach 'child' from 'i' node,
   so time taken to reach 'child' from source should be always greater than time taken to reach 'i' from source.
   if you reach 'child' node from source in less time than the parent node ,it means node has multiple path to reach.
   if any edge is part of loop then it cannot be a bridge.

if child is visited then take the minimun time to reach that ith node from child node low[i]=min(low[i],low[child])
*/
#include "bits_stdcpp.h"
using namespace std;
void dfs(int i, int parent, int &timer, vector<bool> &visited, vector<int> &low, vector<int> &high, vector<int> adj[])
{
    visited[i] = true;
    low[i] = high[i] = timer++;
    for (auto child : adj[i])
    {
        if (parent == child)
            continue;
        if (!visited[child])
        {
            dfs(child, i, timer, visited, low, high, adj);
            low[i] = min(low[i], low[child]);
            if (low[child] > high[i])
                cout << "{" << i << "<---->" << child << "}," << endl;
        }
        else
            low[i] = min(low[i], low[child]);
    }
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
    for (int i = 0; i < n; i++)
    { // to check all components in the graph
        if (!visited[i])
            dfs(i, -1, timer, visited, low, dist, adj);
    }
}