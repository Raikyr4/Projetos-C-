#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> adjlist[11];// usamos o first para o cara adjacente e o second para guardar o peso



int Dijkstra(int ini, int fim)
{
    int dist[10001];
    for (int i = 0; i < 10001; i++)
    {
        dist[i] = 1000000;
    }
    dist[ini] = 0;
    priority_queue< pair<int, int> , vector <pair<int,int>> , greater<pair<int,int>>  > Q; // fila q ordena e remove sempre o maior valor  , porem tem o custo computacional grande
    //aki na fila usamos o first para o peso e o second para o adjacente 
    //minha fila vai armazenar o peso de cada caminho para achar o menor 

    Q.push({0,ini});
    while (Q.size())
    {
        pair<int,int> u = Q.top();
        Q.pop();
        for(int i=0; i<adjlist[u.second].size();i++)
        {
            pair<int,int> V =adjlist[u.second][i];
            if(dist[u.second]+V.second< dist[V.first])
            {
                dist[V.first]=dist[u.second]+V.second;
                Q.push({dist[V.first],V.first});
            }
        }
    }
    return dist[fim];
}

int main()
{
    int N, E;
    int V, Vv, P;
    cin >> N>>E;
    for (int i = 0; i < E; i++)
    {
        cin >> V >> Vv >> P;
        adjlist[V].push_back({Vv, P});
        adjlist[Vv].push_back({V, P});
    }
    cout<<Dijkstra(1,3)<<endl;
}