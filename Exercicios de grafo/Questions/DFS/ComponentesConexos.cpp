#include <iostream>
#include <vector>
using namespace std;

int V, E;
bool visited[26] = {0};
vector<int> adjlist[26];
char alf[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

bool DFS(int u) // o inicio é o u e o X é onde eu quero chegar
{
    visited[u] = true;

    for (int i = 0; i < adjlist[u].size(); i++)
    {
        int V = adjlist[u][i];
        if (!visited[V])
        {
            if (DFS(V))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int N, round = 1, components = 0;
    cin >> N;
    char I, F;
    for (int i = 0; i < N; i++)
    {
        cin >> V >> E;

        for (int j = 0; j < E; j++)
        {
            cin >> I >> F;
            int auxI, auxF;
            for (int h = 0; h < 26; h++)
            {
                if (I == alf[h])
                    auxI = h;
                if (F == alf[h])
                    auxF = h;
            }
            adjlist[auxI].push_back(auxF);
            adjlist[auxF].push_back(auxI);
           // DFS(auxI);
        }
        for(int i=0 ; i<V ;i++)
        {
            if(!visited[i])
            {
                DFS(i);
                components++;
            }
        }
        cout<<"Case #"<<round<<": ";
        cout << components << endl;
        round++;
        components = 0;
        for(int i=0;i<26;i++)
        {
            visited[i]=0;
        }
       /*for (int i = 0; i < V; i++)
        {   
            cout << visited[i] << " ";
        }*/ 
    }
}