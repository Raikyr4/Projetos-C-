#include <iostream>
#include <vector>
#include <queue>
#define inf 100000000
using namespace std;

int M, N;
int Mat[1000][1000];
pair<int, int> XY[4]{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
 int dist[1000][1000];

bool isValid(int X, int Y)
{
    if (X >= 0 && X < M && Y >= 0 && Y < N)
        return true;

    return false;
}

int Dijkstra()
{ 
   
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            dist[i][j] = inf;
        }
    }
    dist[0][0] = Mat[0][0];
   
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> Q;

    Q.push({Mat[0][0], {0, 0}});

    while (Q.size())
    {
        pair<int, pair<int, int>> U = Q.top();
        Q.pop();
        for (int i = 0; i < 4; i++)
        {
            int x = U.second.first + XY[i].first;
            int y = U.second.second + XY[i].second;
            if (isValid(x, y) && dist[U.second.first][U.second.second] + Mat[x][y] < dist[x][y])
            {
                dist[x][y] = dist[U.second.first][U.second.second] + Mat[x][y];
                Q.push({dist[x][y], {x, y}});
            }
        }  
    }
  
    return dist[M - 1][N - 1];
}

int main()
{
    int X;
    cin >> X;
    for (int i = 0; i < X; i++)
    {
        cin >> M >> N;
        for (int a = 0; a < M; a++)
        {
            for (int j = 0; j < N; j++)
            {
                cin >> Mat[a][j];
            }
        }
        cout << Dijkstra() << endl;
    }
}