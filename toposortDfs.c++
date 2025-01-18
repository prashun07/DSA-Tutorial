// Time Complexity: O(N+E) 
// Space Complexity: O(N) + O(N)  
// Auxiliary Space Complexity:  O(N)    Recursion call of DFS
#include "bits_stdcpp.h"
using namespace std;
void toposort(vector<int> adj[], vector<int> &visited, stack<int> &st, int src)
{
    visited[src] = 1;
    for (auto i:adj[src])
    {
        if (!visited[i])
        {
            toposort(adj, visited, st, i);
        }
    }
    st.push(src);
}

int main()
{
    stack<int> st;
    int V = 6;
    vector<int> visited(V + 1);
    for (int i = 0; i <= V; i++)
    {
        visited[i] = 0;
    }
    vector<int> adj[5 + 1];
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
            toposort(adj, visited, st, i);
    }
    while (!st.empty())
    {
        int ans = st.top();
        st.pop();
        cout << ans << " , ";
    }

    return 0;
}