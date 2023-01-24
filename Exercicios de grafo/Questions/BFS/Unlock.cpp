#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// tenho q montar o grafo junto com o problema , ele nao me da o grafo pronto
long L, U, R;
vector<int> buttons;

int BFS(int ini, int fim)
{
    vector<int> dist(10001, -1); // como se fosse o vetor de visitados
    queue<int> Q;
    dist[ini] = 0;
    Q.push(ini);
    while (Q.size())
    {
        int u = Q.front(); // verticie atual
        Q.pop();
        if (u == fim)
        {
            return dist[fim];
        }
        for (int i = 0; i < buttons.size(); i++)
        {
            int V = u + buttons[i];
            V %= 10000;
            if (dist[V] == -1)// se nao foi visitado  / U é o o no inicial e V é o adjacente
            {
                dist[V] = dist[u] + 1;
                Q.push(V);
            }
        }
    }
    return -1;
}

int main()
{
    int round=1;
    while (cin >> L >> U >> R && L || U || R)
    {
        for (int i = 0; i < R; i++)
        {
            int A;
            cin>>A;
            buttons.push_back(A);
        }
        int X=BFS(L,U);
        if(X==-1)
        {
            cout<<"Case "<<round<<": "<<"Permanently Locked"<<endl;
        }
        else
        {
             cout<<"Case "<<round<<": "<<X<<endl;
        }
        round++;
        buttons.clear();
    }
}