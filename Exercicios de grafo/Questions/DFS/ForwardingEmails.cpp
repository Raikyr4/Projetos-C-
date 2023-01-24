#include <iostream>
#include <vector>
using namespace std;

bool visited[50000] = {0};
vector<int> adjlist[50000];

void DFS(int u)
{
    visited[u] = true;

    for (int i = 0; i < adjlist[u].size(); i++)
    {
        int d = adjlist[u][i];
        if (!visited[d])
        {
            DFS(d);
        }
    }
}

int main()
{
    int N, V, X, Y;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        int cont = 0;
        cin >> V;
        for (int j = 0; j < V; j++)
        {
            cin >> X >> Y;
            if()
            adjlist[X].push_back(Y);
            adjlist[Y].push_back(X);
        }
        for (int j = 1; j <=V; j++)
        {
            if (!visited[j])
            {
                DFS(j);
                cont++;
            }
        }
        cout<<"Case "<<i<<": "<<cont<<endl;
    }
}