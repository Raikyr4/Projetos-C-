#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

int V, E;
map<char,bool> visited;
map<char,set<char>> adjlist;

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
    int N, round = 1, components = 0;
    cin >> N;
    char I, F;
    for (int i = 0; i < N; i++)
    {
        cin >> V >> E;

        for (int j = 0; j < E; j++)
        {
            cin >> I >> F;
            adjlist[I].insert(F);
            adjlist[F].insert(I);
        }
        for(char i='a' ; i<=V ;i++)
        {
            if(!visited[i])
            {
                DFS(i);
                components++;
            }
        }

        map<char,set<char>> :: iterator it;
        set<char> ::iterator it2;
        cout<<"Case #"<<round<<": "<<endl;

        for(int i=0; i < V ; i++)
        {
            for(it=adjlist.begin(); it != adjlist.end(); it++)
            {
                cout<<it->first<<',';
                for(it2=it->second.begin();it2!=it->second.end();it2++)
                {
                    cout<<*it2<<',';
                }
            }
            cout<<endl;
        }
        cout << components <<" connected components"<< endl<<endl;

        round++;
        components = 0;
        for(int i=0;i<26;i++)
        {
            visited[i]=0;
        }
        adjlist.clear();
        visited.clear();
      
    }
}