#include <iostream>
#include <queue>
using namespace std;

// quero saber o menor caminho entao eu uso BFS;
int R, C, L, Qtd, lin, col;
bool M[1001][1001];
pair<int, int> XY[4]{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void limpa()
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            M[i][j] = 0;
        }
    }
}

bool isValid(pair<int, int> V)
{
    if (V.first >= 0 && V.first < R && V.second >= 0 && V.second < C)
        return true;

    return false;
}

int BFS(pair<int, int> Robot, pair<int, int> fim)
{
    int dist[R][C];
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            dist[i][j] = -1;
        }
    }
    dist[Robot.first][Robot.second]=0;
    queue<pair<int, int>> Q;
    Q.push(Robot);
    while (Q.size())
    {
        pair<int, int> u = Q.front();
        Q.pop();
        if (u == fim)
        {
            return dist[u.first][u.second];
        }
        for (int i = 0; i < 4; i++)
        {
            pair<int, int> V = {u.first + XY[i].first, u.second + XY[i].second};

            if (isValid(V) && M[V.first][V.second]!=1 && dist[V.first][V.second] == -1)
            {
                Q.push(V);
                dist[V.first][V.second] = dist[u.first][u.second]+1;
            }
        }
    }
}

int main()
{
    while (cin >> R >> C && R && C)
    {
        limpa();
        pair<int, int> ini, fim;
        int X, Y;
        cin >> L;
        for (int i = 0; i < L; i++)
        {
            cin >> lin >> Qtd;
            for (int j = 0; j < Qtd; j++)
            {
                cin >> col;
                M[lin][col] = 1;
            }
        }
        cin >> X >> Y;
        ini.first = X;
        ini.second = Y;
        cin >> X >> Y;
        fim.first = X;
        fim.second = Y;
        cout << BFS(ini, fim) << endl;
    }
}