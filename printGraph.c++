#include"bits_stdcpp.h"
using namespace std;
//for undirected graph
void addEdge(vector<int>graph[],int u,int v)
{
graph[u].push_back(v);
graph[v].push_back(u);
}
void printGraph(vector<int>graph[],int V){
    cout<<"Graph is ...."<<endl;
    for(int i=0;i<V;i++)
    {
        cout<<"Edge from "<<i<<":";
        for(auto j:graph[i])
        {
            cout<<"-> "<<j<<ends;
        }
        cout<<endl;
    }
}

int main(){
    int V=4;
    vector<int>graph[V];
    addEdge(graph,0,1);
    addEdge(graph,0,3);
    addEdge(graph,1,2);
    addEdge(graph,2,3);
    printGraph(graph,V);
return 0;
}