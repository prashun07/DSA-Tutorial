#include "bits_stdcpp.h"
using namespace std;
int fillCups(vector<int> &amount)
{
    priority_queue<pair<int, int>> pq;
    int n = amount.size();
    for (int i = 0; i <n; i++)
    {
        pq.push({amount[i],i});
    }
    int answer = 0;

    while (!pq.empty() && pq.size() > 1)
    {
        int first = pq.top().second;
        pq.pop();
        int second = pq.top().second;
        pq.pop();
        int amF =--amount[first];
        int amS =--amount[second];
        answer++;
        if (amF > 0)
            pq.push({amF,first});
        if (amS > 0)
            pq.push({amS,second});
    }

    for (int i = 0; i < n; i++)
    {
        if (amount[i] != 0)
            answer+=amount[i];
    }
    return answer;
}
int main()
{
    vector<int> amount;
    amount.push_back(1);
    amount.push_back(4);
    amount.push_back(2);
    fillCups(amount);
    // cout <<"Answer:" <<fillCups(amount)<<"----" << endl;
    return 0;
}