#include <iostream>
#include <vector>
using namespace std;

bool visited[101] = {false};
vector<int> adjlist[101];

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
    int V, L;
    cin >> V >> L;
    int cont = 0;
    int X, Y;
    for (int i = 0; i < L; i++)
    {
        cin >> X >> Y;
        adjlist[X].push_back(Y);
        adjlist[Y].push_back(X);
    }
    for (int i = 1; i <= V; i++)
    {
        if (!visited[i])
        {
            DFS(i);
            cont++;
        }
    }
   // cout << cont << endl;
    if (cont > 1)
    {
        cout << "INCOMPLETO" << endl;
    }
    else
    {
        cout << "COMPLETO" << endl;
    }
}