#include <iostream>
#include <vector>
#include <queue>
using namespace std;

pair<int, int> XY[8]{{1, 2}, {1, -2}, {-1,2}, {-1, -2},{2,1},{2,-1},{-2,1},{-2,-1}};

bool isValid(pair<int, int> V)
{
    if (V.first >= 1 && V.first < 9 && V.second >= 1 && V.second < 9)
        return true;

    return false;
}

int BFS(pair<int, int> ini, pair<int, int> fim)
{
    int dist[10][10];
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            dist[i][j] = -1;
        }
    }

    dist[ini.first][ini.second] = 0;
    queue<pair<int, int>> Q;
    Q.push(ini);
    while (Q.size())
    {
        pair<int, int> u = Q.front();
        Q.pop();
        if (u == fim)
        {
            return dist[u.first][u.second];
        }
        for (int i = 0; i < 8; i++)
        {
            pair<int, int> V = {u.first + XY[i].first, u.second + XY[i].second};

            if (isValid(V))
            {
                Q.push(V);
                dist[V.first][V.second] = dist[u.first][u.second] + 1;
            }
        }
    }
}

int main()
{

    string A, B;
    while (cin >> A >> B )
    {
       
        pair<int, int> ini, fim;
        char alf[9] = {' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};

        for (int i = 1; i < 9; i++)
        {
            if (A[0] == alf[i])
            {
                ini.first = i;
                ini.second = A[1] - '0';
            }
            if (B[0] == alf[i])
            {
                fim.first = i;
                fim.second = B[1] - '0';
            }
        }

        cout << "To get from " << A << " to " << B << " takes " << BFS(ini, fim) << " knight moves." << endl;
    }
}