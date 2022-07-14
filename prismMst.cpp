/*
This is prism algorithms in which you have two sets one set include the node which are taken in mst other which are
not.
you take key[] to check minimun weighted edge between all unvisited edges.
the parent [] sort the parent of particular index.
the mst store the included node in mst

Algorithm is:
take key[] with all value INT_MAX and mstSet[] as false.
start with first index .
find the minimun weighted edge index from key if it is not included in mstSet and take that index as node
and iterate over all adjacent node to find next minimum. if you find minimun update parent[] and key[].
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N = 5;
    vector<pair<int, int>> adj[N];
    adj[0].push_back({1, 2});
    adj[0].push_back({3, 6});
    adj[1].push_back({0, 2});
    adj[1].push_back({2, 3});
    adj[1].push_back({3, 8});
    adj[1].push_back({4, 5});
    adj[2].push_back({1, 3});
    adj[2].push_back({4, 7});
    adj[3].push_back({0, 6});
    adj[3].push_back({1, 8});
    adj[4].push_back({1, 5});
    adj[4].push_back({2, 7});

    int key[N];
    int parent[N];
    bool mstSet[N];

    for (int i = 0; i < N; i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    key[0] = 0;
    parent[0] = -1;
    pq.push({0, 0});
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
      
        mstSet[u] = true;

        for (auto it : adj[u])
        { 
            int v = it.first;
            int wt = it.second;
            if (mstSet[v] == false && wt < key[v])
            {
                parent[v] = u;
                key[v] = wt;
                pq.push({key[v], v});
            }
        }
    }
      for (int i = 1; i < N; i++)
        cout << parent[i] << " - " << i << " \n";
        return 0;
}