#include <iostream>
#include <map>
#include <set>
using namespace std;

map<char, set<char> > adjlist;
map<char, bool> visited;

void DFS(char u)
{
    visited[u] = true;
    for (auto it : adjlist[u])
    {
        if (!visited[it])
        {
            DFS(it);
        }
    }
}

int main()
{
    int T;
    cin >> T;
    for (int i =1 ; i<=T ;i++)
    {
        int cont = 0;
        char V;
        cin >> V;
        string edge;
        cin.ignore();
        getline(cin, edge);
        while (edge.size())
        {
            adjlist[edge[0]].insert(edge[1]);
            adjlist[edge[1]].insert(edge[0]);
            getline(cin,edge); 

        }
        for(char j = 'A'; j<=V; j++)
        {
            if(!visited[j])
            {
                DFS(j);
                cont++;
            }
        }
        cout<<cont<<endl;
        if(i<T)
        {
            cout<<endl;
        }
        adjlist.clear();
        visited.clear();
    }
}