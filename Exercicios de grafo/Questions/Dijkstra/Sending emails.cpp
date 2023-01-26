#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> adjlist[20010];

int Dijkstra(int ini, int fim)
{
    int dist[20010];
    for (int i = 0; i < 20010; i++)
    {
        dist[i] = 1000000;
    }
    dist[ini] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;

    Q.push({0, ini});
    while (Q.size())
    {
        pair<int, int> u = Q.top();
        Q.pop();
        for (int i = 0; i < adjlist[u.second].size(); i++)
        {
            pair<int, int> V = adjlist[u.second][i];
            if (dist[u.second] + V.second < dist[V.first])
            {
                dist[V.first] = dist[u.second] + V.second;
                Q.push({dist[V.first], V.first});
            }
        }
    }
    return dist[fim];
}

int main()
{
    int N, round = 1, n, M, S, T;
    cin >> N;
    while (N--)
    {
        cin >> n >> M >> S >> T;
        for (int i = 0; i < M; i++)
        {
            int a, b, p;
            cin >> a >> b >> p;
            adjlist[a].push_back({b, p});
            adjlist[b].push_back({a, p});
        }

        int X = Dijkstra(S, T);
        if (X != 1000000)
        {
            cout << "Case #" << round << ": " << X << endl;
        }
        else
        {
            cout << "Case #" << round << ": unreachable" << endl;
        }
        round++;
        for(int i=0;i <n;i++){
            adjlist[i].clear();
        }
    }
}